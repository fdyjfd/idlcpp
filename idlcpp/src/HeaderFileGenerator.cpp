#include "HeaderFileGenerator.h"
#include "Utility.h"
#include "SourceFile.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "ScopeNameListNode.h"
#include "ScopeNameNode.h"
#include "MemberListNode.h"
#include "EnumeratorNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "DelegateNode.h"
#include "TemplateParametersNode.h"
#include "TemplateParameterListNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "FieldNode.h"
#include "GetterSetterNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "ParameterNode.h"
#include "ParameterListNode.h"
#include "OperatorNode.h"
#include "TypedefNode.h"
#include "Compiler.h"
#include <assert.h>

void generateCode_Token(FILE* file, TokenNode* tokenNode, int indentation)
{
	g_compiler.outputEmbededCodes(file, tokenNode);

	if(indentation > 0)
	{
		writeStringToFile("", 0, file, indentation);
	}
	if(tokenNode->m_nodeType < 256)
	{
		char ch = tokenNode->m_nodeType;
		if ('+' == ch || '-' == ch)
		{
			ch = '*';
		}
		writeStringToFile(&ch, 1, file);
	}
	else
	{
		assert(snt_begin_output < tokenNode->m_nodeType && tokenNode->m_nodeType < snt_end_output);
		const char* str = g_keywordTokens[tokenNode->m_nodeType - snt_begin_output - 1];
		if (isNumAlpha_(GetLastWrittenChar()))
		{
			writeSpaceToFile(file);
		}
		writeStringToFile(str, file);
	}
}

void generateCode_TokenForOperator(FILE* file, TokenNode* tokenNode, int indentation)
{
	g_compiler.outputEmbededCodes(file, tokenNode);

	if (indentation > 0)
	{
		writeStringToFile("", 0, file, indentation);
	}
	if (tokenNode->m_nodeType < 256)
	{
		char ch = tokenNode->m_nodeType;
		writeStringToFile(&ch, 1, file);
	}
	else
	{
		assert(snt_begin_output < tokenNode->m_nodeType && tokenNode->m_nodeType < snt_end_output);
		const char* str = g_keywordTokens[tokenNode->m_nodeType - snt_begin_output - 1];
		if (isNumAlpha_(GetLastWrittenChar()))
		{
			writeSpaceToFile(file);
		}
		writeStringToFile(str, file);
	}
}


void generateCode_Identify(FILE* file, IdentifyNode* identifyNode, int indentation, bool addSpace = true)
{
	g_compiler.outputEmbededCodes(file, identifyNode);
	if(indentation > 0)
	{
		writeStringToFile("", 0, file, indentation);
	}
	if(addSpace && isNumAlpha_(GetLastWrittenChar()))
	{
		writeSpaceToFile(file);
	}
	writeStringToFile(identifyNode->m_str.c_str(), identifyNode->m_str.length(), file);
};

//void generateCode_Name(FILE* file, IdentifyNode* name, IdentifyNode* nativeName, int indentation)
//{
//	char lastChar = g_compiler.outputEmbededCodes(file, name);
//	if (indentation > 0)
//	{
//		writeStringToFile("", 0, file, indentation);
//	}
//	else if (isNumAlpha_(lastChar))
//	{
//		writeSpaceToFile(file);
//	}
//	if (nativeName)
//	{
//		writeStringToFile(nativeName->m_str.c_str(), nativeName->m_str.length(), file);
//	}
//	else
//	{
//		writeStringToFile(name->m_str.c_str(), name->m_str.length(), file);
//	}
//}


void generateCode_TypeName(FILE* file, TypeNameNode* typeNameNode, ScopeNode* scopeNode, bool addKeyword, int indentation)
{
	if(typeNameNode->m_keyword)
	{
		//internal primitive
		typeNameNode->m_keyword->outputEmbededCodes(file, 0 == indentation);
	}
	if(typeNameNode->m_scopeNameList)
	{
		typeNameNode->m_scopeNameList->m_scopeName->m_name->outputEmbededCodes(file, 0 == indentation);
	}
	if (addKeyword && typeNameNode->underTemplateParameter())
	{
		writeStringToFile("typename ", file, indentation);
		indentation = 0;
	}
	std::string typeName;
	typeNameNode->getRelativeName(typeName, scopeNode);
	writeStringToFile(typeName.c_str(), file, indentation);
}

