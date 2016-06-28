#include "SourceFileGenerator.h"
#include "Utility.h"
#include "SourceFile.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "IdentityListNode.h"
#include "ScopeNameListNode.h"
#include "MemberListNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "TemplateParametersNode.h"
#include "TemplateParameterListNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "FieldNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "ParameterNode.h"
#include "TypedefNode.h"
#include "Options.h"
#include "Platform.h"
#include <assert.h>

void generateCode_Token(FILE* file, TokenNode* tokenNode, int indentation);
void generateCode_Identify(FILE* file, IdentifyNode* identifyNode, int indentation);
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
	if (namespaceNode->isNoCode())
	{
		file = 0;
	}

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
	if(classNode->m_templateParametersNode)
	{
		std::vector<IdentifyNode*> templateParameterNodes;
		classNode->m_templateParametersNode->collectParameterNodes(templateParameterNodes);
		className += "<";
		size_t count = templateParameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				className += ", ";
			}
			className += templateParameterNodes[i]->m_str;
		}
		className += ">";
	}
}

void SourceFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, int indentation)
{
	if (classNode->isNoCode())
	{
		file = 0;
	}

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

}

void SourceFileGenerator::generateCode_TemplateHeader(FILE* file, ClassNode* classNode, int indentation)
{
	if(classNode->m_templateParametersNode)
	{
		std::vector<IdentifyNode*> templateParameterNodes;
		classNode->m_templateParametersNode->collectParameterNodes(templateParameterNodes);
		writeStringToFile("template<", file, indentation);
		size_t count = templateParameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				writeStringToFile(",", file);
			}
			writeStringToFile("typename ", file);
			writeStringToFile(templateParameterNodes[i]->m_str.c_str(), file);
		}
		writeStringToFile(">\n", file);
	}
}
