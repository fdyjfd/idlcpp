#pragma once

#include "SyntaxNodeImpl.h"

struct IdentifyNode;

struct AttributeNode : SyntaxNodeImpl
{
	IdentifyNode* m_name;
	IdentifyNode* m_content;
	bool m_u8content;
public:
	AttributeNode(IdentifyNode* name, IdentifyNode* content, bool u8content);
};

struct CompareAttributePtr
{
	bool operator()(const AttributeNode* arg1, const AttributeNode* arg2) const;
};

