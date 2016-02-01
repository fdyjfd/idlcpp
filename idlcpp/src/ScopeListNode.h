#pragma once
#include "SyntaxNodeImpl.h"
#include <vector>

struct IdentifyNode;

struct ScopeListNode : SyntaxNodeImpl
{
	ScopeListNode* m_scopeList;
	IdentifyNode* m_name;
	bool m_global;
public:
	ScopeListNode(ScopeListNode* scopeList, IdentifyNode* name);
	void collectIdentifyNodes(std::vector<IdentifyNode*>& identifyNodes);
};

