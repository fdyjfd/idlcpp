#include "ParameterListNode.h"
#include "ParameterNode.h"
#include "IdentifyNode.h"
#include "ErrorList.h"


ParameterListNode::ParameterListNode(ParameterListNode* parameterList, TokenNode* delimiter, ParameterNode* parameter)
{
	m_nodeType = snt_parameter_list;
	m_parameterList = parameterList;
	m_delimiter = delimiter;
	m_parameter = parameter;
}

void ParameterListNode::collectParameterNodes(std::vector<std::pair<TokenNode*, ParameterNode*>>& parameterNodes)
{
	ParameterListNode* list = this;
	while (0 != list)
	{
		parameterNodes.push_back(std::make_pair(list->m_delimiter, list->m_parameter));
		list = list->m_parameterList;
	}
	std::reverse(parameterNodes.begin(), parameterNodes.end());
}

void ParameterListNode::collectParameterNodes(std::vector<ParameterNode*>& parameterNodes)
{
	ParameterListNode* list = this;
	while (0 != list)
	{
		parameterNodes.push_back(list->m_parameter);
		list = list->m_parameterList;
	}
	std::reverse(parameterNodes.begin(), parameterNodes.end());
}


void checkParameterNames(std::vector<ParameterNode*>& parameterNodes)
{
	std::set<IdentifyNode*, CompareIdentifyPtr> items;
	size_t count = parameterNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		IdentifyNode* identify = parameterNodes[i]->m_name;
		auto res = items.insert(identify);
		if (!res.second)
		{
			char buf[4096];
			sprintf_s(buf, "\'%s\' : parameter already defined at line %d, column %d", identify->m_str.c_str(),
				(*res.first)->m_lineNo, (*res.first)->m_columnNo);
			ErrorList_AddItem_CurrentFile(identify->m_lineNo,
				identify->m_columnNo, semantic_error_member_redefined, buf);
		}
	}
}