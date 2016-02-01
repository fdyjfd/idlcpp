#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct TemplateParameterNode;

struct TemplateParameterListNode : SyntaxNodeImpl
{
	TemplateParameterListNode* m_parameterList;
	TokenNode* m_delimiter;
	TemplateParameterNode* m_parameter;
public:
	TemplateParameterListNode(TemplateParameterListNode* parameterList, TokenNode* delimiter, TemplateParameterNode* parameter);
};