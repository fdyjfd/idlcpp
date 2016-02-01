#pragma once
#include "SyntaxNodeImpl.h"
#include <vector>

struct MemberNode;
struct ScopeNode;

struct MemberListNode : SyntaxNodeImpl
{
	MemberListNode* m_memberList;
	MemberNode* m_member;
public:
	MemberListNode(MemberListNode* memberList, MemberNode* member);
	void initializeMembersEnclosing(ScopeNode* parent);
	void collectMemberNodes(std::vector<MemberNode*>& memberNodes);
	void collectTypeInfo();
};
