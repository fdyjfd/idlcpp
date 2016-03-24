#include "HeaderFileGenerator.h"
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
#include "GetterSetterNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "ParameterNode.h"
#include "TypeAliasNode.h"
#include <assert.h>


void generateCode_Token(FILE* file, TokenNode* tokenNode, int indentation);
void generateCode_Identify(FILE* file, IdentifyNode* identifyNode, int indentation);
void generateCode_TypeName(FILE* file, TypeNameNode* typeNameNode, ScopeNode* scopeNode, int indentation);
void generateCode_Parameter(FILE* file, ParameterNode* parameterNode, MethodNode* methodNode, int indentation);

void generateCode_Token(FILE* file, TokenNode* tokenNode, int indentation)
{
	char lastChar = g_sourceFileManager.outputEmbededCodes(file, tokenNode);

	if(tokenNode->m_lineNo != g_sourceFileManager.m_currentLineNo)
	{

	}

	if(indentation > 0)
	{
		writeStringToFile("", 0, file, indentation);
	}
	if(tokenNode->m_nodeType < 256)
	{
		char buf[3];
		if(':' == tokenNode->m_nodeType)
		{
			buf[0] = ' ';
			buf[1] = ':';
			buf[2] = ' ';
			writeStringToFile(buf, 3, file);
		}
		else
		{
			buf[0] = tokenNode->m_nodeType;
			buf[1] = ' ';
			writeStringToFile(buf, 1, file);
		}
	}
	else
	{
		assert(snt_keyword_begin_output < tokenNode->m_nodeType && tokenNode->m_nodeType < snt_keyword_end_output);
		const char* str = g_keywordTokens[tokenNode->m_nodeType - snt_keyword_begin_output - 1];
		if(0 == indentation && isNumAlpha_(lastChar))
		{
			writeStringToFile(g_strSpaces, 1, file);
		}
		writeStringToFile(str, file);
	}
}

void generateCode_Identify(FILE* file, IdentifyNode* identifyNode, int indentation)
{
	char lastChar = g_sourceFileManager.outputEmbededCodes(file, identifyNode);
	if(indentation > 0)
	{
		writeStringToFile("", 0, file, indentation);
		//fwrite(g_tabs, indentation, 1, file);
	}
	else if(isNumAlpha_(lastChar))
	{
		writeStringToFile(g_strSpaces, 1, file);
	}
	writeStringToFile(identifyNode->m_str.c_str(), identifyNode->m_str.length(), file);
	//fwrite(identifyNode->m_str.c_str(), identifyNode->m_str.length(), 1, file);
};


void generateCode_TypeName(FILE* file, TypeNameNode* typeNameNode, ScopeNode* scopeNode, int indentation)
{
	if(typeNameNode->m_keyword)
	{
		//internal primitive
		typeNameNode->m_keyword->outputEmbededCodes(file, 0 == indentation);
	}
	if(typeNameNode->m_scopeList)
	{
		typeNameNode->m_scopeList->m_name->outputEmbededCodes(file, 0 == indentation);
	}
	std::string typeName;
	typeNameNode->getRelativeName(typeName, scopeNode, 0);
	writeStringToFile(typeName.c_str(), file, indentation);
}

void generateCode_Parameter(FILE* file, ParameterNode* parameterNode, MethodNode* methodNode, int indentation)
{
	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	if(parameterNode->m_constant)
	{
		generateCode_Token(file, parameterNode->m_constant, 0);
	}
	generateCode_TypeName(file, parameterNode->m_type, methodNode->m_enclosing, 0);
	if(0 != parameterNode->m_out)
	{
		generateCode_Token(file, parameterNode->m_out, 0);
	}
	if(0 != parameterNode->m_passing)
	{
		generateCode_Token(file, parameterNode->m_passing, 0);
	}
	writeStringToFile(g_strSpaces, 1, file);
	generateCode_Identify(file, parameterNode->m_name, 0);
};


void HeaderFileGenerator::generateCode(FILE* dstFile, SourceFile* sourceFile)
{
	generateCode_Program(dstFile, sourceFile);
}

void HeaderFileGenerator::generateCode_Program(FILE* file, SourceFile* sourceFile)
{
	writeStringToFile("#pragma once\n\n", file);
	g_sourceFileManager.outputUsedTypes(file, sourceFile);

	generateCode_Namespace(file, sourceFile->m_syntaxTree, -1);

	g_sourceFileManager.outputEmbededCodes(file, 0);
}

void HeaderFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
	if(!namespaceNode->isGlobalNamespace())
	{
		generateCode_Token(file, namespaceNode->m_keyword, indentation);
		generateCode_Identify(file, namespaceNode->m_name, 0);
		//writeStringToFile("\n", file);
		generateCode_Token(file, namespaceNode->m_leftBrace, indentation);
		//writeStringToFile("\n", file);
	}
	std::vector<MemberNode*> memberNodes;
	namespaceNode->m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_enum:
			generateCode_Enum(file, static_cast<EnumNode*>(memberNode), indentation + 1);
			break;
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(memberNode), indentation + 1);
			break;
		case snt_template_class_instance:
			break;
		case snt_type_alias:
			generateCode_TypeAlias(file, static_cast<TypeAliasNode*>(memberNode), indentation + 1);
			break;
		case snt_namespace:
			generateCode_Namespace(file, static_cast<NamespaceNode*>(memberNode), indentation + 1);
			break;
		default:
			assert(false);
		}
	}

	if(!namespaceNode->isGlobalNamespace())
	{
		//writeStringToFile("\n", file);
		generateCode_Token(file, namespaceNode->m_rightBrace, indentation);
		//writeStringToFile(";\n\n", file);
	}
}


void HeaderFileGenerator::generateCode_TypeAlias(FILE* file, TypeAliasNode* typeAliasNode, int indentation)
{
	if(0 != typeAliasNode->m_typeName)
	{
		generateCode_Token(file, typeAliasNode->m_keyword, indentation);
		std::string relativeName;
		typeAliasNode->m_typeName->getRelativeName(relativeName, typeAliasNode->m_enclosing, 0);
		//generateCode_TypeName(file, typeAliasNode->m_typeName, typeAliasNode->m_enclosing, 0);
		writeStringToFile(relativeName.c_str(), file);
		writeStringToFile(g_strSpaces, 1, file);
		generateCode_Identify(file, typeAliasNode->m_name, 0);
		writeStringToFile(";", 1, file);
		//generateCode_Token(file, typeAliasNode->m_semicolon, 0);
	}
}

void HeaderFileGenerator::generateCode_Enum(FILE* file, EnumNode* enumNode, int indentation)
{
	generateCode_Token(file, enumNode->m_keyword, indentation);
	generateCode_Identify(file, enumNode->m_name, 0);
	//writeStringToFile("\n", file);
	generateCode_Token(file, enumNode->m_leftBrace, indentation);
	//writeStringToFile("\n", file);

	std::vector<std::pair<TokenNode*, IdentifyNode*>> identifyNodes;
	enumNode->m_enumeratorList->collectIdentifyNodes(identifyNodes);
	size_t itemCount = identifyNodes.size();	
	for(size_t i = 0; i < itemCount; ++i)
	{
		if(0 != identifyNodes[i].first)
		{
			generateCode_Token(file, identifyNodes[i].first, 0);
			//writeStringToFile("\n", file);
		}
		generateCode_Identify(file, identifyNodes[i].second, indentation + 1);
	}
	//writeStringToFile("\n", file);
	generateCode_Token(file, enumNode->m_rightBrace, indentation);
	generateCode_Token(file, enumNode->m_semicolon, 0);
	//writeStringToFile(";\n\n", file);
}

void HeaderFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, int indentation)
{
	if(classNode->m_templateParameters)
	{
		generateCode_Token(file, classNode->m_templateParameters->m_keyword, indentation);
		generateCode_Token(file, classNode->m_templateParameters->m_leftBracket, 0);
		std::vector<std::pair<TokenNode*, TemplateParameterNode*>> parameterNodes;
		classNode->m_templateParameters->collectParameterNodes(parameterNodes);

		size_t count = parameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(parameterNodes[i].first)
			{
				generateCode_Token(file, parameterNodes[i].first, 0);
			}
			generateCode_Token(file, parameterNodes[i].second->m_keyword, 0);
			writeStringToFile(g_strSpaces, 1, file);
			generateCode_Identify(file, parameterNodes[i].second->m_name, 0);
		}
		generateCode_Token(file, classNode->m_templateParameters->m_rightBracket, 0);
	}

	generateCode_Token(file, classNode->m_keyword, indentation);
	generateCode_Identify(file, classNode->m_name, 0);
	if(classNode->m_baseList)
	{
		assert(0 != classNode->m_colon);
		generateCode_Token(file, classNode->m_colon, 0);
		std::vector<std::pair<TokenNode*, TypeNameNode*>> typeNameNodes;
		classNode->m_baseList->collectTypeNameNodes(typeNameNodes);
		size_t baseCount = typeNameNodes.size();
		for(size_t i = 0; i < baseCount; ++i)
		{
			if(typeNameNodes[i].first)
			{
				generateCode_Token(file, typeNameNodes[i].first, 0);
			}
			writeStringToFile("public ", file);
			generateCode_TypeName(file, typeNameNodes[i].second, classNode->m_enclosing, 0);
		}
	}

	generateCode_Token(file, classNode->m_leftBrace, indentation);
	writeStringToFile("\n", file);
	writeStringToFile("public:\n", file, indentation);
	if (!classNode->isValueType())
	{
		writeStringToFile("virtual ::pafcore::Type* getType();\n", file, indentation + 1);
	}
	bool generateCode = true;
	std::vector<MemberNode*> memberNodes;
	classNode->m_memberList->collectMemberNodes(memberNodes);
	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		if(snt_filter == memberNode->m_nodeType)
		{
			generateCode = static_cast<FilterNode*>(memberNode)->m_native;			
			continue;
		}
		switch(memberNode->m_nodeType)
		{
		case snt_field:
			generateCode_Field(generateCode ? file : 0, static_cast<FieldNode*>(memberNode), indentation + 1);
			break;
		case snt_property:
			generateCode_Property(generateCode ? file : 0, static_cast<PropertyNode*>(memberNode), indentation + 1);
			break;
		case snt_method:
			generateCode_Method(generateCode ? file : 0, static_cast<MethodNode*>(memberNode), indentation + 1);
			break;
		case snt_enum:
			generateCode_Enum(generateCode ? file : 0, static_cast<EnumNode*>(memberNode), indentation + 1);
			break;
		case snt_class:
			generateCode_Class(generateCode ? file : 0, static_cast<ClassNode*>(memberNode), indentation + 1);
			break;
		default:
			assert(false);
		}
	}
	if(!classNode->m_additionalMethods.empty())
	{
		bool backup = g_sourceFileManager.m_outputLineDirective;
		g_sourceFileManager.m_outputLineDirective = false;
		writeStringToFile("\n", file, 0);
		writeStringToFile("public:\n", file, indentation);
		size_t count = classNode->m_additionalMethods.size();
		for(size_t i = 0; i < count; ++i)
		{
			generateCode_AdditionalMethod(file, classNode->m_additionalMethods[i], indentation + 1);
		}
		g_sourceFileManager.m_outputLineDirective = backup;
	}
	generateCode_Token(file, classNode->m_rightBrace, indentation);
	generateCode_Token(file, classNode->m_semicolon, 0);
}


void HeaderFileGenerator::generateCode_Field(FILE* file, FieldNode* fieldNode, int indentation)
{
	ClassNode* classNode = static_cast<ClassNode*>(fieldNode->m_enclosing);
	if(fieldNode->m_static)
	{
		generateCode_Token(file, fieldNode->m_static, indentation);
		indentation = 0;
	}
	if(fieldNode->m_constant)
	{
		generateCode_Token(file, fieldNode->m_constant, indentation);
		indentation = 0;
	}
	generateCode_TypeName(file, fieldNode->m_type, fieldNode->m_enclosing, indentation);

	writeStringToFile(g_strSpaces, 1, file);

	generateCode_Identify(file, fieldNode->m_name, 0);
	if(fieldNode->m_leftBracket)
	{
		generateCode_Token(file, fieldNode->m_leftBracket, 0);
	}
	if(fieldNode->m_rightBracket)
	{
		generateCode_Token(file, fieldNode->m_rightBracket, 0);
	}
	generateCode_Token(file, fieldNode->m_semicolon, 0);
}

void HeaderFileGenerator::generateCode_Property_Get(FILE* file, PropertyNode* propertyNode, int indentation)
{
	ClassNode* classNode = static_cast<ClassNode*>(propertyNode->m_enclosing);
	if(propertyNode->m_modifier)
	{
		generateCode_Token(file, propertyNode->m_modifier, indentation);
		indentation = 0;
	}
	if(0 != propertyNode->m_get->m_constant)
	{
		generateCode_Token(file, propertyNode->m_get->m_constant, indentation);
		indentation = 0;
	}
	generateCode_TypeName(file, propertyNode->m_get->m_type, propertyNode->m_enclosing, indentation);
	if(0 != propertyNode->m_get->m_passing)
	{
		generateCode_Token(file, propertyNode->m_get->m_passing, 0);
	}
	writeStringToFile(g_strSpaces, 1, file);
	generateCode_Token(file, propertyNode->m_get->m_keyword, 0);
	generateCode_Identify(file, propertyNode->m_name, 0);
	if(propertyNode->m_modifier && snt_keyword_abstract == propertyNode->m_modifier->m_nodeType)
	{
		writeStringToFile("() = 0;", file);	
	}
	else
	{
		writeStringToFile("();", file);	
	}
}

