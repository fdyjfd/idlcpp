#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct IdentifyNode;
struct TemplateParameterListNode : SyntaxNodeImpl
{
	TemplateParameterListNode* m_parameterList;
	TokenNode* m_delimiter;
	IdentifyNode* m_parameter;
public:
	TemplateParameterListNode(TemplateParameterListNode* parameterList, TokenNode* delimiter, IdentifyNode* parameter);
};