#include "TypeDeclarationNode.h"
#include "TypeNameNode.h"
#include "RaiseError.h"
#include "Compiler.h"
#include "TypeTree.h"
#include <assert.h>

TypeDeclarationNode::TypeDeclarationNode(IdentifyNode* name, TypeCategory typeCategory)
{
	m_nodeType = snt_type_declaration;
	m_name = name;
	m_typeCategory = typeCategory;
	m_typeNode = 0;
}

TypeNode* TypeDeclarationNode::getTypeNode()
{
	return m_typeNode;
}

void TypeDeclarationNode::collectTypes(TypeNode* enclosingTypeNode)
{
	assert(tc_namespace == enclosingTypeNode->m_category);
	assert(0 == m_typeNode);
	m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addTypeDeclaration(this);
}