void HeaderFileGenerator::generateCode_Property_Set(FILE* file, PropertyNode* propertyNode, int indentation)
{
	ClassNode* classNode = static_cast<ClassNode*>(propertyNode->m_enclosing);

	if(propertyNode->m_modifier)
	{
		generateCode_Token(file, propertyNode->m_modifier, indentation);
		indentation = 0;
	}
	generateCode_Token(file, propertyNode->m_set->m_keyword, indentation);
	generateCode_Identify(file, propertyNode->m_name, 0);
	writeStringToFile("( ", file);
	if(0 != propertyNode->m_set->m_constant)
	{
		generateCode_Token(file, propertyNode->m_set->m_constant, 0);
	}
	generateCode_TypeName(file, propertyNode->m_set->m_type, propertyNode->m_enclosing, 0);
	if(0 != propertyNode->m_set->m_passing)
	{
		generateCode_Token(file, propertyNode->m_set->m_passing, 0);
	}
	if(propertyNode->m_modifier && snt_keyword_abstract == propertyNode->m_modifier->m_nodeType)
	{
		writeStringToFile(") = 0;", file);	
	}
	else
	{
		writeStringToFile(");", file);	
	}
}

void HeaderFileGenerator::generateCode_Property(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if(0 != propertyNode->m_get && 0 != propertyNode->m_set && propertyNode->m_get->m_keyword->m_tokenNo > propertyNode->m_set->m_keyword->m_tokenNo)
	{
		generateCode_Property_Set(file, propertyNode, indentation);
		writeStringToFile("\n", file);	
		generateCode_Property_Get(file, propertyNode, indentation);
	}
	else
	{
		if(0 != propertyNode->m_get)
		{
			generateCode_Property_Get(file, propertyNode, indentation);
			if(0 != propertyNode->m_set)
			{
				writeStringToFile("\n", file);
			}
		}
		if(0 != propertyNode->m_set)
		{
			generateCode_Property_Set(file, propertyNode, indentation);
		}
	}
};

void HeaderFileGenerator::generateCode_Method(FILE* file, MethodNode* methodNode, int indentation)
{
	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	if(methodNode->m_modifier)
	{
		generateCode_Token(file, methodNode->m_modifier, indentation);
		indentation = 0;
	}
	if(0 != methodNode->m_resultConst)
	{
		generateCode_Token(file, methodNode->m_resultConst, indentation);
		indentation = 0;
	}
	if(0 != methodNode->m_result)
	{
		generateCode_TypeName(file, methodNode->m_result, methodNode->m_enclosing, indentation);
		indentation = 0;
		if(0 != methodNode->m_passing)
		{
			generateCode_Token(file, methodNode->m_passing, indentation);
			indentation = 0;
		}
		writeStringToFile(g_strSpaces, 1, file);
	}
	generateCode_Identify(file, methodNode->m_name, indentation);
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
	if(methodNode->m_modifier && snt_keyword_abstract == methodNode->m_modifier->m_nodeType)
	{
		writeStringToFile(" = 0 ", file);
	}
	if(methodNode->m_constant)
	{
		generateCode_Token(file, methodNode->m_constant, 0);
	}
	generateCode_Token(file, methodNode->m_semicolon, 0);
}

void HeaderFileGenerator::generateCode_AdditionalMethod(FILE* file, MethodNode* methodNode, int indentation)
{
	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	const char* typeName = classNode->m_name->m_str.c_str();
	assert(0 != methodNode->m_modifier);
	generateCode_Token(file, methodNode->m_modifier, indentation);
	assert(0 != methodNode->m_result);

	generateCode_TypeName(file, methodNode->m_result, methodNode->m_enclosing, 0);
	if(0 != methodNode->m_passing)
	{
		generateCode_Token(file, methodNode->m_passing, 0);
	}
	writeStringToFile(g_strSpaces, 1, file);

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
	writeStringToFile(";\n", file);
}

void CalcTypeNameInHeaderFile(std::string& typeName, TypeNameNode* typeNameNode, ScopeNode* scopeNode)
{
	typeNameNode->getRelativeName(typeName, scopeNode, 0);
	if(typeNameNode->isTemplateForm())
	{
		assert(typeNameNode->m_typeInfo->m_typeNode->isTemplateClass());
		std::vector<TypeNameNode*> paramNodes;
		typeNameNode->m_parameterList->collectTypeNameNodes(paramNodes);
		size_t count = paramNodes.size();
		typeName += '<';
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				typeName += ',';
			}
			TypeNameNode* paramNode = paramNodes[i];
			std::string paramName;
			CalcTypeNameInHeaderFile(paramName, paramNode, scopeNode);
			typeName.append(paramName);
		}
		typeName += '>';
	}
}
