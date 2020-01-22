#pragma once

#include "SyntaxNodeImpl.h"
#include "TypeNameNode.h"
#include <vector>
#include <string>
#include <map>

struct ProgramNode;
struct IdentifyNode;
struct ScopeNode;
struct ClassNode;
struct NamespaceNode;
struct TypeNameNode;
struct TypeNode;
struct TemplateArguments;
struct AttributeListNode;
enum TypeCategory;
class SourceFile;

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
	AttributeListNode* m_attributeList;
	IdentifyNode* m_name;
	ScopeNode* m_enclosing;
	TokenNode* m_filterNode;
	IdentifyNode* m_nativeName;
	int m_orderIndex;//for field & property syntax order
public:
	MemberNode();
	bool isNoCode();
	bool isNoMeta();
	bool canGenerateMetaCode();
	bool canGenerateNativeCode();
	void getEnclosings(std::vector<ScopeNode*>& enclosings);
	bool isNamespace();
	bool isTemplateClass();
	bool isTypedef();
	void getFullName(std::string& fullName, TemplateArguments* templateArguments);
	void getNativeName(std::string& nativeName, TemplateArguments* templateArguments);
	ProgramNode* getProgramNode();
	SourceFile* getSourceFile();
	std::string getSourceFilePath();
	virtual TypeNode* getTypeNode();
	virtual void getLocalName(std::string& name, TemplateArguments* templateArguments);
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};


struct CompareMemberNodeByName
{
	bool operator()(const MemberNode* m1, const MemberNode* m2) const;
};