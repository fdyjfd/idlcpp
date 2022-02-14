#pragma once

#include "MemberNode.h"
#include "TemplateArguments.h"
#include <vector>

struct TypeNameListNode;
struct TokenListNode;
struct TemplateClassInstanceTypeNode;
struct ClassTypeNode;

struct TemplateClassInstanceNode : MemberNode
{
	TypeNameListNode* m_parameterList;
	TokenListNode* m_tokenList;
	TemplateClassInstanceTypeNode* m_typeNode;
	ClassTypeNode* m_classTypeNode;
	TemplateArguments m_templateArguments;
public:
	TemplateClassInstanceNode(IdentifyNode* name, TypeNameListNode* parameterList);
	virtual TypeNode* getTypeNode();
	virtual void getLocalName(std::string& name, TemplateArguments* templateArguments);
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
	size_t getParameterCount();
	void getReservedMembers(std::vector<IdentifyNode*>& reservedNames,std::vector<TokenNode*>& reservedOperators);
};
