#include "EnumeratorListNode.h"

EnumeratorListNode::EnumeratorListNode(EnumeratorListNode* enumeratorList, TokenNode* delimiter, IdentifyNode* identity)
{
	m_nodeType = snt_enumerator_list;
	m_enumeratorList = enumeratorList;
	m_delimiter = delimiter;
	m_identity = identity;
}

void EnumeratorListNode::collectIdentifyNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& identifyNodes)
{
	EnumeratorListNode* list = this;
	while(0 != list)
	{
		identifyNodes.push_back(std::make_pair(list->m_delimiter, list->m_identity));
		list = list->m_enumeratorList;
	}
	std::reverse(identifyNodes.begin(), identifyNodes.end());
}

void EnumeratorListNode::collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes)
{
	EnumeratorListNode* list = this;
	while (0 != list)
	{
		identifyNodes.push_back(list->m_identity);
		list = list->m_enumeratorList;
	}
	std::reverse(identifyNodes.begin(), identifyNodes.end());
}
