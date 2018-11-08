#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct TokenNode;
struct IdentifyNode;

struct IdentifyListNode : SyntaxNodeImpl
{
	IdentifyListNode* m_identifyList;
	TokenNode* m_delimiter;
	IdentifyNode* m_identify;
public:
	IdentifyListNode(IdentifyListNode* identifyList, TokenNode* delimiter, IdentifyNode* identify);
	void collectIdentifyNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& identifyNodes);
	void collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes);
};

