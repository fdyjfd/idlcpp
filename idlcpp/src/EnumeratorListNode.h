#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct TokenNode;
struct EnumeratorNode;

struct EnumeratorListNode : SyntaxNodeImpl
{
	EnumeratorListNode* m_enumeratorList;
	TokenNode* m_delimiter;
	EnumeratorNode* m_enumerator;
public:
	EnumeratorListNode(EnumeratorListNode* enumeratorList, TokenNode* delimiter, EnumeratorNode* enumerator);
	void collectEnumeratorNodes(std::vector<std::pair<TokenNode*, EnumeratorNode*>>& enumeratorNodes);
	void collectEnumeratorNodes(std::vector<EnumeratorNode*>& enumeratorNodes);
};

