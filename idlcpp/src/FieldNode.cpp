#include "FieldNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "TypeNameNode.h"
#include "SourceFile.h"

FieldNode::FieldNode(TypeNameNode* type, IdentifyNode* name, TokenNode* leftBracket, TokenNode* rightBracket, TokenNode* semicolon)
{
	m_nodeType = snt_field;
	m_static = 0;
	m_constant = 0;
	m_type = type;
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

void FieldNode::checkSemantic()
{
	m_type->checkTypeName(m_enclosing);
	g_sourceFileManager.useType(m_type->m_typeInfo, tu_by_value);
}

void FieldNode::checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments)
{
	m_type->checkTypeNameForTemplateClassInstance(templateClassInstanceNode, templateArguments);
}