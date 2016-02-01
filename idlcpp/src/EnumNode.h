#pragma once
#include "ScopeNode.h"

struct TokenNode;
struct EnumeratorListNode;

struct EnumNode : ScopeNode
{
	TokenNode* m_keyword;
	TokenNode* m_leftBrace;
	EnumeratorListNode* m_enumeratorList;
	TokenNode* m_rightBrace;
	TokenNode* m_semicolon;
public:
	EnumNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, EnumeratorListNode* enumeratorList, TokenNode* rightBrace, TokenNode* semicolon);
	virtual TypeCategory getTypeCategory();
	virtual void collectTypeInfo();
	virtual void checkSemantic();
};