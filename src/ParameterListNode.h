#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct TokenNode;
struct ParameterNode;

struct ParameterListNode : SyntaxNodeImpl
{
	ParameterListNode* m_parameterList;
	TokenNode* m_delimiter;
	ParameterNode* m_parameter;
public:
	ParameterListNode(ParameterListNode* parameterList, TokenNode* delimiter, ParameterNode* parameter);
	void collectParameterNodes(std::vector<std::pair<TokenNode*, ParameterNode*>>& parameterNodes);
	void collectParameterNodes(std::vector<ParameterNode*>& parameterNodes);
};

void checkParameterNames(std::vector<ParameterNode*>& parameterNodes);

