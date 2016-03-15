#pragma once
#include <string>
#include <vector>
#include <map>

struct MemberNode;
struct TypeNameNode;
enum TypeCategory;
typedef std::map<std::string, TypeNameNode*> TemplateArgumentMap;

struct ExportedTypeInfo
{
	MemberNode* m_typeNode;
	std::string m_typeName;
	ExportedTypeInfo(MemberNode* typeNode, const std::string& typeName)
		: m_typeNode(typeNode), m_typeName(typeName)
	{}
};

inline bool isNotIdentifyChar(char c)
{
	return  !(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || '_' == c);
}


void GetMetaTypeFullName(std::string& metaTypeName, MemberNode* typeNode);
void GetSubclassProxyFullName(std::string& subclassProxyName, MemberNode* typeNode);

TypeCategory CalcTypeFullName(std::string& typeName, TypeNameNode* typeNameNode, TemplateArgumentMap* templateArguments);

void CollectExportedTypeInfos(std::vector<ExportedTypeInfo>& typeInfos, MemberNode* memberNode);
