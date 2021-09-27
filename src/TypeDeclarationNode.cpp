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

void TypeDeclarationNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	//assert(enclosingTypeNode->isNamespace() || enclosingTypeNode->isClass());
	assert(0 == m_typeNode);

	switch (enclosingTypeNode->m_category)
	{
	case tc_namespace:
		m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addTypeDeclaration(this);
		break;
	case tc_class_type:
		m_typeNode = static_cast<ClassTypeNode*>(enclosingTypeNode)->addTypeDeclaration(this);
		break;
	default:
		assert(false);
	}
}
