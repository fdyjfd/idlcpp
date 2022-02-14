#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct TokenNode;

struct TokenListNode : SyntaxNodeImpl
{
	TokenListNode* m_tokenList;
	TokenNode* m_token;
public:
	TokenListNode(TokenListNode* tokenList, TokenNode* token);
	void collectTokenNodes(std::vector<TokenNode*>& tokenNodes);
};

