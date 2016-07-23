#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct TypeNameNode;
struct IdentifyNode;

struct GetterSetterNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	TokenNode* m_constant;
	TypeNameNode* m_typeName;
	TokenNode* m_passing;//* or &
	IdentifyNode* m_nativeName;
public:
	GetterSetterNode(TokenNode* keyword, TokenNode* constant, TypeNameNode* typeName, TokenNode* passing);
	bool isConstant();
	bool byValue();
	bool byPtr();
	bool byRef();
};
