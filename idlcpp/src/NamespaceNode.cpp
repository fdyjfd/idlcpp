#include "NamespaceNode.h"
#include "MemberListNode.h"
#include "ClassNode.h"
#include "DelegateNode.h"
#include "TypeTree.h"
#include "Compiler.h"
#include <assert.h>

NamespaceNode::NamespaceNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace)
{
	m_nodeType = snt_namespace;
	m_keyword = keyword;
	m_name = name;
	m_leftBrace = leftBrace;
	m_memberList = memberList;
	m_rightBrace = rightBrace;
	m_memberList->initializeMembersEnclosing(this);
	m_typeNode = 0;
}

bool NamespaceNode::isGlobalNamespace()
{
	return 0 == m_keyword;
}

TypeNode* NamespaceNode::getTypeNode()
{
	return m_typeNode;
}

void NamespaceNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	assert(0 == m_typeNode && enclosingTypeNode->isNamespace() && 0 == templateArguments);
	m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addNamespace(this);
	if (m_typeNode)
	{
		m_memberList->collectTypes(m_typeNode, templateArguments);
	}
}

void NamespaceNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	assert(0 != m_typeNode && 0 == templateArguments);
	m_memberList->checkTypeNames(m_typeNode, templateArguments);
}

void NamespaceNode::checkSemantic(TemplateArguments* templateArguments)
{
	MemberNode::checkSemantic(templateArguments);
	assert(0 == templateArguments);
	m_memberList->checkSemantic(templateArguments);
}

void NamespaceNode::extendInternalCode(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
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
			static_cast<NamespaceNode*>(memberNode)->extendInternalCode(m_typeNode, templateArguments);
			break;
		case snt_class:
			static_cast<ClassNode*>(memberNode)->extendInternalCode(m_typeNode, templateArguments);
			break;
		case snt_delegate:
			static_cast<DelegateNode*>(memberNode)->extendInternalCode(m_typeNode, templateArguments);
			break;
		}
	}
}
