#pragma once
#include "MemberNode.h"

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
	TypeNameNode* m_resultTypeName;
	TokenNode* m_passing;//& * +
	TokenNode* m_leftParenthesis;
	ParameterListNode* m_parameterList;
	TokenNode* m_rightParenthesis;
	TokenNode* m_constant;
	TokenNode* m_semicolon;
	bool m_resultArray;
	bool m_override;
	mutable size_t m_parameterCount;
public:
	MethodNode(IdentifyNode* name, TokenNode* leftParenthesis, ParameterListNode* parameterList, TokenNode* rightParenthesis, TokenNode* constant);
	bool isStatic();
	bool isConstant();
	bool isVirtual();
	bool isAbstract();
	bool byValue();
	bool byRef();
	bool byPtr();
	bool byNew();
	size_t getParameterCount() const;
	void calcManglingName(std::string& name, TemplateArguments* templateArguments);
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};
