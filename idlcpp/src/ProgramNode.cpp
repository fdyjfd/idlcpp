#include "ProgramNode.h"
#include "MemberListNode.h"
#include "NamespaceNode.h"
#include "IdentifyNode.h"
#include "ClassNode.h"
#include "SourceFile.h"
#include "Options.h"
#include "Platform.h"
#include <vector>

const char g_pragmaOnce[] = {"#pragma once\n\n"};

ProgramNode::ProgramNode(MemberListNode* memberList)
: NamespaceNode(0, 0, 0, memberList, 0)
{
}

void ProgramNode::collectTypeInfo()
{
	m_memberList->collectTypeInfo();
}

void ProgramNode::checkSemantic()
{
	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		memberNodes[i]->checkSemantic();
	}
}
