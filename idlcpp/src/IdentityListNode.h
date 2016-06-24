#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct TokenNode;
struct IdentifyNode;

struct IdentityListNode : SyntaxNodeImpl
{
	IdentityListNode* m_identityList;
	TokenNode* m_delimiter;
	IdentifyNode* m_identity;
public:
	IdentityListNode(IdentityListNode* identityList, TokenNode* delimiter, IdentifyNode* identity);
	void collectIdentifyNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& identifyNodes);
	void collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes);
};

