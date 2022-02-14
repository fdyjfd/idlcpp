#pragma once
#include "MemberNode.h"

struct TokenNode;
struct ScopeNameListNode;
struct TypeNameNode;
struct TypedefTypeNode;

struct TypedefNode : MemberNode
{
	TokenNode* m_keyword;
	TypeNameNode* m_typeName;
	TypedefTypeNode* m_typeNode;
	TypeNode* m_srcTypeNode;
public:
	TypedefNode(TokenNode* keyword, IdentifyNode* name, TypeNameNode* typeName);
	TypeNode* getActualTypeNode(TemplateArguments* templateArguments);
	virtual TypeNode* getTypeNode();
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};

