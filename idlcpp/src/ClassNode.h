#pragma once
#include "ScopeNode.h"
#include <vector>

struct TokenNode;
struct TypeNameListNode;
struct MemberListNode;
struct MethodNode;
struct TemplateParametersNode;
struct TypeNameListNode;

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
	IdentifyNode* m_category;
	TokenNode* m_colon;
	TypeNameListNode* m_baseList;
	TokenNode* m_leftBrace;
	TokenNode* m_rightBrace;
	TokenNode* m_semicolon;
	TemplateParametersNode* m_templateParameters;
	TypeNameListNode* m_templateArgumentList;
	std::vector<MethodNode*> m_additionalMethods;//New NewArray Clone
	bool m_isValueType;
	bool m_export;
	LazyBool m_abstractFlag;
	LazyBool m_exportFlag;
public:
	ClassNode(TokenNode* keyword, IdentifyNode* name, IdentifyNode* category);
	void setMemberList(TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace, TokenNode* semicolon);
	void buildAdditionalMethods();
	TypeNameListNode* setTemplateArgumentList(TypeNameListNode* templateArgumentList);
	virtual TypeCategory getTypeCategory();
	virtual void getRelativeName(std::string& relativeName, ScopeNode* scope, TemplateArgumentMap* templateArguments);
	virtual void getTemplateArgumentsName(std::string& relativeName, ScopeNode* scope, TemplateArgumentMap* templateArguments);
	virtual void collectTypeInfo();
	virtual void checkSemantic();
	virtual void checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments);
	virtual void extendInternalCode();
	virtual bool isAbstractClass();
	bool needExport();
	bool isValueType();
	bool hasExportMethod();
	void collectExportMethods(std::vector<MethodNode*>& methodNodes);
	void GenerateCreateInstanceMethod(const char* methodName, MethodNode* constructor);
	void GenerateCreateArrayMethod(const char* methodName, MethodNode* constructor);
};