void generateCode_Parameter(FILE* file, ParameterNode* parameterNode, ScopeNode* scopeNode)
{
	if(parameterNode->m_constant)
	{
		generateCode_Token(file, parameterNode->m_constant, 0);
	}
	generateCode_TypeName(file, parameterNode->m_typeName, scopeNode, true, 0);
	if(0 != parameterNode->m_passing)
	{
		generateCode_Token(file, parameterNode->m_passing, 0);
	}
	if(0 != parameterNode->m_out)
	{
		generateCode_Token(file, parameterNode->m_out, 0);
	}
	writeSpaceToFile(file);
	generateCode_Identify(file, parameterNode->m_name, 0);
};

void generateCode_ParameterList(FILE* file, ParameterListNode* parameterListNode, ScopeNode* scopeNode)
{
	std::vector<std::pair<TokenNode*, ParameterNode*>> parameterNodes;
	parameterListNode->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for (size_t i = 0; i < parameterCount; ++i)
	{
		if (parameterNodes[i].first)
		{
			generateCode_Token(file, parameterNodes[i].first, 0);
		}
		generateCode_Parameter(file, parameterNodes[i].second, scopeNode);
	}
}



void HeaderFileGenerator::generateCode(FILE* dstFile, SourceFile* sourceFile)
{
	generateCode_Program(dstFile, sourceFile);
}

void HeaderFileGenerator::generateCode_Program(FILE* file, SourceFile* sourceFile)
{
	writeStringToFile("#pragma once\n\n", file);
	g_compiler.outputUsedTypes(file, sourceFile);
	writeStringToFile("namespace pafcore{ class ClassType; }\n", file);
	if (sourceFile->m_hasArrayProperty || sourceFile->m_hasListProperty || sourceFile->m_hasMapProperty)
	{
		writeStringToFile("namespace pafcore{ class Iterator; }\n", file);
	}

	generateCode_Namespace(file, sourceFile->m_syntaxTree, -1);

	g_compiler.outputEmbededCodes(file, 0);
}

void HeaderFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
	if (namespaceNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, namespaceNode->m_filterNode);
		file = 0;
	}

	if(!namespaceNode->isGlobalNamespace())
	{
		generateCode_Token(file, namespaceNode->m_keyword, indentation);
		generateCode_Identify(file, namespaceNode->m_name, 0);
		generateCode_Token(file, namespaceNode->m_leftBrace, indentation);
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
		case snt_delegate:
			generateCode_Delegate(file, static_cast<DelegateNode*>(memberNode), indentation + 1);
			break;
		case snt_template_class_instance:
			break;
		case snt_typedef:
			generateCode_Typedef(file, static_cast<TypedefNode*>(memberNode), indentation + 1);
			break;
		case snt_namespace:
			generateCode_Namespace(file, static_cast<NamespaceNode*>(memberNode), indentation + 1);
			break;
		case snt_type_declaration:
			break;
		default:
			assert(false);
		}
	}

	if(!namespaceNode->isGlobalNamespace())
	{
		generateCode_Token(file, namespaceNode->m_rightBrace, indentation);
	}
}


void HeaderFileGenerator::generateCode_Typedef(FILE* file, TypedefNode* typedefNode, int indentation)
{
	if (typedefNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, typedefNode->m_filterNode);
		file = 0;
	}
	if(0 != typedefNode->m_typeName)
	{
		generateCode_Token(file, typedefNode->m_keyword, indentation);	
		generateCode_TypeName(file, typedefNode->m_typeName, typedefNode->m_enclosing, true, 0);
		writeSpaceToFile(file);
		generateCode_Identify(file, typedefNode->m_name, 0);
		writeStringToFile(";", 1, file);
	}
}

