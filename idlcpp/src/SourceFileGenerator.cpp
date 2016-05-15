#include "SourceFileGenerator.h"
#include "SourceFile.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "ScopeListNode.h"
#include "MemberListNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "TemplateParametersNode.h"
#include "TemplateParameterNode.h"
#include "TemplateParameterListNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "FilterNode.h"
#include "FieldNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "ParameterNode.h"
#include "TypeAliasNode.h"
#include "Options.h"
#include "Platform.h"
#include <assert.h>

void generateCode_Token(FILE* file, TokenNode* tokenNode, int indentation);
void generateCode_Identify(FILE* file, IdentifyNode* identifyNode, int indentation);
void generateCode_TypeName(FILE* file, TypeNameNode* typeNameNode, ScopeNode* scopeNode, int indentation);
void generateCode_Parameter(FILE* file, ParameterNode* parameterNode, MethodNode* methodNode, int indentation);

void SourceFileGenerator::generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName)
{
	generateCode_Program(dstFile, sourceFile->m_syntaxTree, fullPathName, baseName);
}

void SourceFileGenerator::generateCode_Program(FILE* file, ProgramNode* programNode, const char* fileName, const char* cppName)
{
	char buf[512];
	std::string pafcorePath;
	GetRelativePath(pafcorePath, fileName, g_options.m_pafcorePath.c_str());
	FormatPathForInclude(pafcorePath);

	writeStringToFile("#pragma once\n\n", file);

	sprintf_s(buf, "#include \"%s.h\"\n", cppName);
	writeStringToFile(buf, file);

	sprintf_s(buf, "#include \"%s%s\"\n", cppName, g_options.m_metaHeaderFilePostfix.c_str());
	writeStringToFile(buf, file);

	sprintf_s(buf, "#include \"%sRefCount.h\"\n\n", pafcorePath.c_str());
	writeStringToFile(buf, file);

	generateCode_Namespace(file, programNode, -1);
}

void SourceFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
	char buf[512];
	if(!namespaceNode->isGlobalNamespace())
	{
		sprintf_s(buf, "namespace %s\n", namespaceNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n\n", file, indentation);
	}
	std::vector<MemberNode*> memberNodes;
	namespaceNode->m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(memberNode), indentation + 1);
			break;
		case snt_namespace:
			generateCode_Namespace(file, static_cast<NamespaceNode*>(memberNode), indentation + 1);
			break;
		}
	}

	if(!namespaceNode->isGlobalNamespace())
	{
		writeStringToFile("}\n\n", file, indentation);
	}
}

void GetClassName(std::string& className, ClassNode* classNode)
{
	className = classNode->m_name->m_str;
	if(classNode->m_templateParameters)
	{
		std::vector<TemplateParameterNode*> templateParameterNodes;
		classNode->m_templateParameters->collectParameterNodes(templateParameterNodes);
		className += "<";
		size_t count = templateParameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				className += ", ";
			}
			className += templateParameterNodes[i]->m_name->m_str;
		}
		className += ">";
	}
}

void SourceFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, int indentation)
{
	if (!classNode->isValueType())
	{
		std::string typeName;
		GetClassName(typeName, classNode);

		generateCode_TemplateHeader(file, classNode, indentation);
		writeStringToFile("::pafcore::ClassType* ", file, indentation);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile("::GetType()\n", file);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return ::RuntimeTypeOf<", file, indentation + 1);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile(">::RuntimeType::GetSingleton();\n", file);
		writeStringToFile("}\n\n", file, indentation);

		generateCode_TemplateHeader(file, classNode, indentation);
		writeStringToFile("::pafcore::ClassType* ", file, indentation);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile("::getType()\n", file);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return ::RuntimeTypeOf<", file, indentation + 1);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile(">::RuntimeType::GetSingleton();\n", file);
		writeStringToFile("}\n\n", file, indentation);

		generateCode_TemplateHeader(file, classNode, indentation);
		writeStringToFile("size_t ", file, indentation);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile("::getAddress()\n", file);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return (size_t)this;\n", file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);
	}
	if(!classNode->m_additionalMethods.empty())
	{
		size_t count = classNode->m_additionalMethods.size();
		for(size_t i = 0; i < count; ++i)
		{
			generateCode_AdditionalMethod(file, classNode->m_additionalMethods[i], indentation);
		}
	}
}

void SourceFileGenerator::generateCode_TemplateHeader(FILE* file, ClassNode* classNode, int indentation)
{
	if(classNode->m_templateParameters)
	{
		std::vector<TemplateParameterNode*> templateParameterNodes;
		classNode->m_templateParameters->collectParameterNodes(templateParameterNodes);
		writeStringToFile("template<", file, indentation);
		size_t count = templateParameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				writeStringToFile(",", file);
			}
			writeStringToFile("typename ", file);
			writeStringToFile(templateParameterNodes[i]->m_name->m_str.c_str(), file);
		}
		writeStringToFile(">\n", file);
	}
}


void SourceFileGenerator::generateCode_AdditionalMethod(FILE* file, MethodNode* methodNode, int indentation)
{
	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);

	generateCode_TemplateHeader(file, classNode, indentation);

	std::string typeName;
	GetClassName(typeName, classNode);

	writeStringToFile(typeName.c_str(), file, indentation);

	if(0 != methodNode->m_passing)
	{
		generateCode_Token(file, methodNode->m_passing, 0);
	}
	writeStringToFile(g_strSpaces, 1, file);
	writeStringToFile(typeName.c_str(), file);
	writeStringToFile("::", file);

	generateCode_Identify(file, methodNode->m_name, 0);

	generateCode_Token(file, methodNode->m_leftParenthesis, 0);
	std::vector<std::pair<TokenNode*, ParameterNode*>> parameterNodes;
	methodNode->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for(size_t i = 0; i < parameterCount; ++i)
	{
		if(parameterNodes[i].first)
		{
			generateCode_Token(file, parameterNodes[i].first, 0);
		}
		generateCode_Parameter(file, parameterNodes[i].second, methodNode, 0);
	}
	generateCode_Token(file, methodNode->m_rightParenthesis, 0);
	writeStringToFile("\n", file);
	char buf[512];
	writeStringToFile("{\n", file, indentation);
	if("NewArray" == methodNode->m_name->m_str)
	{
		if(classNode->isValueType())
		{
			sprintf_s(buf, "return new_array<%s>(count);\n", typeName.c_str());
		}
		else
		{
			sprintf_s(buf, "return new_array<::pafcore::RefCountObject<%s>>(count);\n", typeName.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	else if("NewArrayARC" == methodNode->m_name->m_str)
	{
		sprintf_s(buf, "return new_array<::pafcore::AtomicRefCountObject<%s>>(count);\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		if("New" == methodNode->m_name->m_str || "Clone" == methodNode->m_name->m_str)
		{
			if(classNode->isValueType())
			{
				sprintf_s(buf, "return new %s(", typeName.c_str());
			}
			else
			{
				sprintf_s(buf, "return new ::pafcore::RefCountObject<%s>(", typeName.c_str());
			}
		}
		else
		{
			assert("NewARC" == methodNode->m_name->m_str || "CloneARC" == methodNode->m_name->m_str);
			sprintf_s(buf, "return new ::pafcore::AtomicRefCountObject<%s>(", typeName.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		for(size_t i = 0; i < parameterCount; ++i)
		{
			if(i != 0)
			{
				writeStringToFile(", ", file);
			}
			writeStringToFile(parameterNodes[i].second->m_name->m_str.c_str(), file);
		}
		writeStringToFile(");\n", file);
	}
	writeStringToFile("}\n\n", file, indentation);
}