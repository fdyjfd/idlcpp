#include "Compiler.h"
#include "SourceFile.h"
#include "Utility.h"
#include "Platform.h"
#include "ImportDirectory.h"
#include "ErrorList.h"
#include "Options.h"
#include "TypeTree.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "IdentifyNode.h"
#include "MemberListNode.h"
#include "ClassNode.h"
#include "TypeNameNode.h"
#include "TemplateClassInstanceNode.h"
#include "TypedefNode.h"
#include "EnumNode.h"
#include "ScopeNameListNode.h"
#include "ScopeNameNode.h"
#include "HeaderFileGenerator.h"
#include "SourceFileGenerator.h"
#include "MetaHeaderFileGenerator.h"
#include "MetaSourceFileGenerator.h"
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <assert.h>



Compiler::Compiler()
{
	m_currentSourceFile = 0;
	m_mainSourceFile = 0;
	m_insertSourceFilePosition = 0;
	m_currentLineNo = 0;
}

void Compiler::insertUnParsedSourceFile(const std::string& fileName)
{
	m_sourceFileNames.insert(fileName);
	assert(m_insertSourceFilePosition <= m_unParsedSourceFiles.size());
	SourceFile* sourceFile = new SourceFile;
	sourceFile->m_fileName = fileName;
	m_unParsedSourceFiles.insert(m_unParsedSourceFiles.begin() + m_insertSourceFilePosition, sourceFile);
	m_insertSourceFilePosition++;
	if (m_currentSourceFile)
	{
		m_currentSourceFile->m_importSourceFiles.push_back(sourceFile);
	}
}

int Compiler::addSourceFile(const char* fileName)
{
	if (strlen(fileName) == 0)
	{
		return import_file_failed;
	}
	std::string fullName;
	if (isAbsolutePath(fileName))
	{
		normalizeFileName(fullName, fileName);
		if (m_sourceFileNames.find(fullName) != m_sourceFileNames.end())
		{
			return import_file_already_import;
		}
		if (fileExisting(fullName.c_str()))
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
		for (; it != end; ++it)
		{
			std::string str = *it + fileName;
			normalizeFileName(fullName, str.c_str());
			if (m_sourceFileNames.find(fullName) != m_sourceFileNames.end())
			{
				return import_file_already_import;
			}
			if (fileExisting(fullName.c_str()))
			{
				insertUnParsedSourceFile(fullName);
				return import_file_succeeded;
			}
		}
	}
	return import_file_failed;
}

SourceFile* Compiler::popSourceFile()
{
	if (m_unParsedSourceFiles.empty())
	{
		return 0;
	}
	SourceFile* sourceFile = m_unParsedSourceFiles.front();
	m_unParsedSourceFiles.erase(m_unParsedSourceFiles.begin());
	m_insertSourceFilePosition = 0;
	return sourceFile;
}

void Compiler::prepareParse(SourceFile* sourceFile, bool main)
{
	m_currentSourceFile = sourceFile;
	if (main)
	{
		assert(0 == m_mainSourceFile);
		m_mainSourceFile = m_currentSourceFile;
	}
}

void Compiler::attachSyntaxTree(ProgramNode* programNode)
{
	assert(0 != m_currentSourceFile && 0 == m_currentSourceFile->m_syntaxTree);
	m_currentSourceFile->m_syntaxTree = programNode;
	programNode->m_sourceFile = m_currentSourceFile;
}

void CollectSourceFiles(std::vector<SourceFile*>& sourceFiles, SourceFile* sourceFile)
{
	size_t count = sourceFile->m_importSourceFiles.size();
	for (size_t i = 0; i < count; ++i)
	{
		CollectSourceFiles(sourceFiles, sourceFile->m_importSourceFiles[i]);
	}
	sourceFiles.push_back(sourceFile);
}

void Compiler::collectTypes()
{
	std::vector<SourceFile*> sourceFiles;
	CollectSourceFiles(sourceFiles, m_mainSourceFile);
	size_t count = sourceFiles.size();
	for (size_t i = 0; i < count; ++i)
	{
		if (0 != sourceFiles[i]->m_syntaxTree)
		{
			m_currentSourceFile = sourceFiles[i];
			m_currentSourceFile->m_syntaxTree->collectTypes(0, 0);
		}
	}
}

