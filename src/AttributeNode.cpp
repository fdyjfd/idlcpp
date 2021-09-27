#include "AttributeNode.h"
#include "IdentifyNode.h"

AttributeNode::AttributeNode(IdentifyNode* name, IdentifyNode* content, bool u8content)
{
	m_nodeType = snt_attribute;
	m_name = name;
	m_content = content;
	m_u8content = u8content;
}

bool CompareAttributePtr::operator()(const AttributeNode* arg1, const AttributeNode* arg2) const
{
	return arg1->m_name->m_str < arg2->m_name->m_str;
}

