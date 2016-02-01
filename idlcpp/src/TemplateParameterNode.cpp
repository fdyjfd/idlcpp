#include "TemplateParameterNode.h"

TemplateParameterNode::TemplateParameterNode(TokenNode* keyword, IdentifyNode* name)
{
	m_nodeType = snt_template_parameter;
	m_keyword = keyword;
	m_name = name;
}
