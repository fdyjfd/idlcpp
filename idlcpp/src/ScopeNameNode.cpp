#include "ScopeNameNode.h"
#include "IdentifyNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include <vector>
#include <assert.h>

ScopeNameNode::ScopeNameNode(IdentifyNode* name, TokenNode* leftBracket, TypeNameListNode* parameterList, TokenNode* rightBracket)
{
	m_nodeType = snt_scope_name;
	m_name = name;
	m_leftBracket = leftBracket;
	m_parameterList = parameterList;
	m_rightBracket = rightBracket;
}

bool ScopeNameNode::calcTemplateParametersTypeNodes(TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments)
{
	if (0 != m_parameterList)
	{
		std::vector<TypeNameNode*> typeNameNodes;
		m_parameterList->collectTypeNameNodes(typeNameNodes);
		auto begin = typeNameNodes.begin();
		auto end = typeNameNodes.end();
		for (auto it = begin; it != end; ++it)
		{
			TypeNameNode* typeNameNode = *it;
			if (!typeNameNode->calcTypeNodes(enclosingTypeTreeNode, templateArguments))
			{
				return false;
			}
		}
	}
	return true;
}

void ScopeNameNode::getString(std::string& str)
{
	str = m_name->m_str;
	if (m_parameterList)
	{
		assert(m_leftBracket && m_rightBracket);
		str += "<";
		std::vector<TypeNameNode*> typeNameNodes;
		m_parameterList->collectTypeNameNodes(typeNameNodes);
		auto begin = typeNameNodes.begin();
		auto end = typeNameNodes.end();
		for (auto it = begin; it != end; ++it)
		{
			TypeNameNode* typeNameNode = *it;
			std::string subStr;
			typeNameNode->getString(subStr);
			if (it != begin)
			{
				str += ", ";
			}
			str += subStr;
		}
		str += ">";
	}
}


bool ScopeNameNode::isTemplateForm()
{
	return 0 != m_parameterList;
}
