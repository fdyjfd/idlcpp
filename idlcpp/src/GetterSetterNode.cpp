#pragma once

#include "GetterSetterNode.h"
#include "TokenNode.h"

GetterSetterNode::GetterSetterNode(TokenNode* keyword, TokenNode* constant, TypeNameNode* typeName, TokenNode* passing)
{
	m_nodeType = snt_getter_setter;
	m_keyword = keyword;
	m_constant = constant;
	m_typeName = typeName;
	m_passing = passing;
	m_nativeName = 0;
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
	return (0 != m_passing && '*' == m_passing->m_nodeType);
}

bool GetterSetterNode::byRef()
{
	return (0 != m_passing && '&' == m_passing->m_nodeType);
}