void Compiler::checkTypeNames()
{
	std::vector<SourceFile*> sourceFiles;
	CollectSourceFiles(sourceFiles, m_mainSourceFile);
	size_t count = sourceFiles.size();
	for (size_t i = 0; i < count; ++i)
	{
		if (0 != sourceFiles[i]->m_syntaxTree)
		{
			m_currentSourceFile = sourceFiles[i];
			m_currentSourceFile->m_syntaxTree->checkTypeNames(0, 0);
		}
	}
}

void Compiler::checkSemantic()
{
	std::vector<SourceFile*> sourceFiles;
	CollectSourceFiles(sourceFiles, m_mainSourceFile);
	size_t count = sourceFiles.size();
	for (size_t i = 0; i < count; ++i)
	{
		if (0 != sourceFiles[i]->m_syntaxTree)
		{
			m_currentSourceFile = sourceFiles[i];
			m_currentSourceFile->m_syntaxTree->checkSemantic(0);
		}
	}
}

void Compiler::extendInternalCode()
{
	std::vector<SourceFile*> sourceFiles;
	CollectSourceFiles(sourceFiles, m_mainSourceFile);
	size_t count = sourceFiles.size();
	for (size_t i = 0; i < count; ++i)
	{
		if (0 != sourceFiles[i]->m_syntaxTree)
		{
			m_currentSourceFile = sourceFiles[i];
			m_currentSourceFile->m_syntaxTree->extendInternalCode(0, 0);
		}
	}
	//if (0 != m_mainSourceFile && 0 != m_mainSourceFile->m_syntaxTree)
	//{
	//	m_currentSourceFile = m_mainSourceFile;
	//	m_mainSourceFile->m_syntaxTree->extendInternalCode(0, 0);
	//}
}

void Compiler::useType(TypeNode* typeNode, TemplateArguments* templateArguments, TypeUsage usage, TypeNameNode* typeNameNode)
{
	useType(typeNode, usage, typeNameNode);
	TypeNode* actualTypeNode = typeNode->getActualTypeNode(templateArguments);
	if (actualTypeNode != typeNode)
	{
		useType(actualTypeNode, tu_use_definition, typeNameNode);
	}
}

void Compiler::useType(TypeNode* typeNode, TypeUsage usage, TypeNameNode* typeNameNode)
{
	if (m_mainSourceFile != m_currentSourceFile)
	{
		return;
	}
	if (0 == typeNode || typeNode->isPredefinedType()
		|| typeNode->isTemplateParameter())
	{
		return;
	}
	if (typeNode->isTemplateClassInstance())
	{
		typeNode = static_cast<TemplateClassInstanceTypeNode*>(typeNode)->m_templateClassInstanceNode->m_classTypeNode;
	}
	assert(typeNameNode->m_scopeNameList);
	int tokenNo = typeNameNode->m_scopeNameList->m_scopeName->m_name->m_tokenNo;
	UsedType ut = { typeNode, usage, tokenNo };
	auto it = std::find(m_usedTypes.begin(), m_usedTypes.end(), ut);
	if (m_usedTypes.end() == it)
	{
		m_usedTypes.push_back(ut);
	}
	else
	{
		it->usage |= usage;
		if (it->tokenNo > tokenNo)
		{
			it->tokenNo = tokenNo;
		}
	}
}

