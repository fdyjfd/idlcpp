#pragma once
#include "MemberNode.h"
#include <vector>

struct SyntaxNodeImpl;
struct TokenNode;
struct ParameterListNode;
struct ParameterNode;
struct TypeNameNode;

struct MethodNode : MemberNode
{
public:
	TokenNode* m_modifier;
	TokenNode* m_resultConst;
	TypeNameNode* m_result;
	TokenNode* m_passing;//REF PTR NEW
	TokenNode* m_leftParenthesis;
	ParameterListNode* m_parameterList;
	TokenNode* m_rightParenthesis;
	TokenNode* m_constant;
	TokenNode* m_semicolon;
	bool m_resultArray;
	bool m_override;
public:
	MethodNode(IdentifyNode* name, TokenNode* leftParenthesis, ParameterListNode* parameterList, TokenNode* rightParenthesis, TokenNode* constant, TokenNode* semicolon);
	bool isStatic();
	bool isConstant();
	bool isVirtual();
	bool isAbstract();
	bool byValue();
	bool byRef();
	bool byPtr();
	bool byNew();
	size_t getParameterCount();
	void collectParameterNodes(std::vector<std::pair<TokenNode*, ParameterNode*>>& parameterNodes);
	void collectParameterNodes(std::vector<ParameterNode*>& parameterNodes);
	virtual void checkSemantic();
	virtual void checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments);
};
