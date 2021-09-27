#include "EnumNode.h"
#include "ClassNode.h"
#include "EnumeratorNode.h"
#include "EnumeratorListNode.h"
#include "IdentifyNode.h"
#include "ErrorList.h"
#include "Compiler.h"
#include "TypeTree.h"
#include <vector>
#include <assert.h>

EnumNode::EnumNode(TokenNode* keyword, TokenNode* keyword2, IdentifyNode* name, TokenNode* leftBrace, EnumeratorListNode* enumeratorList, TokenNode* rightBrace)
{
	m_nodeType = snt_enum;
	m_keyword = keyword;
	m_keyword2 = keyword2;
	m_name = name;
	m_leftBrace = leftBrace;
	m_enumeratorList = enumeratorList;
	m_rightBrace = rightBrace;
	m_semicolon = 0;
	m_typeNode = 0;
}

TypeNode* EnumNode::getTypeNode()
{
	return m_typeNode;
}

bool EnumNode::isStronglyTypedEnum()
{
	return 0 != m_keyword2;
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

	std::vector<EnumeratorNode*> enumeratorNodes;
	m_enumeratorList->collectEnumeratorNodes(enumeratorNodes);
	size_t count = enumeratorNodes.size();
	std::set<EnumeratorNode*, CompareEnumeratorPtr> items;
	for(size_t i = 0; i < count; ++i)
	{
		EnumeratorNode* enumerator = enumeratorNodes[i];
		auto res = items.insert(enumerator);
		if(!res.second)
		{
			char buf[4096];
			sprintf_s(buf, "\'%s\' : enumerator already defined at line %d, column %d", enumerator->m_name->m_str.c_str(),
				(*res.first)->m_name->m_lineNo, (*res.first)->m_name->m_columnNo);
			ErrorList_AddItem_CurrentFile(enumerator->m_name->m_lineNo,
				enumerator->m_name->m_columnNo, semantic_error_enumerator_redefined, buf);
		}
		enumerator->checkSemantic();
	}
}