void HeaderFileGenerator::generateCode_Enum(FILE* file, EnumNode* enumNode, int indentation)
{
	if (enumNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, enumNode->m_filterNode);
		file = 0;
	}
	else if (enumNode->m_nativeName)
	{
		g_compiler.outputEmbededCodes(file, enumNode->m_keyword);
		file = 0;
	}

	generateCode_Token(file, enumNode->m_keyword, indentation);
	if (enumNode->m_keyword2)
	{
		generateCode_Token(file, enumNode->m_keyword2, 0);
	}
	generateCode_Identify(file, enumNode->m_name, 0);
	generateCode_Token(file, enumNode->m_leftBrace, indentation);

	std::vector<std::pair<TokenNode*, EnumeratorNode*>> enumeratorNodes;
	enumNode->m_enumeratorList->collectEnumeratorNodes(enumeratorNodes);
	size_t itemCount = enumeratorNodes.size();
	for(size_t i = 0; i < itemCount; ++i)
	{
		if(0 != enumeratorNodes[i].first)
		{
			generateCode_Token(file, enumeratorNodes[i].first, 0);
		}
		generateCode_Identify(file, enumeratorNodes[i].second->m_name, indentation + 1);
	}
	generateCode_Token(file, enumNode->m_rightBrace, indentation);
	generateCode_Token(file, enumNode->m_semicolon, 0);
}

void HeaderFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, int indentation)
{
	if (classNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, classNode->m_filterNode);
		file = 0;
	}
	else if (classNode->m_nativeName)
	{
		g_compiler.outputEmbededCodes(file, classNode->m_keyword);
		file = 0;
	}

	if(classNode->m_templateParametersNode)
	{
		generateCode_Token(file, classNode->m_templateParametersNode->m_keyword, indentation);
		generateCode_Token(file, classNode->m_templateParametersNode->m_leftBracket, 0);
		std::vector<std::pair<TokenNode*, IdentifyNode*>> parameterNodes;
		classNode->m_templateParametersNode->collectParameterNodes(parameterNodes);

		size_t count = parameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(parameterNodes[i].first)
			{
				generateCode_Token(file, parameterNodes[i].first, 0);
			}
			writeStringToFile("typename ", file);
			generateCode_Identify(file, parameterNodes[i].second, 0);
		}
		generateCode_Token(file, classNode->m_templateParametersNode->m_rightBracket, 0);
	}

	generateCode_Token(file, classNode->m_keyword, indentation);
	generateCode_Identify(file, classNode->m_name, 0);


	if(classNode->m_baseList)
	{
		std::vector<std::pair<TokenNode*, TypeNameNode*>> typeNameNodes;
		classNode->m_baseList->collectTypeNameNodesNotNoCode(typeNameNodes);
		size_t baseCount = typeNameNodes.size();
		if (baseCount)
		{
			assert(0 != classNode->m_colon);
			writeSpaceToFile(file);
			generateCode_Token(file, classNode->m_colon, 0);
			writeSpaceToFile(file);
			for(size_t i = 0; i < baseCount; ++i)
			{
				if(typeNameNodes[i].first && 0 != i)
				{
					generateCode_Token(file, typeNameNodes[i].first, 0);
				}
				writeStringToFile("public ", file);
				generateCode_TypeName(file, typeNameNodes[i].second, classNode->m_enclosing, false, 0);
			}
		}
	}

	generateCode_Token(file, classNode->m_leftBrace, indentation);
	writeStringToFile("\n", file);
	writeStringToFile("public:\n", file, indentation);

	std::vector<MemberNode*> memberNodes;
	classNode->m_memberList->collectMemberNodes(memberNodes);

	auto it = classNode->m_additionalMethods.begin();
	auto end = classNode->m_additionalMethods.end();
	for (; it != end; ++it)
	{
		MethodNode* methodNode = *it;
		if (!methodNode->isNoCode())
		{
			memberNodes.push_back(methodNode);
		}
	}

	size_t memberCount = memberNodes.size();
	for (size_t i = 0; i < memberCount; ++i)
	{
		char buf[4096];
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_class:
		{
			ClassNode* nestedClassNode = static_cast<ClassNode*>(memberNode);
			if (0 == nestedClassNode->m_nativeName)
			{
				sprintf_s(buf, "%s%s;\n", g_keywordTokens[nestedClassNode->m_keyword->m_nodeType - snt_begin_output - 1],
					nestedClassNode->m_name->m_str.c_str());
				writeStringToFile(buf, file, indentation + 1);
			}
		}
		break;
		case snt_enum:
		{
			EnumNode* nestedEnumNode = static_cast<EnumNode*>(memberNode);
			if (0 == nestedEnumNode->m_nativeName)
			{
				sprintf_s(buf, "%s%s%s;\n", g_keywordTokens[nestedEnumNode->m_keyword->m_nodeType - snt_begin_output - 1],
					nestedEnumNode->m_keyword2 ? "class " : "",
					nestedEnumNode->m_name->m_str.c_str());
				writeStringToFile(buf, file, indentation + 1);
			}
		}
		break;
		}
	}
	if (!classNode->isNoMeta())
	{
		writeStringToFile("static ::pafcore::ClassType* GetType();\n", file, indentation + 1);
		if (!classNode->isValueType())
		{
			writeStringToFile("virtual ::pafcore::ClassType* getType();\n", file, indentation + 1);
			writeStringToFile("virtual size_t getAddress();\n", file, indentation + 1);
		}
	}
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch(memberNode->m_nodeType)
		{
		case snt_field:
			generateCode_Field(file, static_cast<FieldNode*>(memberNode), indentation + 1);
			break;
		case snt_property:
			generateCode_Property(file, static_cast<PropertyNode*>(memberNode), indentation + 1);
			break;
		case snt_method:
			generateCode_Method(file, static_cast<MethodNode*>(memberNode), indentation + 1);
			break;
		case snt_operator:
			generateCode_Operator(file, static_cast<OperatorNode*>(memberNode), indentation + 1);
			break;
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(memberNode), indentation + 1);
			break;
		case snt_delegate:
			generateCode_Delegate(file, static_cast<DelegateNode*>(memberNode), indentation + 1);
			break;
		case snt_enum:
			generateCode_Enum(file, static_cast<EnumNode*>(memberNode), indentation + 1);
			break;
		case snt_typedef:
			generateCode_Typedef(file, static_cast<TypedefNode*>(memberNode), indentation + 1);
			break;
		case snt_type_declaration:
			break;
		default:
			assert(false);
		}
	}

	generateCode_Token(file, classNode->m_rightBrace, indentation);
	generateCode_Token(file, classNode->m_semicolon, 0);
}

