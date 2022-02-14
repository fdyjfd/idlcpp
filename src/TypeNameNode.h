#pragma once

#include "SyntaxNodeImpl.h"
#include <string>
#include <vector>
#include <map>

struct TokenNode;
struct IdentifyNode;
struct ScopeNameListNode;
struct TypeNameListNode;
struct ScopeNode;
struct TypeInfo;
struct TypeNameNode;
struct TemplateClassInstanceNode;
struct TypeNode;
struct TemplateArguments;

enum TypeCategory;

struct TypeNameNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	ScopeNameListNode* m_scopeNameList;
	TokenNode* m_filterNode;
	TypeNode* m_startTypeNode;
	TypeNode* m_typeNode;
public:
	TypeNameNode(TokenNode* keyword, PredefinedType primitiveType);
	TypeNameNode(ScopeNameListNode* scopeNameList);
	bool isNoCode();
	bool isNoMeta();
	bool calcTypeNodes(TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments);
	TypeNode* getTypeNode(TemplateArguments* templateArguments);
	TypeNode* getActualTypeNode(TemplateArguments* templateArguments);
	void getString(std::string& str);
	void getRelativeName(std::string& typeName, ScopeNode* scopeNode);
	bool underTemplateParameter();
};