void Compiler::outputUsedTypes(FILE* file, SourceFile* sourceFile)
{
	char buf[4096];
	std::vector<SourceFile*> sourceFiles;
	std::vector<TypeNode*> typeNodes;
	auto begin = m_usedTypes.begin();
	auto end = m_usedTypes.end();
	for (auto it = begin; it != end; ++it)
	{
		TypeNode* typeNode = it->typeNode;
		if (typeNode->isTypeDeclaration())
		{
			continue;
		}
		if (typeNode->m_sourceFile != sourceFile)
		{
			if ( (it->usage & tu_use_definition) || !typeNode->getEnclosing()->isNamespace()
				|| typeNode->isTemplateClass() || typeNode->isTypedef() || typeNode->isTemplateClassInstance())
			{
				if (std::find(sourceFiles.begin(), sourceFiles.end(), typeNode->m_sourceFile)
					== sourceFiles.end())
				{
					sourceFiles.push_back(typeNode->m_sourceFile);
				}
			}
			else
			{
				if (std::find(typeNodes.begin(), typeNodes.end(), typeNode) == typeNodes.end())
				{
					typeNodes.push_back(typeNode);
				}
			}
		}
		else
		{
			if (it->tokenNo < typeNode->m_identifyNode->m_tokenNo && typeNode->getEnclosing()->isNamespace())
			{
				if (std::find(typeNodes.begin(), typeNodes.end(), typeNode) == typeNodes.end())
				{
					typeNodes.push_back(typeNode);
				}
			}
		}
	}
	auto begin2 = sourceFiles.begin();
	auto end2 = sourceFiles.end();
	for (auto it2 = begin2; it2 != end2; ++it2)
	{
		std::string fileName;
		GetRelativePath(fileName, m_mainSourceFile->m_fileName.c_str(), (*it2)->m_fileName.c_str());
		size_t dotPos = fileName.find_last_of('.');
		size_t slashPos = fileName.find_last_of("\\/");
		if (std::string::npos == slashPos || slashPos < dotPos)
		{
			fileName.erase(dotPos);
		}
		fileName += ".h";
		writeStringToFile("#include \"", file);
		FormatPathForInclude(fileName);
		writeStringToFile(fileName.c_str(), fileName.length(), file);
		writeStringToFile("\"\n", file);
	}

	auto begin3 = typeNodes.begin();
	auto end3 = typeNodes.end();
	for (auto it3 = begin3; it3 != end3; ++it3)
	{
		int indentation = 0;
		TypeNode* typeNode = *it3;
		assert(typeNode->isClass() || typeNode->isEnum());
		std::vector<TypeNode*> enclosings;
		typeNode->getEnclosings(enclosings);
		assert(!enclosings.empty() && enclosings[0] == g_typeTree.getRootNamespaceTypeNode());

		size_t count = enclosings.size();
		for (size_t i = 1; i < count; ++i)
		{
			TypeNode* scopeNode = enclosings[i];
			assert(scopeNode->isNamespace());
			sprintf_s(buf, "namespace %s{ ", scopeNode->m_name.c_str());
			writeStringToFile(buf, file);
		}

		buf[0] = 0;
		if (typeNode->isTemplateClass())
		{
			ClassNode* classNode = static_cast<ClassTypeNode*>(typeNode)->m_classNode;
			std::string paramNames;
			auto begin = static_cast<ClassTypeNode*>(typeNode)->m_parameterNodes.begin();
			auto end = static_cast<ClassTypeNode*>(typeNode)->m_parameterNodes.end();
			for (auto it = begin; it != end; ++it)
			{
				TemplateParameterTypeNode* paramTypeNode = *it;
				if(it != begin)
				{
					paramNames += ", ";
				}
				paramNames += "typename " + paramTypeNode->m_name;
			}
			std::vector<TemplateParameterTypeNode*> m_parameterNodes;

			sprintf_s(buf, "template<%s>%s%s;", paramNames.c_str(), 
				g_keywordTokens[classNode->m_keyword->m_nodeType - snt_begin_output - 1], typeNode->m_name.c_str());
		}
		else if (typeNode->isClass())
		{
			ClassNode* classNode = static_cast<ClassTypeNode*>(typeNode)->m_classNode;
			if (0 == classNode->m_nativeName)
			{
				sprintf_s(buf, "%s%s;", g_keywordTokens[classNode->m_keyword->m_nodeType - snt_begin_output - 1], typeNode->m_name.c_str());
			}
		}
		else if (typeNode->isEnum())
		{
			EnumNode* enumNode = static_cast<EnumTypeNode*>(typeNode)->m_enumNode;
			if (0 == enumNode->m_nativeName)
			{
				sprintf_s(buf, "%s%s;", g_keywordTokens[snt_keyword_enum - snt_begin_output - 1], typeNode->m_name.c_str());
			}
		}
		writeStringToFile(buf, file, indentation);
		for (size_t i = 1; i < count; ++i)
		{
			writeStringToFile(" }", file);
		}
		writeStringToFile("\n", file);
	}
}

