#pragma once

#include "GetterSetterNode.h"
#include "TokenNode.h"

GetterSetterNode::GetterSetterNode(TokenNode* keyword)
{
	m_nodeType = snt_getter_setter;
	m_keyword = keyword;
	m_nativeName = 0;
	m_allowNull = false;
}

bool GetterSetterNode::isAllowNull()
{
	return m_allowNull;
}
