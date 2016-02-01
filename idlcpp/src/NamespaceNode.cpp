#include "NamespaceNode.h"
#include "MemberListNode.h"
#include "ClassNode.h"
#include "SourceFile.h"

NamespaceNode::NamespaceNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace)
{
	m_nodeType = snt_namespace;
	m_keyword = keyword;
	m_name = name;
	m_leftBrace = leftBrace;
	m_memberList = memberList;
	m_rightBrace = rightBrace;
	m_memberList->initializeMembersEnclosing(this);
}

bool NamespaceNode::isGlobalNamespace()
{
	return 0 == m_keyword;
}

void NamespaceNode::collectTypeInfo()
{
	g_sourceFileManager.registerNamespace(this);
	m_memberList->collectTypeInfo();
}

void NamespaceNode::checkSemantic()
{
	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);

	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		memberNodes[i]->checkSemantic();
	}
}

void NamespaceNode::extendInternalCode()
{
	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_namespace:
			static_cast<NamespaceNode*>(memberNode)->extendInternalCode();
			break;
		case snt_class:
			static_cast<ClassNode*>(memberNode)->extendInternalCode();
			break;
		}
	}
}
