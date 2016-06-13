#pragma once
#include "SyntaxNodeImpl.h"
#include <vector>
#include <string>


struct IdentifyNode;
struct TokenNode;
struct TypeNameListNode;
struct TypeNode;
struct TemplateArguments;

struct ScopeNameNode : SyntaxNodeImpl
{
	IdentifyNode* m_name;
	TokenNode* m_leftBracket;
	TypeNameListNode* m_parameterList;
	TokenNode* m_rightBracket;
public:
	ScopeNameNode(IdentifyNode* name, TokenNode* leftBracket, TypeNameListNode* parameterList, TokenNode* rightBracket);
	bool calcTemplateParametersTypeNodes(TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments);
	void getString(std::string& str);
	bool isTemplateForm();
};

