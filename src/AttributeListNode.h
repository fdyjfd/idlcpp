#pragma once

#include "SyntaxNodeImpl.h"
#include <vector>

struct AttributeNode;

struct AttributeListNode : SyntaxNodeImpl
{
	AttributeListNode* m_attributeList;
	AttributeNode* m_attribute;
public:
	AttributeListNode(AttributeListNode* attributeList, AttributeNode* attribute);
	void collectAttributeNodes(std::vector<AttributeNode*>& attributeNodes);
	void checkSemantic();
};

void checkAttributeNames(std::vector<AttributeNode*>& attributeNodes);
