#pragma once
#include "ScopeNode.h"
#include "TemplateArguments.h"
#include <vector>

struct TokenNode;
struct IdentifyListNode;
struct TypeNameListNode;
struct MemberListNode;
struct MethodNode;
struct TemplateParametersNode;
struct TypeNameListNode;
struct TemplateArguments;
struct ClassTypeNode;

struct ClassNode : ScopeNode
{
	enum LazyBool
	{
		lb_false,
		lb_true,
		lb_unknown,
	};
	TokenNode* m_modifier;
	TokenNode* m_keyword;
	//IdentifyListNode* m_conceptList;
	IdentifyNode* m_category;
	TokenNode* m_colon;
	TypeNameListNode* m_baseList;
	TokenNode* m_leftBrace;
	TokenNode* m_rightBrace;
	TokenNode* m_semicolon;
	TemplateParametersNode* m_templateParametersNode;
	ClassTypeNode* m_typeNode;
	TemplateArguments m_templateArguments;
	std::vector<MethodNode*> m_additionalMethods;//New NewARC NewArray
	bool m_isValueType;
	bool m_override;
	LazyBool m_abstractFlag;
	LazyBool m_copyableFlag;
public:
	ClassNode(TokenNode* keyword, IdentifyListNode* conceptList, IdentifyNode* name);
	void setTemplateParameters(TemplateParametersNode* templateParametersNode);
	void setMemberList(TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace);
	void buildAdditionalMethods();
	void extendInternalCode(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	bool isAbstractClass();
	bool isCopyableClass(TemplateArguments* templateArguments);
	bool needSubclassProxy(TemplateArguments* templateArguments);
	bool isValueType();
	bool hasOverrideMethod(TemplateArguments* templateArguments);
	bool isAdditionalMethod(MethodNode* methodNode);
	void collectOverrideMethods(std::vector<MethodNode*>& methodNodes, TemplateArguments* templateArguments);
	void GenerateCreateInstanceMethod(const char* methodName, MethodNode* constructor);
	void GenerateCreateArrayMethod(const char* methodName, MethodNode* constructor);

	virtual TypeNode* getTypeNode();
	virtual void getLocalName(std::string& name, TemplateArguments* templateArguments);
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};