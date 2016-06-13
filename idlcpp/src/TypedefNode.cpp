#include "TypedefNode.h"
#include "TypeNameNode.h"
#include "RaiseError.h"
#include "Compiler.h"
#include "TypeTree.h"
#include <assert.h>

TypedefNode::TypedefNode(TokenNode* keyword, IdentifyNode* name, TypeNameNode* typeName)
{
	m_nodeType = snt_typedef;
	m_keyword = keyword;
	m_name = name;
	m_typeName = typeName;
	m_typeNode = 0;
	m_actualTypeNode = 0;
}

TypeNode* TypedefNode::getTypeNode()
{
	return m_typeNode;
}

void TypedefNode::collectTypes(TypeNode* enclosingTypeNode)
{
	assert(enclosingTypeNode->isNamespace());
	assert(0 == m_actualTypeNode && 0 == m_typeNode);
	if (m_typeName->calcTypeNodes(enclosingTypeNode, 0))
	{
		m_actualTypeNode = m_typeName->m_typeNode;
		if (m_actualTypeNode->isTypedef())
		{
			m_actualTypeNode = static_cast<TypedefTypeNode*>(m_actualTypeNode)->m_typedefNode->m_actualTypeNode;
			assert(!m_actualTypeNode->isTypedef());
		}
		m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addTypedef(this);
	}
}
