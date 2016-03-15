#include "SourceFile.h"
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <assert.h>
#include "Platform.h"
#include "ImportDirectory.h"
#include "ErrorList.h"
#include "Options.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "IdentifyNode.h"
#include "MemberListNode.h"
#include "ClassNode.h"
#include "TypeNameNode.h"
#include "TemplateClassInstanceNode.h"
#include "TypeAliasNode.h"
#include "HeaderFileGenerator.h"
#include "SourceFileGenerator.h"
#include "MetaHeaderFileGenerator.h"
#include "MetaSourceFileGenerator.h"


SourceFile::~SourceFile()
{
	size_t count = m_embededCodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		delete m_embededCodes[i];
	}
}

void SourceFile::addEmbededCodeBlock(const char* str, int tokenNo)
{
	EmbededCode* embededCode = new EmbededCode;
	embededCode->m_code = str;
	embededCode->m_tokenNo = tokenNo;
	m_embededCodes.push_back(embededCode);
}

char SourceFile::outputEmbededCodes(FILE* file, int tokenNo)
{
	char lastChar = 0;
	for(; m_currentEmbededCode < m_embededCodes.size(); ++m_currentEmbededCode)
	{
		EmbededCode* embededCode = m_embededCodes[m_currentEmbededCode];
		if(embededCode->m_tokenNo <= tokenNo)
		{
			lastChar = embededCode->m_code.back();
			writeStringToFile(embededCode->m_code.c_str(), embededCode->m_code.length(), file);
		}
		else
		{
			break;
		}
	}
	return lastChar;
}


SourceFileManager::SourceFileManager()
{
	m_currentSourceFile = 0;
	m_mainSourceFile = 0;
	m_insertSourceFilePosition = 0;
	m_currentLineNo = 0;
}

void SourceFileManager::insertUnParsedSourceFile(const std::string& fileName)
{
	m_sourceFileNames.insert(fileName);
	assert(m_insertSourceFilePosition <= m_unParsedSourceFiles.size());
	SourceFile* sourceFile = new SourceFile;
	sourceFile->m_fileName = fileName;
	m_unParsedSourceFiles.insert(m_unParsedSourceFiles.begin() + m_insertSourceFilePosition, sourceFile);
	m_insertSourceFilePosition++;
	if(m_currentSourceFile)
	{
		m_currentSourceFile->m_importSourceFiles.push_back(sourceFile);
	}
}

int SourceFileManager::addSourceFile(const char* fileName)
{
	if(strlen(fileName) == 0)
	{
		return import_file_failed;
	}
	std::string fullName;
	if(isAbsolutePath(fileName))
	{
		normalizeFileName(fullName, fileName);
		if(m_sourceFileNames.find(fullName) != m_sourceFileNames.end())
		{
			return import_file_already_import;
		}
		if(fileExisting(fullName.c_str()))
		{
			insertUnParsedSourceFile(fullName);
			return import_file_succeeded;
		}
		else
		{
			return import_file_failed;
		}
	}
	else
	{
		ImportDirectories::DirectoryContainer::iterator it = g_importDirectories.m_directories.begin();
		ImportDirectories::DirectoryContainer::iterator end = g_importDirectories.m_directories.end();
		for(;it != end; ++it)
		{
			std::string str = *it + fileName;
			normalizeFileName(fullName, str.c_str());
			if(m_sourceFileNames.find(fullName) != m_sourceFileNames.end())
			{
				return import_file_already_import;
			}
			if(fileExisting(fullName.c_str()))
			{
				insertUnParsedSourceFile(fullName);
				return import_file_succeeded;
			}
		}
	}
	return import_file_failed;
}

SourceFile* SourceFileManager::popSourceFile()
{
	if(m_unParsedSourceFiles.empty())
	{
		return 0;
	}
	SourceFile* sourceFile = m_unParsedSourceFiles.front();
	m_unParsedSourceFiles.erase(m_unParsedSourceFiles.begin());
	m_insertSourceFilePosition = 0;
	return sourceFile;
}

