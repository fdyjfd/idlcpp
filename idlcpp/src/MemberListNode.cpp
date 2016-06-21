#include "MemberListNode.h"
#include "MemberNode.h"
#include <assert.h>

MemberListNode::MemberListNode(MemberListNode* memberList, MemberNode* member)
{
	m_nodeType = snt_member_list;
	m_memberList = memberList;
	m_member = member;
}

void MemberListNode::initializeMembersEnclosing(ScopeNode* parent)
{
	MemberListNode* list = this;
	while (0 != list)
	{
		list->m_member->m_enclosing = parent;
		list = list->m_memberList;
	}
}

void MemberListNode::collectMemberNodes(std::vector<MemberNode*>& memberNodes)
{
	MemberListNode* list = this;
	while (0 != list)
	{
		memberNodes.push_back(list->m_member);
		list = list->m_memberList;
	}
	std::reverse(memberNodes.begin(), memberNodes.end());
}

void MemberListNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	assert(enclosingTypeNode);
	std::vector<MemberNode*> memberNodes;
	collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		memberNode->collectTypes(enclosingTypeNode, templateArguments);
	}
}

void MemberListNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	std::vector<MemberNode*> memberNodes;
	collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		memberNode->checkTypeNames(enclosingTypeNode, templateArguments);
	}
}

void MemberListNode::checkSemantic(TemplateArguments* templateArguments)
{
	std::vector<MemberNode*> memberNodes;
	collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		memberNode->checkSemantic(templateArguments);
	}
}
