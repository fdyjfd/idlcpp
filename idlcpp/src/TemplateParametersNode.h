#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct TokenNode;
struct IdentifyNode;
struct TemplateParameterListNode;

struct TemplateParametersNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	TokenNode* m_leftBracket;
	TemplateParameterListNode* m_parameterList;
	TokenNode* m_rightBracket;
public:
	TemplateParametersNode(TokenNode* keyword, TokenNode* leftBracket, TemplateParameterListNode* parameterList, TokenNode* rightBracket);
	void collectParameterNodes(std::vector<std::pair<TokenNode*, IdentifyNode*>>& parameterNodes);
	void collectParameterNodes(std::vector<IdentifyNode*>& parameterNodes);
	size_t getParameterCount();
	bool checkSemantic();
};
