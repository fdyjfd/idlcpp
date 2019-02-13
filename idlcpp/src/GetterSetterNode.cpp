#pragma once

#include "GetterSetterNode.h"
#include "TokenNode.h"

GetterSetterNode::GetterSetterNode(TokenNode* keyword)
{
	m_nodeType = snt_getter_setter;
	m_keyword = keyword;
	m_nativeName = 0;
	m_getterIncRef = false;
	m_setterDecRef = false;
	m_setterAllowNull = false;
}

bool GetterSetterNode::isGetterIncRef()
{
	return m_getterIncRef;
}

bool GetterSetterNode::isSetterDecRef()
{
	return m_setterDecRef;
}

bool GetterSetterNode::isSetterAllowNull()
{
	return m_setterAllowNull;
}
