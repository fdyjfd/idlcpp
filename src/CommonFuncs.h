#pragma once
#include <string>
#include <vector>
#include <map>

struct MemberNode;
struct TypeNameNode;
enum TypeCategory;
struct TemplateArguments;
struct TypeNode;
struct ClassNode;

inline bool isNotIdentifyChar(char c)
{
	return  !(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || '_' == c);
}


void GetMetaTypeFullName(std::string& metaTypeName, MemberNode* memberNode, TemplateArguments* templateArguments);
void GetMetaTypeFullName(std::string& metaTypeName, TypeNode* typeNode);
void GetSubclassProxyFullName(std::string& subclassProxyName, ClassNode* typeNode, TemplateArguments* templateArguments);
TypeCategory CalcTypeNativeName(std::string& typeName, TypeNameNode* typeNameNode, TemplateArguments* templateArguments);
void CollectTypeNodes(std::vector<TypeNode*>& typeNodes, MemberNode* memberNode);

//void CollectExportedTypeInfos(std::vector<ExportedTypeInfo>& typeInfos, MemberNode* memberNode);
