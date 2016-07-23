#include "OperatorNode.h"
#include "ParameterListNode.h"
#include "ParameterNode.h"
#include "TypeNameNode.h"
#include "IdentifyNode.h"
#include "ClassNode.h"
#include "ErrorList.h"
#include "RaiseError.h"
#include "TypeTree.h"
#include "Compiler.h"

#include <set>
#include <assert.h>

const char g_strPure[] = { " = 0 " };

OperatorNode::OperatorNode(TokenNode* keyword, TokenNode* sign, TokenNode* leftParenthesis,
	ParameterListNode* parameterList, TokenNode* rightParenthesis, TokenNode* constant, TokenNode* semicolon)
: MethodNode(0, leftParenthesis, parameterList, rightParenthesis, constant)
{
	m_semicolon = semicolon;
	m_nodeType = snt_operator;
	m_keyword = keyword;
	m_sign = sign;
}

void OperatorNode::getOperatorString(std::string& str)
{
	if (m_sign->m_nodeType < 256)
	{
		str = char(m_sign->m_nodeType);
		if ('(' == m_sign->m_nodeType)
		{
			str += ')';
		}
		else if ('[' == m_sign->m_nodeType)
		{
			str += ']';
		}
	}
	else
	{
		assert(snt_begin_output < m_sign->m_nodeType && m_sign->m_nodeType < snt_end_output);
		str = g_keywordTokens[m_sign->m_nodeType - snt_begin_output - 1];
	}
}


void OperatorNode::calcName()
{
	if (m_name)
	{
		return;
	}
	ErrorCode error = no_error;
	size_t paramCount = getParameterCount();
	const char* str = 0;
	switch (m_sign->m_nodeType)
	{
	case '+':
		if (0 == paramCount)
		{
			str = "op_plus";
		}
		else if (1 == paramCount)
		{
			str = "op_add";
		}
		else
		{ 
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	case '-':
		if (0 == paramCount)
		{
			str = "op_negate";
		}
		else if (1 == paramCount)
		{
			str = "op_subtract";
		}
		else
		{
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	case '*':
		if (0 == paramCount)
		{
			str = "op_dereference";
		}
		else if (1 == paramCount)
		{
			str = "op_multiply";
		}
		else
		{
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	case '/':
		if (1 == paramCount)
		{
			str = "op_divide";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '%':
		if (1 == paramCount)
		{
			str = "op_mod";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '^':
		if (1 == paramCount)
		{
			str = "op_bitwiseXor";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '&':
		if (0 == paramCount)
		{
			str = "op_address";
		}
		else if (1 == paramCount)
		{
			str = "op_bitwiseAnd";
		}
		else
		{
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	case '|':
		if (1 == paramCount)
		{
			str = "op_bitwiseOr";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '~':
		if (0 == paramCount)
		{
			str = "op_bitwiseNot";
		}
		else
		{
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	case '!':
		if (0 == paramCount)
		{
			str = "op_not";
		}
		else
		{
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	case '=':
		if (1 == paramCount)
		{
			str = "op_assign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '<':
		if (1 == paramCount)
		{
			str = "op_less";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '>':
		if (1 == paramCount)
		{
			str = "op_greater";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case ',':
		if (1 == paramCount)
		{
			str = "op_comma";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '[':
		if (1 == paramCount)
		{
			str = "op_subscript";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case '(':
		str = "op_call";
		break;
	case snt_operator_add_assign:
		if (1 == paramCount)
		{
			str = "op_addAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_sub_assign:
		if (1 == paramCount)
		{
			str = "op_subtractAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_mul_assign:
		if (1 == paramCount)
		{
			str = "op_multiplyAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_div_assign:
		if (1 == paramCount)
		{
			str = "op_divideAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_mod_assign:
		if (1 == paramCount)
		{
			str = "op_modAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_bit_xor_assign:
		if (1 == paramCount)
		{
			str = "op_bitwiseXorAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_bit_and_assign:
		if (1 == paramCount)
		{
			str = "op_bitwiseAndAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_bit_or_assign:
		if (1 == paramCount)
		{
			str = "op_bitwiseOrAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_left_shift:
		if (1 == paramCount)
		{
			str = "op_leftShift";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_right_shift:
		if (1 == paramCount)
		{
			str = "op_rightShift";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_left_shift_assign:
		if (1 == paramCount)
		{
			str = "op_leftShiftAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_right_shift_assign:
		if (1 == paramCount)
		{
			str = "op_rightShiftAssign";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_equal:
		if (1 == paramCount)
		{
			str = "op_equal";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_not_equal:
		if (1 == paramCount)
		{
			str = "op_notEqual";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_less_equal:
		if (1 == paramCount)
		{
			str = "op_lessEqual";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_greater_equal:
		if (1 == paramCount)
		{
			str = "op_greaterEqual";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_and:
		if (1 == paramCount)
		{
			str = "op_and";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_or:
		if (1 == paramCount)
		{
			str = "op_or";
		}
		else
		{
			error = (0 == paramCount) ? semantic_error_too_few_formal_parameters : semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_inc:
		if (0 == paramCount)
		{
			str = "op_increment";
		}
		else if (1 == paramCount)
		{
			str = "op_postIncrement";
			m_sign->m_nodeType = snt_operator_post_inc;
			m_parameterList = 0;
			m_parameterCount = 0;
		}
		else
		{
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	case snt_operator_dec:
		if (0 == paramCount)
		{
			str = "op_decrement";
		}
		else if (1 == paramCount)
		{
			str = "op_postDecrement";
			m_sign->m_nodeType = snt_operator_post_dec;
			m_parameterList = 0;
			m_parameterCount = 0;
		}
		else
		{
			error = semantic_error_too_many_formal_parameters;
		}
		break;
	default:
		assert(false);
	}
	if (str)
	{
		assert(no_error == error);
		m_name = (IdentifyNode*)newIdentify(str);
	}
	else
	{
		if (semantic_error_too_few_formal_parameters == error)
		{
			RaiseError_TooFewFormalParameters(this);
		}
		else
		{
			assert(semantic_error_too_many_formal_parameters == error);
			RaiseError_TooManyFormalParameters(this);
		}
	}
}


void OperatorNode::checkSemantic(TemplateArguments* templateArguments)
{
	calcName();
	if (m_modifier && snt_keyword_static == m_modifier->m_nodeType)
	{
		RaiseError_StaticOperator(this);
	}
	MethodNode::checkSemantic(templateArguments);

}
