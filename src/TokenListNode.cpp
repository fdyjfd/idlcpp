#include "TokenListNode.h"

TokenListNode::TokenListNode(TokenListNode* tokenList, TokenNode* token)
{
	m_nodeType = snt_token_list;
	m_tokenList = tokenList;
	m_token = token;
}

void TokenListNode::collectTokenNodes(std::vector<TokenNode*>& tokenNodes)
{
	TokenListNode* list = this;
	while (0 != list)
	{
		tokenNodes.push_back(list->m_token);
		list = list->m_tokenList;
	}
	std::reverse(tokenNodes.begin(), tokenNodes.end());
}
