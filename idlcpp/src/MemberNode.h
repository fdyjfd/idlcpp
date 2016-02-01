#pragma once

#include "SyntaxNodeImpl.h"
#include "TypeNameNode.h"
#include <vector>
#include <string>
#include <map>

struct IdentifyNode;
struct ScopeNode;
struct NamespaceNode;
struct TypeNameNode;

struct MemberNode : SyntaxNodeImpl
{
	IdentifyNode* m_name;
	ScopeNode* m_enclosing;
public:
	MemberNode();
	NamespaceNode* getNamespace();
	void getEnclosings(std::vector<ScopeNode*>& enclosings);
	bool isTemplateClass();
	virtual TypeCategory getTypeCategory();
	virtual void getRelativeName(std::string& relativeName, ScopeNode* scope, TemplateArgumentMap* templateArguments);
	virtual void collectTypeInfo();
	virtual void checkSemantic()
	{}
	virtual void checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments)
	{}
	virtual bool isAbstractClass();
	void getFullName(std::string& fullName, TemplateArgumentMap* templateArguments);
private:
	bool getRelativeName(std::vector<std::string>& names, ScopeNode* scope);
};


struct CompareMemberNodeByName
{
	bool operator()(const MemberNode* m1, const MemberNode* m2) const;
};