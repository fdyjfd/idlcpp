#include "TemplateParametersNode.h"
#include "TemplateParameterListNode.h"
#include "IdentifyNode.h"
#include "RaiseError.h"
#include <set>

TemplateParametersNode::TemplateParametersNode(TokenNode* keyword, TokenNode* leftBracket, TemplateParameterListNode* parameterList, TokenNode* rightBracket)
{
	m_nodeType = snt_template_parameters;
	m_keyword = keyword;
	m_leftBracket = leftBracket;
	m_parameterList = parameterList;
	m_rightBracket = rightBracket;
}

void TemplateParametersNode::collectParameterNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& parameterNodes)
{
	TemplateParameterListNode* list = m_parameterList;
	while(0 != list)
	{
		parameterNodes.push_back(std::make_pair(list->m_delimiter, list->m_parameter));
		list = list->m_parameterList;
	}
	std::reverse(parameterNodes.begin(), parameterNodes.end());
}

void TemplateParametersNode::collectParameterNodes(std::vector<IdentifyNode*>& parameterNodes)
{
	TemplateParameterListNode* list = m_parameterList;
	while (0 != list)
	{
		parameterNodes.push_back(list->m_parameter);
		list = list->m_parameterList;
	}
	std::reverse(parameterNodes.begin(), parameterNodes.end());
}

size_t TemplateParametersNode::getParameterCount()
{
	size_t count = 0;
	TemplateParameterListNode* list = m_parameterList;
	while (0 != list)
	{
		++count;
		list = list->m_parameterList;
	}
	return count;
}

bool TemplateParametersNode::checkSemantic()
{
	bool res = true;
	std::set<std::string> paramNames;
	std::vector<IdentifyNode*> parameterNodes;
	collectParameterNodes(parameterNodes);
	size_t count = parameterNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		IdentifyNode* paramNode = parameterNodes[i];
		if(!paramNames.insert(paramNode->m_str).second)
		{
			RaiseError_TemplateParameterRedefinition(paramNode);
			res = false;
		}
	}
	return res;
}
