#pragma once

#include "SyntaxNodeImpl.h"
#include "TypeNameNode.h"
#include <vector>
#include <string>
#include <map>

struct IdentifyNode;
struct ScopeNode;
struct ClassNode;
struct NamespaceNode;
struct TypeNameNode;
struct TypeNode;
struct TemplateArguments;
enum TypeCategory;

enum MemberFilter
{
	mf_default,
	mf_meta_only,
	mf_native_only,
};

enum TypeTreeFilter
{
	ttf_type = 1,
	ttf_template_instance = 2,
	ttf_typename = 4,
	ttf_typedef = 8,
	ttf_all = 0xF,
};

struct MemberNode : SyntaxNodeImpl
{
	IdentifyNode* m_name;
	ScopeNode* m_enclosing;
	MemberFilter m_filter;
public:
	MemberNode();
	bool isMetaOnly();
	bool isNativeOnly();
	bool canGenerateMetaCode();
	bool canGenerateNativeCode();
	void getEnclosings(std::vector<ScopeNode*>& enclosings);
	bool isNamespace();
	bool isTemplateClass();
	bool isTypedef();
	void getFullName(std::string& fullName, TemplateArguments* templateArguments);
	virtual TypeNode* getTypeNode();
	virtual void getLocalName(std::string& name, TemplateArguments* templateArguments);
	virtual void collectTypes(TypeNode* enclosingTypeNode);
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};


struct CompareMemberNodeByName
{
	bool operator()(const MemberNode* m1, const MemberNode* m2) const;
};