#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct TokenNode;
struct IdentifyNode;

struct EnumeratorListNode : SyntaxNodeImpl
{
	EnumeratorListNode* m_enumeratorList;
	TokenNode* m_delimiter;
	IdentifyNode* m_identity;
public:
	EnumeratorListNode(EnumeratorListNode* enumeratorList, TokenNode* delimiter, IdentifyNode* identity);
	void collectIdentifyNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& identifyNodes);
	void collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes);
};

