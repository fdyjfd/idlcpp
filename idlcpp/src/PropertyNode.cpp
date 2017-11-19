#include "PropertyNode.h"
#include "TypeNameNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "GetterSetterNode.h"
#include "ClassNode.h"
#include "TypeTree.h"
#include "RaiseError.h"
#include "Compiler.h"
#include <assert.h>

PropertyNode::PropertyNode(IdentifyNode* name, PropertyArrayCategory category)
{
	m_nodeType = snt_property;
	m_modifier = 0;
	m_constant = 0;
	m_typeName = 0;
	m_passing = 0;
	m_name = name;
	m_get = 0;
	m_set = 0;
	m_arrayCategory = category;
}

bool PropertyNode::isStatic()
{
	return (0 != m_modifier && snt_keyword_static == m_modifier->m_nodeType);
}

bool PropertyNode::isVirtual()
{
	return (0 != m_modifier && 
		(snt_keyword_virtual == m_modifier->m_nodeType || 
		snt_keyword_abstract == m_modifier->m_nodeType));
}

bool PropertyNode::isAbstract()
{
	return (0 != m_modifier && snt_keyword_abstract == m_modifier->m_nodeType);
}

bool PropertyNode::isNotArray()
{
	return not_array == m_arrayCategory;
}

bool PropertyNode::isArray()
{
	return not_array != m_arrayCategory;
}

bool PropertyNode::isFixedArray()
{
	return fixed_array == m_arrayCategory;
}

bool PropertyNode::isDynamicArray()
{
	return dynamic_array == m_arrayCategory;
}

bool PropertyNode::byPtr()
{
	return (0 != m_passing && '*' == m_passing->m_nodeType);
}

void PropertyNode::setGetter(GetterSetterNode* getter)
{
	assert(snt_keyword_get == getter->m_keyword->m_nodeType);
	m_get = getter;
	if(0 == m_get->m_typeName)
	{
		m_get->m_constant = m_constant;
		m_get->m_typeName = m_typeName;
		m_get->m_passing = m_passing;
	}
}

void PropertyNode::setSetter(GetterSetterNode* setter)
{
	assert(snt_keyword_set == setter->m_keyword->m_nodeType);
	m_set = setter;
	if(0 == m_set->m_typeName)
	{
		m_set->m_constant = m_constant;
		m_set->m_typeName = m_typeName;
		m_set->m_passing = m_passing;
	}
}

void PropertyNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	if (m_get && m_get->m_typeName != m_typeName)
	{
		m_get->m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	}
	if (m_set && m_set->m_typeName != m_typeName)
	{
		m_set->m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	}
}

void PropertyNode::checkSemantic(TemplateArguments* templateArguments)
{
	MemberNode::checkSemantic(templateArguments);

	assert(snt_class == m_enclosing->m_nodeType);
	ClassNode* classNode = static_cast<ClassNode*>(m_enclosing);
	if(m_get)
	{
		TypeNode* typeNode = m_get->m_typeName->getTypeNode(templateArguments);
		if (0 == typeNode)
		{
			return;
		}
		if (void_type == typeNode->getTypeCategory(templateArguments) && !byPtr())
		{
			RaiseError_InvalidPropertyType(m_get, true);
		}
		g_compiler.useType(typeNode, templateArguments, m_get->byValue() ? tu_use_definition : tu_use_declaration, m_get->m_typeName);
	}
	if(m_set)
	{
		TypeNode* typeNode = m_set->m_typeName->getTypeNode(templateArguments);
		if (0 == typeNode)
		{
			return;
		}
		if (void_type == typeNode->getTypeCategory(templateArguments) && !byPtr())
		{
			RaiseError_InvalidPropertyType(m_set, false);
		}
		g_compiler.useType(typeNode, templateArguments, m_set->byValue() ? tu_use_definition : tu_use_declaration, m_set->m_typeName);
	}
};