void SourceFileManager::prepareParse(SourceFile* sourceFile, bool main)
{
	m_currentSourceFile = sourceFile;
	if(main)
	{
		assert(0 == m_mainSourceFile);
		m_mainSourceFile = m_currentSourceFile;
	}
}

void SourceFileManager::checkNameForRegister_(MemberNode* memberNode, const std::string& name, int nameCategories)
{
	char buf[512];
	if(nc_namespace & nameCategories)
	{
		auto it = m_namespaceInfos.find(name);
		if (m_namespaceInfos.end() != it)
		{
			sprintf_s(buf, "\'%s\' : already defined in %s(%d,%d)",
				memberNode->m_name->m_str.c_str(), it->second.front().m_sourceFile->m_fileName.c_str(),
				it->second.front().m_namespaceNode->m_name->m_lineNo, it->second.front().m_namespaceNode->m_name->m_columnNo);
			ErrorList_AddItem(m_currentSourceFile->m_fileName.c_str(), memberNode->m_name->m_lineNo,
				memberNode->m_name->m_columnNo, semantic_error_type_redefined, buf);
		}
	}
	if(nc_type & nameCategories)
	{
		auto it = m_typeInfos.find(name);
		if (m_typeInfos.end() != it)
		{
			char buf[512];
			sprintf_s(buf, "\'%s\' : already defined in %s(%d,%d)",
				memberNode->m_name->m_str.c_str(), it->second.m_sourceFile->m_fileName.c_str(),
				it->second.m_typeNode->m_name->m_lineNo, it->second.m_typeNode->m_name->m_columnNo);
			ErrorList_AddItem(m_currentSourceFile->m_fileName.c_str(), memberNode->m_name->m_lineNo,
				memberNode->m_name->m_columnNo, semantic_error_type_redefined, buf);
		}
	}
	//if(nc_class_template & nameCategories)
	//{
	//	auto it = m_classTemplateTypeInfos.find(name);
	//	if (m_classTemplateTypeInfos.end() != it)
	//	{
	//		char buf[512];
	//		sprintf_s(buf, "\'%s\' : already defined in %s(%d,%d)",
	//			memberNode->m_name->m_str.c_str(), it->second.m_sourceFile->m_fileName.c_str(),
	//			it->second.m_typeNode->m_name->m_lineNo, it->second.m_typeNode->m_name->m_columnNo);
	//		ErrorList_AddItem(m_currentSourceFile->m_fileName.c_str(), memberNode->m_name->m_lineNo,
	//			memberNode->m_name->m_columnNo, semantic_error_type_redefined, buf);
	//	}
	//}
}

void SourceFileManager::registerNamespace(NamespaceNode* namespaceNode)
{
	std::string name;
	namespaceNode->getFullName(name, 0);
	checkNameForRegister_(namespaceNode, name, nc_all & ~nc_namespace);
	m_namespaceInfos.insert(make_pair(name, std::vector<NamespaceInfo>())).first->second.push_back(NamespaceInfo(namespaceNode, m_currentSourceFile));
}

void SourceFileManager::registerType(MemberNode* typeNode)
{
	if(snt_class == typeNode->m_nodeType)
	{
		ClassNode* classNode = static_cast<ClassNode*>(typeNode);
		assert(0 == classNode->m_templateArgumentList);
	}
	std::string name;
	typeNode->getFullName(name, 0);
	checkNameForRegister_(typeNode, name, nc_all);
	m_typeInfos.insert(make_pair(name, TypeInfo(typeNode, m_currentSourceFile)));
}


void SourceFileManager::attachSyntaxTree(ProgramNode* programNode)
{
	assert(0 != m_currentSourceFile && 0 == m_currentSourceFile->m_syntaxTree);
	m_currentSourceFile->m_syntaxTree = programNode;
}

void CollectSourceFiles(std::vector<SourceFile*>& sourceFiles, SourceFile* sourceFile)
{
	size_t count = sourceFile->m_importSourceFiles.size();
	for(size_t i = 0; i < count; ++i)
	{
		CollectSourceFiles(sourceFiles, sourceFile->m_importSourceFiles[i]);
	}
	sourceFiles.push_back(sourceFile);
}

