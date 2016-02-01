#include "ScopeListNode.h"
#include <vector>

ScopeListNode::ScopeListNode(ScopeListNode* scopeList, IdentifyNode* name)
{
	m_nodeType = snt_scope_list;
	m_scopeList = scopeList;
	m_name = name;
	m_global = false;
}

void ScopeListNode::collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes)
{
	ScopeListNode* list = this;
	while (0 != list)
	{
		identifyNodes.push_back(list->m_name);
		list = list->m_scopeList;
	}
	std::reverse(identifyNodes.begin(), identifyNodes.end());
}
