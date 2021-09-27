#include "EnumeratorListNode.h"

EnumeratorListNode::EnumeratorListNode(EnumeratorListNode* enumeratorList, TokenNode* delimiter, EnumeratorNode* enumerator)
{
	m_nodeType = snt_enumerator_list;
	m_enumeratorList = enumeratorList;
	m_delimiter = delimiter;
	m_enumerator = enumerator;
}

void EnumeratorListNode::collectEnumeratorNodes(std::vector<std::pair<TokenNode*, EnumeratorNode*>>& enumeratorNodes)
{
	EnumeratorListNode* list = this;
	while(0 != list)
	{
		enumeratorNodes.push_back(std::make_pair(list->m_delimiter, list->m_enumerator));
		list = list->m_enumeratorList;
	}
	std::reverse(enumeratorNodes.begin(), enumeratorNodes.end());
}

void EnumeratorListNode::collectEnumeratorNodes(std::vector<EnumeratorNode*>& enumeratorNodes)
{
	EnumeratorListNode* list = this;
	while (0 != list)
	{
		enumeratorNodes.push_back(list->m_enumerator);
		list = list->m_enumeratorList;
	}
	std::reverse(enumeratorNodes.begin(), enumeratorNodes.end());
}