void HeaderFileGenerator::generateCode_Delegate(FILE* file, DelegateNode* delegateNode, int indentation)
{
	if (delegateNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, delegateNode->m_filterNode);
		file = 0;
	}
	generateCode_Token(file, delegateNode->m_keyword, indentation);
	generateCode_Identify(file, delegateNode->m_name, 0);
	
	writeStringToFile(" : public ::pafcore::Delegate\n", file);
	writeStringToFile("{\n", file, indentation);
	writeStringToFile("public:\n", file, indentation);
	
	int methodIndentation = indentation + 1;

	generateCode_Identify(file, delegateNode->m_name, methodIndentation);
	writeStringToFile("() = default;\n", file, 0);
	generateCode_Identify(file, delegateNode->m_name, methodIndentation);
	writeStringToFile("(const ", file, 0);
	generateCode_Identify(file, delegateNode->m_name, 0);
	writeStringToFile("&) = delete;\n", file, 0);

	if (0 != delegateNode->m_resultConst)
	{
		generateCode_Token(file, delegateNode->m_resultConst, methodIndentation);
		methodIndentation = 0;
	}
	if (0 != delegateNode->m_resultTypeName)
	{
		generateCode_TypeName(file, delegateNode->m_resultTypeName, delegateNode->m_enclosing, true, methodIndentation);
		methodIndentation = 0;
		if (0 != delegateNode->m_passing)
		{
			generateCode_Token(file, delegateNode->m_passing, methodIndentation);
			methodIndentation = 0;
		}
		writeSpaceToFile(file);
	}
	writeStringToFile("invoke", file, methodIndentation);
	generateCode_Token(file, delegateNode->m_leftParenthesis, 0);
	generateCode_ParameterList(file, delegateNode->m_parameterList, delegateNode->m_enclosing);
	generateCode_Token(file, delegateNode->m_rightParenthesis, 0);
	generateCode_Token(file, delegateNode->m_semicolon, 0);
	writeStringToFile("\n", file);

	writeStringToFile("typedef ", file, indentation + 1);
	if (0 != delegateNode->m_resultConst)
	{
		generateCode_Token(file, delegateNode->m_resultConst, 0);
	}
	if (0 != delegateNode->m_resultTypeName)
	{
		generateCode_TypeName(file, delegateNode->m_resultTypeName, delegateNode->m_enclosing, true, 0);
		if (0 != delegateNode->m_passing)
		{
			generateCode_Token(file, delegateNode->m_passing, 0);
		}
		writeSpaceToFile(file);
	}
	writeStringToFile("(*CallBackFunction)(void* userData, ", file, 0);
	generateCode_ParameterList(file, delegateNode->m_parameterList, delegateNode->m_enclosing);
	writeStringToFile(");\n", file);
	writeStringToFile("::pafcore::FunctionCallBack* addFunction(CallBackFunction function, void* userData)\n", file, indentation + 1);
	writeStringToFile("{return Delegate::addFunction(function, userData);}\n", file, indentation + 1);
	writeStringToFile("};\n", file, indentation);
}

