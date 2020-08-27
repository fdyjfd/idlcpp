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

PropertyNode::PropertyNode(IdentifyNode* name, PropertyCategory category)
{
	m_nodeType = snt_property;
	m_modifier = 0;
	m_typeName = 0;
	m_passing = 0;
	m_name = name;
	m_get = 0;
	m_set = 0;
	m_propertyCategory = category;
	m_candidate = false;
	m_keyTypeName = 0;
	m_keyPassing = 0;

}

PropertyCategory PropertyNode::getCategory()
{
	return m_propertyCategory;
}

bool PropertyNode::isStatic()
{
	return (0 != m_modifier && snt_keyword_static == m_modifier->m_nodeType);
}

bool PropertyNode::isSimple()
{
	return simple_property == m_propertyCategory;
}

bool PropertyNode::isFixedArray()
{
	return fixed_array_property == m_propertyCategory;
}

bool PropertyNode::isDynamicArray()
{
	return dynamic_array_property == m_propertyCategory;
}

bool PropertyNode::isList()
{
	return list_property == m_propertyCategory;
}

bool PropertyNode::isMap()
{
	return map_property == m_propertyCategory;
}

bool PropertyNode::hasCandidate()
{
	return m_candidate;
}

bool PropertyNode::isKeyByPtr()
{
	return (0 != m_keyPassing && '*' == m_keyPassing->m_nodeType);
}

bool PropertyNode::isKeyByValue()
{
	return 0 == m_keyPassing;
}

bool PropertyNode::isByValue()
{
	return 0 == m_passing;
}

bool PropertyNode::isByPtr()
{
	return (0 != m_passing && '*' == m_passing->m_nodeType);
}

bool PropertyNode::isByRef()
{
	return (0 != m_passing && '&' == m_passing->m_nodeType);
}

void PropertyNode::setGetter(GetterSetterNode* getter)
{
	assert(snt_keyword_get == getter->m_keyword->m_nodeType);
	m_get = getter;
}

void PropertyNode::setSetter(GetterSetterNode* setter)
{
	assert(snt_keyword_set == setter->m_keyword->m_nodeType);
	m_set = setter;
}

void PropertyNode::setCandidate()
{
	m_candidate = true;
}

void PropertyNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	if (m_keyTypeName)
	{
		m_keyTypeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	}
}

void PropertyNode::checkSemantic(TemplateArguments* templateArguments)
{
	MemberNode::checkSemantic(templateArguments);

	assert(snt_class == m_enclosing->m_nodeType);
	ClassNode* classNode = static_cast<ClassNode*>(m_enclosing);
	TypeNode* typeNode = m_typeName->getTypeNode(templateArguments);
	if (0 == typeNode)
	{
		return;
	}
	if (void_type == typeNode->getTypeCategory(templateArguments) && !isByPtr())
	{
		RaiseError_InvalidPropertyType(this);
	}
	g_compiler.useType(typeNode, templateArguments, isByValue() ? tu_use_definition : tu_use_declaration, m_typeName);
}
