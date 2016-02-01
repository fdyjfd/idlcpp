#pragma once
#include "MemberNode.h"

struct TokenNode;
struct ScopeListNode;
struct TypeNameNode;

struct TypeAliasNode : MemberNode
{
	TokenNode* m_keyword;
	TypeNameNode* m_typeName;
	TypeCategory m_typeCategory;
public:
	TypeAliasNode(IdentifyNode* name, TypeCategory typeCategory);
	TypeAliasNode(TokenNode* keyword, IdentifyNode* name, TypeNameNode* typeName);
	virtual void collectTypeInfo();
	virtual TypeCategory getTypeCategory();
	virtual void checkSemantic();
	virtual bool isAbstractClass();
};