void HeaderFileGenerator::generateCode_Field(FILE* file, FieldNode* fieldNode, int indentation)
{
	if (fieldNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, fieldNode->m_filterNode);
		file = 0;
	}
	else if (fieldNode->m_nativeName)
	{
		TokenNode* firstToken;
		if (0 != fieldNode->m_static)
		{
			firstToken = fieldNode->m_static;
		}
		else if (0 != fieldNode->m_constant)
		{
			firstToken = fieldNode->m_constant;
		}
		else
		{
			if (fieldNode->m_typeName->m_keyword)
			{
				firstToken = fieldNode->m_typeName->m_keyword;
			}
			else
			{
				firstToken = fieldNode->m_typeName->m_scopeNameList->m_scopeName->m_name;
			}
		}
		g_compiler.outputEmbededCodes(file, firstToken);
		file = 0;
	}
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
	generateCode_TypeName(file, fieldNode->m_typeName, fieldNode->m_enclosing, true, indentation);
	if (fieldNode->m_pointer)
	{
		generateCode_Token(file, fieldNode->m_pointer, 0);
	}
	writeSpaceToFile(file);
	//generateCode_Name(file, fieldNode->m_name, fieldNode->m_nativeName, 0);
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
	if (propertyNode->m_get->m_nativeName)
	{
		TokenNode* firstToken;
		if (0 != propertyNode->m_modifier)
		{
			firstToken = propertyNode->m_modifier;
		}
		else
		{
			if (propertyNode->m_typeName->m_keyword)
			{
				firstToken = propertyNode->m_typeName->m_keyword;
			}
			else
			{
				firstToken = propertyNode->m_typeName->m_scopeNameList->m_scopeName->m_name;
			}
		}
		g_compiler.outputEmbededCodes(file, firstToken);
		file = 0;
	}

	ClassNode* classNode = static_cast<ClassNode*>(propertyNode->m_enclosing);
	if(propertyNode->m_modifier)
	{
		generateCode_Token(file, propertyNode->m_modifier, indentation);
		indentation = 0;
	}
	generateCode_TypeName(file, propertyNode->m_typeName, propertyNode->m_enclosing, true, indentation);
	if(0 != propertyNode->m_passing)
	{
		generateCode_Token(file, propertyNode->m_passing, 0);
	}
	writeSpaceToFile(file);
	generateCode_Token(file, propertyNode->m_get->m_keyword, 0);
	generateCode_Identify(file, propertyNode->m_name, 0, false);

	writeStringToFile("(", file);

	if (propertyNode->isFixedArray() || propertyNode->isDynamicArray() || propertyNode->isList())
	{
		writeStringToFile("size_t", file);
	}
	else if (propertyNode->isMap())
	{
		generateCode_TypeName(file, propertyNode->m_keyTypeName, propertyNode->m_enclosing, true, 0);
		if (0 != propertyNode->m_keyPassing)
		{
			generateCode_Token(file, propertyNode->m_keyPassing, 0);
		}
	}
	if (propertyNode->isStatic())
	{
		writeStringToFile(");", file);
	}
	else
	{
		writeStringToFile(") const;", file);
	}
}

