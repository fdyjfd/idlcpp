#pragma once

#include "MemberNode.h"

struct TokenNode;
struct FilterNode : MemberNode
{
	bool m_native;
	bool m_meta;
	FilterNode(bool native, bool meta)
	{
		m_nodeType = snt_filter;
		m_native = native;
		m_meta = meta;
	}
};
