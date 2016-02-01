#include "ParameterListNode.h"

ParameterListNode::ParameterListNode(ParameterListNode* parameterList, TokenNode* delimiter, ParameterNode* parameter)
{
	m_nodeType = snt_parameter_list;
	m_parameterList = parameterList;
	m_delimiter = delimiter;
	m_parameter = parameter;
}
