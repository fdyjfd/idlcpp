#include "IdentifyListNode.h"

IdentifyListNode::IdentifyListNode(IdentifyListNode* identifyList, TokenNode* delimiter, IdentifyNode* identify)
{
	m_nodeType = snt_identify_list;
	m_identifyList = identifyList;
	m_delimiter = delimiter;
	m_identify = identify;
}

void IdentifyListNode::collectIdentifyNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& identifyNodes)
{
	IdentifyListNode* list = this;
	while(0 != list)
	{
		identifyNodes.push_back(std::make_pair(list->m_delimiter, list->m_identify));
		list = list->m_identifyList;
	}
	std::reverse(identifyNodes.begin(), identifyNodes.end());
}

void IdentifyListNode::collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes)
{
	IdentifyListNode* list = this;
	while (0 != list)
	{
		identifyNodes.push_back(list->m_identify);
		list = list->m_identifyList;
	}
	std::reverse(identifyNodes.begin(), identifyNodes.end());
}
