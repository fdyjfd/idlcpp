#include "EnumNode.h"
#include "ClassNode.h"
#include "IdentifyNode.h"
#include "IdentityListNode.h"
#include "ErrorList.h"
#include "Compiler.h"
#include "TypeTree.h"
#include <vector>
#include <assert.h>

EnumNode::EnumNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, IdentityListNode* identityList, TokenNode* rightBrace)
{
	m_nodeType = snt_enum;
	m_keyword = keyword;
	m_name = name;
	m_leftBrace = leftBrace;
	m_identityList = identityList;
	m_rightBrace = rightBrace;
	m_semicolon = 0;
	m_typeNode = 0;
}

TypeNode* EnumNode::getTypeNode()
{
	return m_typeNode;
}


void EnumNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	assert(0 == m_typeNode);
	switch (enclosingTypeNode->m_category)
	{
	case tc_namespace:
		m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addEnum(this);
		break;
	case tc_class_type:
		m_typeNode = static_cast<ClassTypeNode*>(enclosingTypeNode)->addEnum(this);
		break;
	default:
		assert(false);
	}
}

void EnumNode::checkSemantic(TemplateArguments* templateArguments)
{
	MemberNode::checkSemantic(templateArguments);

	std::vector<IdentifyNode*> identifyNodes;
	m_identityList->collectIdentifyNodes(identifyNodes);
	size_t count = identifyNodes.size();
	std::set<IdentifyNode*, CompareIdentifyPtr> items;
	for(size_t i = 0; i < count; ++i)
	{
		IdentifyNode* identify = identifyNodes[i];
		auto res = items.insert(identify);
		if(!res.second)
		{
			char buf[512];
			sprintf_s(buf, "\'%s\' : enumerator already defined at line %d, column %d", identify->m_str.c_str(), 
				(*res.first)->m_lineNo, (*res.first)->m_columnNo);
			ErrorList_AddItem_CurrentFile(identify->m_lineNo,
				identify->m_columnNo, semantic_error_enumerator_redefined, buf);
		}
	}
}
