#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct TypeNameNode;

struct GetterSetterNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	TokenNode* m_constant;
	TypeNameNode* m_type;
	TokenNode* m_passing;//PTR or REF
public:
	GetterSetterNode(TokenNode* keyword, TokenNode* constant, TypeNameNode* type, TokenNode* passing);
	bool isConstant();
	bool byValue();
	bool byPtr();
	bool byRef();
};
