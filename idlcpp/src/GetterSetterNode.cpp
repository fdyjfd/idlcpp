#pragma once

#include "GetterSetterNode.h"
#include "TokenNode.h"

GetterSetterNode::GetterSetterNode(TokenNode* keyword, TokenNode* constant, TypeNameNode* type, TokenNode* passing)
{
	m_nodeType = snt_getter_setter;
	m_keyword = keyword;
	m_constant = constant;
	m_type = type;
	m_passing = passing;
}

bool GetterSetterNode::isConstant()
{
	return (0 != m_constant);
}

bool GetterSetterNode::byValue()
{
	return 0 == m_passing;
}

bool GetterSetterNode::byPtr()
{
	return (0 != m_passing && snt_keyword_ptr == m_passing->m_nodeType);
}

bool GetterSetterNode::byRef()
{
	return (0 != m_passing && snt_keyword_ref == m_passing->m_nodeType);
}