void SourceFileManager::checkTypeInfos()
{
	std::vector<SourceFile*> sourceFiles;
	CollectSourceFiles(sourceFiles, m_mainSourceFile);
	size_t count = sourceFiles.size();
	for(size_t i = 0; i < count; ++i)
	{
		if(0 != sourceFiles[i]->m_syntaxTree)
		{
			m_currentSourceFile = sourceFiles[i];
			m_currentSourceFile->m_syntaxTree->collectTypeInfo();
		}
	}
}

void SourceFileManager::checkSemantic()
{
	if(0 != m_mainSourceFile && 0 != m_mainSourceFile->m_syntaxTree)
	{
		m_currentSourceFile = m_mainSourceFile;
		m_mainSourceFile->m_syntaxTree->checkSemantic();
	}
}

TypeInfo* SourceFileManager::findTypeInfo(IdentifyNode* identifyNode, const std::string& typeName, bool isGlobal, ScopeNode* scopeNode)
{
	char buf[512];
	TypeInfo* typeInfo = 0;
	if (isGlobal)
	{
		auto it = m_typeInfos.find(typeName);
		if (m_typeInfos.end() != it)
		{
			typeInfo = &it->second;
		}
	}
	else
	{
		ScopeNode* enclosing = scopeNode;
		while (enclosing)
		{
			std::string containerName;
			enclosing->getFullName(containerName, 0);
			std::string fullName = containerName + "::" + typeName;
			auto it = m_typeInfos.find(fullName);
			if (m_typeInfos.end() != it)
			{
				typeInfo = &it->second;
				break;
			}
			enclosing = enclosing->m_enclosing;
		}
		if (0 == typeInfo)
		{
			auto it = m_typeInfos.begin();
			auto end = m_typeInfos.end();
			for (; it != end; ++it)
			{
				if (it->first.length() < typeName.length())
				{
					continue;
				}
				size_t offset = it->first.length() - typeName.length();
				if (typeName == it->first.c_str() + offset &&
					(0 == offset || ':' == it->first[offset - 1]))
				{
					if (0 == typeInfo)
					{
						typeInfo = &it->second;
					}
					else
					{
						TypeInfo* typeInfo2 = &it->second;
						sprintf_s(buf, "\'%s\' : ambiguous type name"
							" could be %s(%d, %d)"
							" or %s(%d, %d)",
							typeName.c_str(),
							typeInfo->m_sourceFile->m_fileName.c_str(), typeInfo->m_typeNode->m_name->m_lineNo, typeInfo->m_typeNode->m_name->m_columnNo,
							typeInfo2->m_sourceFile->m_fileName.c_str(), typeInfo2->m_typeNode->m_name->m_lineNo, typeInfo2->m_typeNode->m_name->m_columnNo);
						ErrorList_AddItem_CurrentFile(identifyNode->m_lineNo,
							identifyNode->m_columnNo, semantic_error_ambiguous_type_name, buf);
						return 0;
					}
				}
			}
		}
	}
	if (0 == typeInfo)
	{
		sprintf_s(buf, "\'%s\' : is not a type name", typeName.c_str());
		ErrorList_AddItem_CurrentFile(identifyNode->m_lineNo,
			identifyNode->m_columnNo, semantic_error_invalid_type_name, buf);
	}
	return typeInfo;
}

void SourceFileManager::useType(TypeInfo* typeInfo, UseType usage)
{
	if(0 == typeInfo)
	{
		return;
	}
	auto it = m_usedTypes.find(typeInfo);
	if(m_usedTypes.end() == it)
	{
		m_usedTypes.insert(std::make_pair(typeInfo, usage));
	}
	else
	{
		it->second |= usage;
	}
}

