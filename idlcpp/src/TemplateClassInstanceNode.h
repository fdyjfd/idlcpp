#pragma once

#include "MemberNode.h"
#include <vector>

struct TokenNode;
struct ScopeListNode;
struct TypeNameListNode;
struct TypeNameNode;

struct TemplateClassInstanceNode : MemberNode
{
	TokenNode* m_keyword;
	TokenNode* m_keyword2;
	TokenNode* m_leftBracket;
	TypeNameListNode* m_parameterList;
	TokenNode* m_rightBracket;
	TokenNode* m_semicolon;
	TypeNameNode* m_templateTypeNameNode;
	TypeCategory m_typeCategory;
public:
	TemplateClassInstanceNode(TokenNode* keyword, TokenNode* keyword2, IdentifyNode* name, TokenNode* leftBracket, TypeNameListNode* parameterList, TokenNode* rightBracket, TokenNode* semicolon);
	virtual TypeCategory getTypeCategory();
	virtual void getRelativeName(std::string& relativeName, ScopeNode* scope, TemplateArgumentMap* templateArguments);
	virtual void collectTypeInfo();
	virtual void checkSemantic();
	virtual bool isAbstractClass();
	size_t getParameterCount();
};
