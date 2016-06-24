#include "IdentityListNode.h"

IdentityListNode::IdentityListNode(IdentityListNode* identityList, TokenNode* delimiter, IdentifyNode* identity)
{
	m_nodeType = snt_identity_list;
	m_identityList = identityList;
	m_delimiter = delimiter;
	m_identity = identity;
}

void IdentityListNode::collectIdentifyNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& identifyNodes)
{
	IdentityListNode* list = this;
	while(0 != list)
	{
		identifyNodes.push_back(std::make_pair(list->m_delimiter, list->m_identity));
		list = list->m_identityList;
	}
	std::reverse(identifyNodes.begin(), identifyNodes.end());
}

void IdentityListNode::collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes)
{
	IdentityListNode* list = this;
	while (0 != list)
	{
		identifyNodes.push_back(list->m_identity);
		list = list->m_identityList;
	}
	std::reverse(identifyNodes.begin(), identifyNodes.end());
}
