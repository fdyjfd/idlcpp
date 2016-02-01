#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct ParameterNode;

struct ParameterListNode : SyntaxNodeImpl
{
	ParameterListNode* m_parameterList;
	TokenNode* m_delimiter;
	ParameterNode* m_parameter;
public:
	ParameterListNode(ParameterListNode* parameterList, TokenNode* delimiter, ParameterNode* parameter);
};