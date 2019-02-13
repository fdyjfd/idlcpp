#pragma once
#include "MemberNode.h"

struct SyntaxNodeImpl;
struct TokenNode;
struct ParameterListNode;
struct ParameterNode;
struct TypeNameNode;
struct ClassNode;

struct DelegateNode : MemberNode
{
public:
	TokenNode* m_keyword;
	TokenNode* m_resultConst;
	TypeNameNode* m_resultTypeName;
	TokenNode* m_passing;//& * +
	TokenNode* m_leftParenthesis;
	ParameterListNode* m_parameterList;
	TokenNode* m_rightParenthesis;
	TokenNode* m_semicolon;
	bool m_resultArray;
	mutable size_t m_parameterCount;
	ClassNode* m_classNode;
public:
	bool byValue();
	bool byRef();
	bool byPtr();
	bool byNew();
	DelegateNode(IdentifyNode* name, TokenNode* leftParenthesis, ParameterListNode* parameterList, TokenNode* rightParenthesis, TokenNode* semicolon);
	size_t getParameterCount() const;
	void extendInternalCode(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};
