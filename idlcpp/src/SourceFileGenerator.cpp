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
#include "ParameterListNode.h"
#include "TypedefNode.h"
#include "Options.h"
#include "Platform.h"
#include <assert.h>

void generateCode_Token(FILE* file, TokenNode* tokenNode, int indentation);
void generateCode_Identify(FILE* file, IdentifyNode* identifyNode, int indentation, bool addSpace = true);
void generateCode_Parameter(FILE* file, ParameterNode* parameterNode, ScopeNode* scopeNode, int indentation);

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

	sprintf_s(buf, "#include \"%sRefCountImpl.h\"\n\n", pafcorePath.c_str());
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

		bool isInline = 0 != classNode->m_templateParametersNode;

		generateCode_TemplateHeader(file, classNode, indentation);
		if (isInline)
		{
			writeStringToFile("inline ::pafcore::ClassType* ", file, indentation);
		}
		else
		{
			writeStringToFile("::pafcore::ClassType* ", file, indentation);
		}
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile("::GetType()\n", file);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return ::RuntimeTypeOf<", file, indentation + 1);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile(">::RuntimeType::GetSingleton();\n", file);
		writeStringToFile("}\n\n", file, indentation);

		generateCode_TemplateHeader(file, classNode, indentation);
		if (isInline)
		{
			writeStringToFile("inline ::pafcore::ClassType* ", file, indentation);
		}
		else
		{
			writeStringToFile("::pafcore::ClassType* ", file, indentation);
		}
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile("::getType()\n", file);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return ::RuntimeTypeOf<", file, indentation + 1);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile(">::RuntimeType::GetSingleton();\n", file);
		writeStringToFile("}\n\n", file, indentation);

		generateCode_TemplateHeader(file, classNode, indentation);
		if (isInline)
		{
			writeStringToFile("inline size_t ", file, indentation);
		}
		else
		{
			writeStringToFile("size_t ", file, indentation);
		}
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile("::getAddress()\n", file);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return (size_t)this;\n", file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);
	}
	if (!classNode->m_additionalMethods.empty())
	{
		size_t count = classNode->m_additionalMethods.size();
		for (size_t i = 0; i < count; ++i)
		{
			generateCode_AdditionalMethod(file, classNode->m_additionalMethods[i], indentation);
		}
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


void SourceFileGenerator::generateCode_AdditionalMethod(FILE* file, MethodNode* methodNode, int indentation)
{
	if (methodNode->isNoCode())
	{
		file = 0;
	}

	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	std::string typeName;
	GetClassName(typeName, classNode);
	bool isInline = 0 != classNode->m_templateParametersNode;

	generateCode_TemplateHeader(file, classNode, indentation);

	if (isInline)
	{
		writeStringToFile("inline ", file, indentation);
		writeStringToFile(typeName.c_str(), file);
	}
	else
	{
		writeStringToFile(typeName.c_str(), file, indentation);
	}


	if (0 != methodNode->m_passing)
	{
		generateCode_Token(file, methodNode->m_passing, 0);
	}
	writeSpaceToFile(file);;
	writeStringToFile(typeName.c_str(), file);
	writeStringToFile("::", file);

	generateCode_Identify(file, methodNode->m_name, 0);

	generateCode_Token(file, methodNode->m_leftParenthesis, 0);
	std::vector<ParameterNode*> parameterNodes;

	methodNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for (size_t i = 0; i < parameterCount; ++i)
	{
		if (0 != i)
		{
			writeStringToFile(", ", file);
		}
		generateCode_Parameter(file, parameterNodes[i], classNode->m_enclosing, 0);
	}
	generateCode_Token(file, methodNode->m_rightParenthesis, 0);
	writeStringToFile("\n", file);
	char buf[512];
	writeStringToFile("{\n", file, indentation);

	if ("New" == methodNode->m_name->m_str)
	{
		if (classNode->isValueType())
		{
			sprintf_s(buf, "return paf_new %s(", typeName.c_str());
		}
		else
		{
			if (classNode->m_category && classNode->m_category->m_str == "atomic_reference_object")
			{
				sprintf_s(buf, "return paf_new ::pafcore::AtomicRefCountImpl<%s>(", typeName.c_str());
			}
			else
			{
				sprintf_s(buf, "return paf_new ::pafcore::RefCountImpl<%s>(", typeName.c_str());
			}
		}
	}
	//else if ("NewARC" == methodNode->m_name->m_str)
	//{
	//	sprintf_s(buf, "return paf_new ::pafcore::AtomicRefCountImpl<%s>(", typeName.c_str());
	//}
	else
	{
		assert("NewArray" == methodNode->m_name->m_str);
		assert(classNode->isValueType());
		sprintf_s(buf, "return paf_new_array<%s>(", typeName.c_str());
	}

	writeStringToFile(buf, file, indentation + 1);
	for (size_t i = 0; i < parameterCount; ++i)
	{
		if (i != 0)
		{
			writeStringToFile(", ", file);
		}
		writeStringToFile(parameterNodes[i]->m_name->m_str.c_str(), file);
	}
	writeStringToFile(");\n", file);
	
	writeStringToFile("}\n\n", file, indentation);
}