void HeaderFileGenerator::generateCode_Property_Set(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->m_set->m_nativeName)
	{
		TokenNode* firstToken;
		if (0 != propertyNode->m_modifier)
		{
			firstToken = propertyNode->m_modifier;
		}
		else
		{
			if (propertyNode->m_typeName->m_keyword)
			{
				firstToken = propertyNode->m_typeName->m_keyword;
			}
			else
			{
				firstToken = propertyNode->m_typeName->m_scopeNameList->m_scopeName->m_name;
			}
		}
		g_compiler.outputEmbededCodes(file, firstToken);
		file = 0;
	}

	ClassNode* classNode = static_cast<ClassNode*>(propertyNode->m_enclosing);

	if(propertyNode->m_modifier)
	{
		generateCode_Token(file, propertyNode->m_modifier, indentation);
		indentation = 0;
	}
	generateCode_Token(file, propertyNode->m_set->m_keyword, indentation);
	generateCode_Identify(file, propertyNode->m_name, 0, false);
	
	writeStringToFile("(", file);
	
	if (propertyNode->isFixedArray() || propertyNode->isDynamicArray() || propertyNode->isList())
	{
		writeStringToFile("size_t, ", file);
	}
	else if (propertyNode->isMap())
	{
		generateCode_TypeName(file, propertyNode->m_keyTypeName, propertyNode->m_enclosing, true, 0);
		if (0 != propertyNode->m_keyPassing)
		{
			generateCode_Token(file, propertyNode->m_keyPassing, 0);
		}
		writeStringToFile(", ", file);
	}
	generateCode_TypeName(file, propertyNode->m_typeName, propertyNode->m_enclosing, true, 0);
	if(0 != propertyNode->m_passing)
	{
		generateCode_Token(file, propertyNode->m_passing, 0);
	}
	writeStringToFile(");", file);	
}

void HeaderFileGenerator::generateCode_Property_CandidateCount(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	writeStringToFile("size_t candidateCount_", file, indentation);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	if (propertyNode->isStatic())
	{
		writeStringToFile("();", file);
	}
	else
	{
		writeStringToFile("() const;", file);
	}
}

void HeaderFileGenerator::generateCode_Property_GetCandidate(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	TokenNode* passing = propertyNode->m_passing;
	TypeNameNode* typeName = propertyNode->m_typeName;

	generateCode_TypeName(file, typeName, propertyNode->m_enclosing, true, indentation);
	if (0 != passing)
	{
		generateCode_Token(file, passing, 0);
	}
	writeStringToFile(" getCandidate_", file, 0);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	if (propertyNode->isStatic())
	{
		writeStringToFile("(size_t);", file);
	}
	else
	{
		writeStringToFile("(size_t) const;", file);
	}
}

void HeaderFileGenerator::generateCode_Property_Size(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	writeStringToFile("size_t size_", file, indentation);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	if (propertyNode->isStatic())
	{
		writeStringToFile("();", file);
	}
	else
	{
		writeStringToFile("() const;", file);
	}
}

void HeaderFileGenerator::generateCode_Property_Resize(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	writeStringToFile("void resize_", file, indentation);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	writeStringToFile("(size_t);", file);
}

void HeaderFileGenerator::generateCode_Property_PushBack(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	TokenNode* passing = propertyNode->m_passing;
	TypeNameNode* typeName = propertyNode->m_typeName;

	writeStringToFile("void pushBack_", file, indentation);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	writeStringToFile("(", file);
	generateCode_TypeName(file, typeName, propertyNode->m_enclosing, true, 0);
	if (0 != passing)
	{
		generateCode_Token(file, passing, 0);
	}
	writeStringToFile(");", file);
}

void HeaderFileGenerator::generateCode_Property_GetIterator(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	writeStringToFile("::pafcore::Iterator* getIterator_", file, indentation);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	writeStringToFile("();", file);
}

void HeaderFileGenerator::generateCode_Property_GetKey(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	generateCode_TypeName(file, propertyNode->m_keyTypeName, propertyNode->m_enclosing, true, indentation);
	if (0 != propertyNode->m_keyPassing)
	{
		generateCode_Token(file, propertyNode->m_keyPassing, 0);
	}
	writeStringToFile(" getKey_", file);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	writeStringToFile("(::pafcore::Iterator*);", file);
}

void HeaderFileGenerator::generateCode_Property_GetValue(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	TokenNode* passing = propertyNode->m_passing;
	TypeNameNode* typeName = propertyNode->m_typeName;

	generateCode_TypeName(file, typeName, propertyNode->m_enclosing, true, indentation);
	if (0 != passing)
	{
		generateCode_Token(file, passing, 0);
	}
	writeStringToFile(" getValue_", file);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	writeStringToFile("(::pafcore::Iterator*);", file);
}


