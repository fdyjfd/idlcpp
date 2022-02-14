#pragma once
#include "MethodNode.h"
#include <vector>

struct OperatorNode : MethodNode
{
public:
	TokenNode* m_keyword;
	TokenNode* m_sign;
public:
	OperatorNode(TokenNode* keyword, TokenNode* sign, TokenNode* leftParenthesis, 
		ParameterListNode* parameterList, TokenNode* rightParenthesis, TokenNode* constant, TokenNode* semicolon);
	void getOperatorString(std::string& str);
	virtual void checkSemantic(TemplateArguments* templateArguments);
private:
	void calcName();
};
