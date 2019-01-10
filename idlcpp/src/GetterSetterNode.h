#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct TypeNameNode;
struct IdentifyNode;

struct GetterSetterNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	IdentifyNode* m_nativeName;
	bool m_allowNull;
public:
	GetterSetterNode(TokenNode* keyword);
	bool isAllowNull();
};