void SourceFileManager::outputUsedTypes(FILE* file)
{
	char buf[512];
	std::set<SourceFile*> sourceFiles;
	std::set<MemberNode*> typeNodes;
	auto begin = m_usedTypes.begin();
	auto end = m_usedTypes.end();
	for(auto it = begin; it != end; ++it)
	{
		TypeInfo* typeInfo = it->first;
		if ((it->second & ut_as_base) || 
			(it->second & ut_by_value) || 
			typeInfo->m_typeNode->isTemplateClass() || 
			(typeInfo->m_typeNode->m_enclosing != 0 && typeInfo->m_typeNode->m_enclosing->m_nodeType != snt_namespace))
		{
			sourceFiles.insert(typeInfo->m_sourceFile);
		}
		else
		{
			typeNodes.insert(typeInfo->m_typeNode);
		}
	}
	auto begin2 = sourceFiles.begin();
	auto end2 = sourceFiles.end();
	for(auto it2 = begin2; it2 != end2; ++it2)
	{
		std::string fileName;
		GetRelativePath(fileName, m_mainSourceFile->m_fileName.c_str(), (*it2)->m_fileName.c_str());
		size_t dotPos = fileName.find_last_of('.');
		size_t slashPos = fileName.find_last_of("\\/");
		if(std::string::npos == slashPos || slashPos < dotPos)
		{
			fileName.erase(dotPos);
		}
		fileName += ".h";
		writeStringToFile("#include \"", file);
		FormatPathForInclude(fileName);
		writeStringToFile(fileName.c_str(), fileName.length(), file);
		writeStringToFile("\"\n", file);
	}
	bool outputTypeDec = false;
	auto begin3 = typeNodes.begin();
	auto end3 = typeNodes.end();
	for (auto it3 = begin3; it3 != end3; ++it3)
	{
		int indentation = 0;
		MemberNode* typeNode = *it3;
		if(snt_class == typeNode->m_nodeType)
		{
			ClassNode* classNode = static_cast<ClassNode*>(typeNode);
			std::vector<ScopeNode*> enclosings;
			classNode->getEnclosings(enclosings);

			size_t count = enclosings.size();
			for (size_t i = 0; i < count; ++i)
			{
				ScopeNode* scopeNode = enclosings[i];
				assert(snt_namespace == scopeNode->m_nodeType);
				sprintf_s(buf, "namespace %s{ ", scopeNode->m_name->m_str.c_str());
				writeStringToFile(buf, file);
			}
			sprintf_s(buf, "%s%s;", g_keywordTokens[classNode->m_keyword->m_nodeType - snt_keyword_begin_output - 1], typeNode->m_name->m_str.c_str());
			writeStringToFile(buf, file, indentation);
			for (size_t i = 0; i < count; ++i)
			{
				writeStringToFile(" }", file);
			}
			writeStringToFile("\n", file);

		}
	}
}

void SourceFileManager::outputUsedTypesForMetaSource(FILE* file)
{
	std::set<SourceFile*> sourceFiles;
	auto begin = m_usedTypes.begin();
	auto end = m_usedTypes.end();
	for(auto it = begin; it != end; ++it)
	{
		//if((it->second & ut_by_value) || (it->second & ut_by_ref))
		{
			TypeInfo* typeInfo = it->first;
			sourceFiles.insert(typeInfo->m_sourceFile);
		}
	}
	auto begin2 = sourceFiles.begin();
	auto end2 = sourceFiles.end();
	for(auto it2 = begin2; it2 != end2; ++it2)
	{
		std::string fileName;
		GetRelativePath(fileName, m_mainSourceFile->m_fileName.c_str(), (*it2)->m_fileName.c_str());
		size_t dotPos = fileName.find_last_of('.');
		size_t slashPos = fileName.find_last_of('\\');
		if(std::string::npos == slashPos || slashPos < dotPos)
		{
			fileName.erase(dotPos);
		}
		fileName += g_options.m_metaHeaderFilePostfix;
		writeStringToFile("#include \"", file);
		
		FormatPathForInclude(fileName);
		writeStringToFile(fileName.c_str(), fileName.length(), file);
		writeStringToFile("\"\n", file);
	}
}


const char g_strHeader[] = 
{
	"//DO NOT EDIT THIS FILE, it is generated by idlcpp\n"
	"//http://www.idlcpp.org\n\n"
};

