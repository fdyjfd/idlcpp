#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct TypeNameNode;
struct IdentifyNode;

struct GetterSetterNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	IdentifyNode* m_nativeName;
	bool m_getterIncRef;
	bool m_setterDecRef;
	bool m_setterAllowNull;
public:
	GetterSetterNode(TokenNode* keyword);
	bool isGetterIncRef();
	bool isSetterDecRef();
	bool isSetterAllowNull();
};
