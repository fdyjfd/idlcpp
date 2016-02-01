#pragma once
#include "NamespaceNode.h"

struct MemberListNode;

struct ProgramNode : NamespaceNode
{
public:
	ProgramNode(MemberListNode* memberList);
	virtual void collectTypeInfo();
	void checkSemantic();
};