void Compiler::outputUsedTypesForMetaHeader(FILE* file, SourceFile* sourceFile)
{
	std::vector<SourceFile*> sourceFiles;
	auto begin = m_usedTypes.begin();
	auto end = m_usedTypes.end();
	for (auto it = begin; it != end; ++it)
	{
		if (it->usage & tu_use_meta)
		{
			TypeNode* typeNode = it->typeNode;
			if (typeNode->m_sourceFile != sourceFile)
			{
				if (std::find(sourceFiles.begin(), sourceFiles.end(), typeNode->m_sourceFile)
					== sourceFiles.end())
				{
					sourceFiles.push_back(typeNode->m_sourceFile);
				}
			}
		}
	}
	auto begin2 = sourceFiles.begin();
	auto end2 = sourceFiles.end();
	for (auto it2 = begin2; it2 != end2; ++it2)
	{
		std::string fileName;
		GetRelativePath(fileName, m_mainSourceFile->m_fileName.c_str(), (*it2)->m_fileName.c_str());
		size_t dotPos = fileName.find_last_of('.');
		size_t slashPos = fileName.find_last_of('\\');
		if (std::string::npos == slashPos || slashPos < dotPos)
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

void Compiler::outputUsedTypesForMetaSource(FILE* file, SourceFile* sourceFile)
{
	std::vector<SourceFile*> sourceFiles;
	auto begin = m_usedTypes.begin();
	auto end = m_usedTypes.end();
	for (auto it = begin; it != end; ++it)
	{
		TypeNode* typeNode = it->typeNode;
		if (typeNode->m_sourceFile != sourceFile)
		{
			if (std::find(sourceFiles.begin(), sourceFiles.end(), typeNode->m_sourceFile)
				== sourceFiles.end())
			{
				sourceFiles.push_back(typeNode->m_sourceFile);
			}
		}
	}
	auto begin2 = sourceFiles.begin();
	auto end2 = sourceFiles.end();
	for (auto it2 = begin2; it2 != end2; ++it2)
	{
		std::string fileName;
		GetRelativePath(fileName, m_mainSourceFile->m_fileName.c_str(), (*it2)->m_fileName.c_str());
		size_t dotPos = fileName.find_last_of('.');
		size_t slashPos = fileName.find_last_of('\\');
		if (std::string::npos == slashPos || slashPos < dotPos)
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

bool Compiler::generateCode(const char* fileName)
{
	if (0 != m_mainSourceFile && 0 != m_mainSourceFile->m_syntaxTree)
	{
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

		return res;
	}
	return false;
}

bool Compiler::generateHeaderFile(const char* fileName)
{
	FILE* file = fopen(fileName, "w");
	if (0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		HeaderFileGenerator::generateCode(file, m_mainSourceFile);
		fclose(file);
		return true;
	}
	return false;
}

bool Compiler::generateSourceFile(const char* fileName, const char* cppName)
{
	FILE* file = fopen(fileName, "w");
	if (0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		SourceFileGenerator::generateCode(file, m_mainSourceFile, fileName, cppName);
		fclose(file);
		return true;
	}
	return false;
}

bool Compiler::generateMetaHeaderFile(const char* fileName, const char* cppName)
{
	FILE* file = fopen(fileName, "w");
	if (0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		MetaHeaderFileGenerator::generateCode(file, m_mainSourceFile, fileName, cppName);
		fclose(file);
		return true;
	}
	return false;
}

bool Compiler::generateMetaSourceFile(const char* fileName, const char* cppName)
{
	FILE* file = fopen(fileName, "w");
	if (0 != file)
	{
		writeStringToFile(g_strHeader, sizeof(g_strHeader) - 1, file);
		MetaSourceFileGenerator::generateCode(file, m_mainSourceFile, fileName, cppName);
		fclose(file);
		return true;
	}
	return false;
}

void Compiler::outputEmbededCodes(FILE* file, TokenNode* tokenNode)
{
	assert(0 != m_mainSourceFile);

	m_mainSourceFile->outputEmbededCodes(file, tokenNode ? tokenNode->m_tokenNo : INT_MAX);
	if (m_outputLineDirective && tokenNode && m_currentLineNo < tokenNode->m_lineNo)
	{
		m_currentLineNo = tokenNode->m_lineNo;
		char buf[4096];
		std::string fileName = m_mainSourceFile->m_fileName;
		FormatPathForInclude(fileName);
		sprintf_s(buf, "\n#line %d \"%s\"\n", m_currentLineNo, fileName.c_str());
		writeStringToFile(buf, file);
	}
}


Compiler g_compiler;

void addSourceFile(const char* fileName)
{
	if (import_file_failed == g_compiler.addSourceFile(fileName))
	{
		ErrorList_AddItem_CurrentFile(import_error_file_not_existing, fileName);
	}
}

const char* getCurrentSourceFileName()
{
	const char* res = "";
	if (g_compiler.m_currentSourceFile)
	{
		res = g_compiler.m_currentSourceFile->m_fileName.c_str();
	}
	return res;
}

