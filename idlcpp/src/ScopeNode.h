#pragma once

#include "MemberNode.h"

struct MemberListNode;

struct ScopeNode : MemberNode
{
	MemberListNode* m_memberList;
public:
	ScopeNode()
	{
		m_memberList = 0;
	}
};
