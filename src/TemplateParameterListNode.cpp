#include "TemplateParameterListNode.h"

TemplateParameterListNode::TemplateParameterListNode(TemplateParameterListNode* parameterList, TokenNode* delimiter, IdentifyNode* parameter)
{
	m_nodeType = snt_template_parameter_list;
	m_parameterList = parameterList;
	m_delimiter = delimiter;
	m_parameter = parameter;
}
