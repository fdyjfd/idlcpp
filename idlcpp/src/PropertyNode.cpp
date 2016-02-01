#include "PropertyNode.h"
#include "TypeNameNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "GetterSetterNode.h"
#include "SourceFile.h"
#include <assert.h>

PropertyNode::PropertyNode(TokenNode* constant, TypeNameNode* type, TokenNode* passing, IdentifyNode* name)
{
	m_nodeType = snt_property;
	m_modifier = 0;
	m_constant = constant;
	m_type = type;
	m_passing = passing;
	m_name = name;
	m_get = 0;
	m_set = 0;
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

void PropertyNode::setGetter(GetterSetterNode* getter)
{
	assert(snt_keyword_get == getter->m_keyword->m_nodeType);
	m_get = getter;
	if(0 == m_get->m_type)
	{
		m_get->m_constant = m_constant;
		m_get->m_type = m_type;
		m_get->m_passing = m_passing;
	}
}

void PropertyNode::setSetter(GetterSetterNode* setter)
{
	assert(snt_keyword_set == setter->m_keyword->m_nodeType);
	m_set = setter;
	if(0 == m_set->m_type)
	{
		m_set->m_constant = m_constant;
		m_set->m_type = m_type;
		m_set->m_passing = m_passing;
	}
}

void PropertyNode::checkSemantic()
{
	if(m_get)
	{
		m_get->m_type->checkTypeName(m_enclosing);
		g_sourceFileManager.useType(m_get->m_type->m_typeInfo, m_get->byValue() ? ut_by_value : ut_by_ref);
	}
	if(m_set)
	{
		m_set->m_type->checkTypeName(m_enclosing);
		g_sourceFileManager.useType(m_set->m_type->m_typeInfo, m_set->byValue() ? ut_by_value : ut_by_ref);
	}
};

void PropertyNode::checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments)
{	
	m_type->checkTypeNameForTemplateClassInstance(templateClassInstanceNode, templateArguments);
}
