#pragma once

#include "SyntaxNodeImpl.h"
#include <string>
#include <vector>
#include <map>

struct TokenNode;
struct ScopeListNode;
struct TypeNameListNode;
struct ScopeNode;
struct TemplateParameterNode;
struct TypeInfo;
struct TypeNameNode;
struct TemplateClassInstanceNode;

typedef std::map<std::string, TypeNameNode*> TemplateArgumentMap;

struct TypeNameNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	PrimitiveType m_primitiveType;
	ScopeListNode* m_scopeList;
	TokenNode* m_leftBracket;
	TypeNameListNode* m_parameterList;
	TokenNode* m_rightBracket;
	TypeCategory m_typeCategory;
	TypeInfo* m_typeInfo;
private:
	void getName(std::vector<std::string>& names);
public:
	TypeNameNode(TokenNode* keyword, PrimitiveType primitiveType);
	TypeNameNode(ScopeListNode* scopeList);
	TypeNameNode(ScopeListNode* scopeList, TokenNode* leftBracket, TypeNameListNode* parameterList, TokenNode* rightBracket);
	size_t getParameterCount();
	void getName(std::string& name);
	void getTemplateParametersName(std::string& name);
	void getNameExceptTemplateParameters(std::string& name);
	TypeCategory getFullName(std::string& fullName, TemplateArgumentMap* templateArguments);
	TypeCategory getRelativeName(std::string& typeName, ScopeNode* scopeNode, TemplateArgumentMap* templateArguments);
	void checkTypeName(ScopeNode* scopeNode);
	void checkTypeName_(ScopeNode* scopeNode, std::vector<TemplateParameterNode*>& templateParameters);
	TypeInfo* checkTemplateTypeName_(ScopeNode* scopeNode, std::vector<TemplateParameterNode*>& templateParameters);
	void checkTypeNameForTemplateClassInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments);
	bool isVoid()
	{
		return void_type == m_typeCategory;
	}
	bool isPrimitiveType()
	{
		return primitive_type == m_typeCategory;
	}
	bool isEnumType()
	{
		return enum_type == m_typeCategory;
	}	
	bool isValueType()
	{
		return value_type == m_typeCategory;
	}
	bool isReferenceType()
	{
		return reference_type == m_typeCategory;
	}
	bool isTemplateParameter()
	{
		return template_parameter == m_typeCategory;
	}
	bool isTemplateForm()
	{
		return 0 != m_parameterList;
	}
	bool isGlobal();
};


struct CompareTypeNamePtr
{
	bool operator()(const TypeNameNode* arg1, const TypeNameNode* arg2) const;
};

