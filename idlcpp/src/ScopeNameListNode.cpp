#include "ScopeNameListNode.h"
#include "ScopeNameNode.h"
#include <vector>

ScopeNameListNode::ScopeNameListNode(ScopeNameListNode* scopeNameList, ScopeNameNode* scopeName)
{
	m_nodeType = snt_scope_name_list;
	m_scopeNameList = scopeNameList;
	m_scopeName = scopeName;
	m_global = false;
}

void ScopeNameListNode::collectIdentifyNodes(std::vector<ScopeNameNode*>& scopeNameNodes)
{
	ScopeNameListNode* list = this;
	while (0 != list)
	{
		scopeNameNodes.push_back(list->m_scopeName);
		list = list->m_scopeNameList;
	}
	std::reverse(scopeNameNodes.begin(), scopeNameNodes.end());
}

bool ScopeNameListNode::calcTemplateParametersTypeNodes(TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments)
{
	std::vector<ScopeNameNode*> scopeNameNodes;
	collectIdentifyNodes(scopeNameNodes);
	auto begin = scopeNameNodes.begin();
	auto end = scopeNameNodes.end();
	for (auto it = begin; it != end; ++it)
	{
		ScopeNameNode* scopeNameNode = *it;
		if (!scopeNameNode->calcTemplateParametersTypeNodes(enclosingTypeTreeNode, templateArguments))
		{
			return false;
		}
	}
	return true;
}

void ScopeNameListNode::getString(std::string& str)
{
	str = m_global ? "::" : "";
	std::vector<ScopeNameNode*> scopeNameNodes;
	collectIdentifyNodes(scopeNameNodes);
	auto begin = scopeNameNodes.begin();
	auto end = scopeNameNodes.end();
	for (auto it = begin; it != end; ++it)
	{
		ScopeNameNode* scopeNameNode = *it;
		std::string subStr;
		scopeNameNode->getString(subStr);
		if (it != begin)
		{
			str += "::";
		}
		str += subStr;
	}
}
