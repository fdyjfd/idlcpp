#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct IdentifyNode;

struct TemplateParameterNode : SyntaxNodeImpl
{
	TokenNode* m_keyword;
	IdentifyNode* m_name;
public:
	TemplateParameterNode(TokenNode* keyword, IdentifyNode* name);
};
