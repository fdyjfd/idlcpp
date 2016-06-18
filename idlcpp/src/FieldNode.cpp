#include "FieldNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "ClassNode.h"
#include "TypeNameNode.h"
#include "TypeTree.h"
#include "RaiseError.h"
#include "Compiler.h"
#include <assert.h>

FieldNode::FieldNode(TypeNameNode* typeName, IdentifyNode* name, TokenNode* leftBracket, TokenNode* rightBracket, TokenNode* semicolon)
{
	m_nodeType = snt_field;
	m_static = 0;
	m_constant = 0;
	m_typeName = typeName;
	m_name = name;
	m_leftBracket = leftBracket;
	m_rightBracket = rightBracket;
	m_semicolon = semicolon;
}

bool FieldNode::isStatic()
{
	return (0 != m_static);
}

bool FieldNode::isConstant()
{
	return 0 != m_constant;
}

bool FieldNode::isArray()
{
	return (0 != m_leftBracket);
}

void FieldNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments);
}

void FieldNode::checkSemantic(TemplateArguments* templateArguments)
{
	TypeNode* typeNode = m_typeName->getTypeNode(templateArguments);
	if (0 == typeNode)
	{
		return;
	}
	if (void_type == typeNode->getTypeCategory())
	{
		RaiseError_InvalidFieldType(this);
	}
	g_compiler.useType(typeNode, tu_definition, m_typeName);
}