void HeaderFileGenerator::generateCode_Property_Insert(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	TokenNode* passing = propertyNode->m_passing;
	TypeNameNode* typeName = propertyNode->m_typeName;

	writeStringToFile("void insert_", file, indentation);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	writeStringToFile("(::pafcore::Iterator*, ", file);
	generateCode_TypeName(file, typeName, propertyNode->m_enclosing, true, 0);
	if (0 != passing)
	{
		generateCode_Token(file, passing, 0);
	}
	writeStringToFile(");", file);
}


void HeaderFileGenerator::generateCode_Property_Erase(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isStatic())
	{
		writeStringToFile("static ", file, indentation);
		indentation = 0;
	}
	TokenNode* passing = propertyNode->m_passing;
	TypeNameNode* typeName = propertyNode->m_typeName;

	writeStringToFile("void erase_", file, indentation);
	writeStringToFile(propertyNode->m_name->m_str.c_str(), file);
	writeStringToFile("(::pafcore::Iterator*);", file);
}

void HeaderFileGenerator::generateCode_Property(FILE* file, PropertyNode* propertyNode, int indentation)
{
	if (propertyNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, propertyNode->m_filterNode);
		file = 0;
	}
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
		g_compiler.outputEmbededCodes(file, propertyNode->m_name); //¸ñÊ½

	}
	if (propertyNode->isSimple())
	{
		if (propertyNode->hasCandidate())
		{
			writeStringToFile("\n", file);
			generateCode_Property_CandidateCount(file, propertyNode, indentation);
			writeStringToFile("\n", file);
			generateCode_Property_GetCandidate(file, propertyNode, indentation);
		}
	}
	else if (propertyNode->isFixedArray() || propertyNode->isDynamicArray())
	{
		writeStringToFile("\n", file);
		generateCode_Property_Size(file, propertyNode, indentation);
		if (propertyNode->isDynamicArray())
		{
			writeStringToFile("\n", file);
			generateCode_Property_Resize(file, propertyNode, indentation);
		}
		writeStringToFile("\n", file);
		generateCode_Property_GetIterator(file, propertyNode, indentation);
		writeStringToFile("\n", file);
		generateCode_Property_GetValue(file, propertyNode, indentation);
	}
	else if (propertyNode->isList())
	{
		writeStringToFile("\n", file);
		generateCode_Property_PushBack(file, propertyNode, indentation);
		writeStringToFile("\n", file);
		generateCode_Property_GetIterator(file, propertyNode, indentation);
		writeStringToFile("\n", file);
		generateCode_Property_GetValue(file, propertyNode, indentation);
		writeStringToFile("\n", file);
		generateCode_Property_Insert(file, propertyNode, indentation);
		writeStringToFile("\n", file);
		generateCode_Property_Erase(file, propertyNode, indentation);
	}
	else if(propertyNode->isMap())
	{
		writeStringToFile("\n", file);
		generateCode_Property_GetIterator(file, propertyNode, indentation);
		writeStringToFile("\n", file);
		generateCode_Property_GetKey(file, propertyNode, indentation);
		writeStringToFile("\n", file);
		generateCode_Property_GetValue(file, propertyNode, indentation);
	}
};

