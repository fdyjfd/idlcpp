#pragma once

#include "SyntaxNodeImpl.h"

struct IdentifyNode;

struct AttributeNode : SyntaxNodeImpl
{
	IdentifyNode* m_name;
	IdentifyNode* m_content;
public:
	AttributeNode(IdentifyNode* name, IdentifyNode* content);
};

struct CompareAttributePtr
{
	bool operator()(const AttributeNode* arg1, const AttributeNode* arg2) const;
};