bool SourceFileManager::generateCode(const char* fileName)
{
	if(0 != m_mainSourceFile && 0 != m_mainSourceFile->m_syntaxTree)
	{
		m_mainSourceFile->m_syntaxTree->extendInternalCode();

		const char* dirEnd = getDirNameEnd(fileName);
		const char* name = 0 == dirEnd ? fileName : dirEnd + 1;

		m_currentLineNo = 0;
		m_outputLineDirective = g_options.m_outputLineDirective;

		std::string headerFileName = fileName;
		headerFileName += ".h";
		bool res = generateHeaderFile(headerFileName.c_str());
		
		m_outputLineDirective = false;

		std::string sourceFileName = fileName;
		sourceFileName += g_options.m_internalSourceFilePostfix;
		res &= generateSourceFile(sourceFileName.c_str(), name);

		std::string metaHeaderFileName = fileName;
		metaHeaderFileName += g_options.m_metaHeaderFilePostfix;
		res &= generateMetaHeaderFile(metaHeaderFileName.c_str(), name);

		std::string metaSourceFileName = fileName;
		metaSourceFileName += g_options.m_metaSourceFilePostfix;
		res &= generateMetaSourceFile(metaSourceFileName.c_str(), name);
		/**/
		return res;
	}
	return false;
}

bool SourceFileManager::generateHeaderFile(const char* fileName)
{
	FILE* file= fopen(fileName, "w");
	if(0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		HeaderFileGenerator::generateCode(file, m_mainSourceFile);
		fclose(file);
		return true;	
	}
	return false;
}

bool SourceFileManager::generateSourceFile(const char* fileName, const char* cppName)
{
	FILE* file= fopen(fileName, "w");
	if(0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		SourceFileGenerator::generateCode(file, m_mainSourceFile, fileName, cppName);
		fclose(file);
		return true;	
	}
	return false;
}

bool SourceFileManager::generateMetaHeaderFile(const char* fileName, const char* cppName)
{
	FILE* file= fopen(fileName, "w");
	if(0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		MetaHeaderFileGenerator::generateCode(file, m_mainSourceFile, fileName, cppName);
		fclose(file);
		return true;	
	}
	return false;
}

bool SourceFileManager::generateMetaSourceFile(const char* fileName, const char* cppName)
{
	FILE* file= fopen(fileName, "w");
	if(0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		MetaSourceFileGenerator::generateCode(file, m_mainSourceFile, fileName, cppName);
		fclose(file);
		return true;	
	}
	return false;
}

char SourceFileManager::outputEmbededCodes(FILE* file, TokenNode* tokenNode)
{
	assert(0 != m_mainSourceFile);
	
	char lastChar =  m_mainSourceFile->outputEmbededCodes(file, tokenNode ? tokenNode->m_tokenNo : INT_MAX);
	if(m_outputLineDirective && tokenNode && m_currentLineNo != tokenNode->m_lineNo)
	{
		m_currentLineNo = tokenNode->m_lineNo;
		char buf[512];
		std::string fileName = m_mainSourceFile->m_fileName;
		FormatPathForInclude(fileName);
		sprintf_s(buf, "\n#line %d \"%s\"\n", m_currentLineNo, fileName.c_str());
		writeStringToFile(buf, file);
	}
	return lastChar;
}

SourceFileManager g_sourceFileManager;

void addSourceFile(const char* fileName)
{
	if(import_file_failed == g_sourceFileManager.addSourceFile(fileName))
	{
		ErrorList_AddItem_CurrentFile(import_error_file_not_existing, fileName);
	}
}

const char* getCurrentSourceFileName()
{
	const char* res = "";
	if(g_sourceFileManager.m_currentSourceFile)
	{
		res = g_sourceFileManager.m_currentSourceFile->m_fileName.c_str();
	}
	return res;
}

const char* getMainSourceFileName()
{
	const char* res = "";
	if(g_sourceFileManager.m_mainSourceFile)
	{
		res = g_sourceFileManager.m_mainSourceFile->m_fileName.c_str();
	}
	return res;
}
