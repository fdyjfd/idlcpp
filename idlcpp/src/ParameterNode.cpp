#include "ParameterNode.h"
#include "TypeNameNode.h"
#include "IdentifyNode.h"
#include "MethodNode.h"
#include "SourceFile.h"
#include <assert.h>

ParameterNode::ParameterNode(TypeNameNode* type, TokenNode* out, TokenNode* passing, IdentifyNode* name)
{
	m_nodeType = snt_parameter;
	m_constant = 0;
	m_type = type;
	m_out = out;
	m_passing = passing;
	m_name = name;
	m_array = false;
}

bool ParameterNode::isConstant()
{
	return (0 != m_constant && snt_keyword_const == m_constant->m_nodeType);
}

bool ParameterNode::byValue()
{
	return 0 == m_passing;
}

bool ParameterNode::byPtr()
{
	return (0 != m_passing && snt_keyword_ptr == m_passing->m_nodeType);
}

bool ParameterNode::byRef()
{
	return (0 != m_passing && snt_keyword_ref == m_passing->m_nodeType);
}

bool ParameterNode::outNew()
{
	return (0 != m_out && snt_keyword_new == m_out->m_nodeType);
}

bool ParameterNode::isArray()
{
	return m_array;
}

bool ParameterNode::isInput()
{
	return 0 == m_out;
}

bool ParameterNode::isOutput()
{
	return 0 != m_out;
}

void ParameterNode::checkSemantic(MethodNode* methodNode)
{
	m_type->checkTypeName(methodNode->m_enclosing);
	g_sourceFileManager.useType(m_type->m_typeInfo, byValue() ? tu_by_value : tu_by_ref);
}
