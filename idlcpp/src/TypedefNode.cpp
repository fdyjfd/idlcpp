#include "TypedefNode.h"
#include "TypeNameNode.h"
#include "RaiseError.h"
#include "Compiler.h"
#include "TemplateArguments.h"
#include "TypeTree.h"

#include <assert.h>

TypedefNode::TypedefNode(TokenNode* keyword, IdentifyNode* name, TypeNameNode* typeName)
{
	m_nodeType = snt_typedef;
	m_keyword = keyword;
	m_name = name;
	m_typeName = typeName;
	m_typeNode = 0;
	m_srcTypeNode = 0;
}

TypeNode* TypedefNode::getTypeNode()
{
	return m_typeNode;
}

void TypedefNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	//assert(enclosingTypeNode->isNamespace() || enclosingTypeNode->isClass());
	assert(0 == m_srcTypeNode && 0 == m_typeNode);
	if (m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments))
	{
		m_srcTypeNode = m_typeName->m_typeNode;//null means under template parameter
		if (m_srcTypeNode && m_srcTypeNode->isTypedef())
		{
			m_srcTypeNode = static_cast<TypedefTypeNode*>(m_srcTypeNode)->m_typedefNode->m_srcTypeNode;
			assert(!m_srcTypeNode->isTypedef());
		}
		switch (enclosingTypeNode->m_category)
		{
		case tc_namespace:
			m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addTypedef(this);
			break;
		case tc_class_type:
			m_typeNode = static_cast<ClassTypeNode*>(enclosingTypeNode)->addTypedef(this);
			break;
		default:
			assert(false);
		}
	}
}

TypeNode* TypedefNode::getActualTypeNode(TemplateArguments* templateArguments)
{
	if (m_srcTypeNode)
	{
		return m_srcTypeNode->getActualTypeNode(templateArguments);
	}
	else
	{
		//under template parameter
		if (templateArguments->m_classTypeNode->isTemplateClass())
		{
			return 0;
		}
		else
		{
			assert(templateArguments->m_classTypeNode->isTemplateClassInstance());
			return m_typeName->getTypeNode(templateArguments);
		}
	}
}

void TypedefNode::checkSemantic(TemplateArguments* templateArguments)
{
	TypeNode* typeNode = m_typeName->getTypeNode(templateArguments);
	g_compiler.useType(typeNode, templateArguments, TypeUsage(tu_use_definition | tu_use_meta), m_typeName);
}