void HeaderFileGenerator::generateCode_Method(FILE* file, MethodNode* methodNode, int indentation)
{
	if (methodNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, methodNode->m_filterNode);
		file = 0;
	}
	else if (methodNode->m_nativeName)
	{
		TokenNode* firstToken;
		if (0 != methodNode->m_modifier)
		{
			firstToken = methodNode->m_modifier;
		}
		else if (0 != methodNode->m_resultConst)
		{
			firstToken = methodNode->m_resultConst;
		}
		else if (0 != methodNode->m_resultTypeName)
		{
			if (methodNode->m_resultTypeName->m_keyword)
			{
				firstToken = methodNode->m_resultTypeName->m_keyword;
			}
			else
			{
				firstToken = methodNode->m_resultTypeName->m_scopeNameList->m_scopeName->m_name;
			}
		}
		else
		{
			firstToken = methodNode->m_name;
		}
		g_compiler.outputEmbededCodes(file, firstToken);
		file = 0;
	}

	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	if(classNode->isAdditionalMethod(methodNode))
	{
		writeStringToFile("\n", file);
	}
	if(0 != methodNode->m_modifier)
	{
		generateCode_Token(file, methodNode->m_modifier, indentation);
		indentation = 0;
	}
	if(0 != methodNode->m_resultConst)
	{
		generateCode_Token(file, methodNode->m_resultConst, indentation);
		indentation = 0;
	}
	if(0 != methodNode->m_resultTypeName)
	{
		generateCode_TypeName(file, methodNode->m_resultTypeName, methodNode->m_enclosing, true, indentation);
		indentation = 0;
		if(0 != methodNode->m_passing)
		{
			generateCode_Token(file, methodNode->m_passing, indentation);
			indentation = 0;
		}
		writeSpaceToFile(file);
	}
	//generateCode_Name(file, methodNode->m_name, methodNode->m_nativeName, indentation);
	generateCode_Identify(file, methodNode->m_name, indentation);
	generateCode_Token(file, methodNode->m_leftParenthesis, 0);
	std::vector<std::pair<TokenNode*, ParameterNode*>> parameterNodes;
	methodNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for(size_t i = 0; i < parameterCount; ++i)
	{
		if(parameterNodes[i].first)
		{
			generateCode_Token(file, parameterNodes[i].first, 0);
		}
		generateCode_Parameter(file, parameterNodes[i].second, classNode);
	}
	generateCode_Token(file, methodNode->m_rightParenthesis, 0);
	if(methodNode->m_constant)
	{
		generateCode_Token(file, methodNode->m_constant, 0);
	}
	if(methodNode->isAbstract())
	{
		writeStringToFile(" = 0 ", file);
	}
	generateCode_Token(file, methodNode->m_semicolon, 0);
}

void HeaderFileGenerator::generateCode_Operator(FILE* file, OperatorNode* operatorNode, int indentation)
{
	if (operatorNode->isNoCode())
	{
		g_compiler.outputEmbededCodes(file, operatorNode->m_filterNode);
		file = 0;
	}

	ClassNode* classNode = static_cast<ClassNode*>(operatorNode->m_enclosing);
	if (operatorNode->m_modifier)
	{
		generateCode_Token(file, operatorNode->m_modifier, indentation);
		indentation = 0;
	}
	if (0 != operatorNode->m_resultConst)
	{
		generateCode_Token(file, operatorNode->m_resultConst, indentation);
		indentation = 0;
	}
	if (0 != operatorNode->m_resultTypeName)
	{
		generateCode_TypeName(file, operatorNode->m_resultTypeName, operatorNode->m_enclosing, true, indentation);
		indentation = 0;
		if (0 != operatorNode->m_passing)
		{
			generateCode_Token(file, operatorNode->m_passing, indentation);
			indentation = 0;
		}
		writeSpaceToFile(file);
	}
	generateCode_Token(file, operatorNode->m_keyword, 0);
	generateCode_TokenForOperator(file, operatorNode->m_sign, 0);
	if ('(' == operatorNode->m_sign->m_nodeType)
	{
		writeStringToFile(")", file);
	}
	else if ('[' == operatorNode->m_sign->m_nodeType)
	{
		writeStringToFile("]", file);
	}
	generateCode_Token(file, operatorNode->m_leftParenthesis, 0);
	std::vector<std::pair<TokenNode*, ParameterNode*>> parameterNodes;
	operatorNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for (size_t i = 0; i < parameterCount; ++i)
	{
		if (parameterNodes[i].first)
		{
			generateCode_Token(file, parameterNodes[i].first, 0);
		}
		generateCode_Parameter(file, parameterNodes[i].second, classNode);
	}
	if (snt_operator_post_inc == operatorNode->m_sign->m_nodeType
		|| snt_operator_post_inc == operatorNode->m_sign->m_nodeType)
	{
		writeStringToFile("int", file);
	}
	generateCode_Token(file, operatorNode->m_rightParenthesis, 0);
	if (operatorNode->m_constant)
	{
		generateCode_Token(file, operatorNode->m_constant, 0);
	}
	if (operatorNode->isAbstract())
	{
		writeStringToFile(" = 0 ", file);
	}
	generateCode_Token(file, operatorNode->m_semicolon, 0);
}
