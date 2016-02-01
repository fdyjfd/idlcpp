#pragma once
#include "ScopeNode.h"

struct TokenNode;
struct IdentifyNode;
struct MemberListNode;

struct NamespaceNode : ScopeNode
{
	TokenNode* m_keyword;
	TokenNode* m_leftBrace;
	TokenNode* m_rightBrace;
public:
	NamespaceNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace);
	virtual void collectTypeInfo();
	bool isGlobalNamespace();
	void extendInternalCode();
	virtual void checkSemantic();
};