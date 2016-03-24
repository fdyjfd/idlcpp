#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

int enterSourceFile(const char* fileName);
int leaveSourceFile();
const char* getCurrentSourceFileName();
const char* getMainSourceFileName();

const int import_file_failed			= -1;
const int import_file_succeeded			= 0;
const int import_file_already_import	= 1;

//void setCurrentPackageName(const char* name);

void addSourceFile(const char* fileName);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>
#include <set>
#include <map>
#include <vector>

struct ProgramNode;
struct MemberNode;
struct ClassNode;
struct TypeAliasNode;
struct NamespaceNode;
struct TemplateClassInstanceNode;
struct IdentifyNode;
struct ScopeNode;
struct TokenNode;

struct EmbededCode
{
	int m_tokenNo;
	std::string m_code;
};

class SourceFile
{
public:
	SourceFile()
	{
		m_syntaxTree = 0;
		m_currentEmbededCode = 0;
	}
	~SourceFile();
public:
	void addEmbededCodeBlock(const char* str, int tokenNo);
	char outputEmbededCodes(FILE* file, int tokenNo);
public:
	std::string m_fileName;
	ProgramNode* m_syntaxTree;
	std::vector<EmbededCode*> m_embededCodes;
	size_t m_currentEmbededCode;
	std::vector<SourceFile*> m_importSourceFiles;
};

struct TypeInfo
{
	MemberNode* m_typeNode;
	SourceFile* m_sourceFile;
public:
	TypeInfo(MemberNode* typeNode, SourceFile* sourceFile)
	{
		m_typeNode = typeNode;
		m_sourceFile = sourceFile;
	}
};

struct NamespaceInfo
{
	NamespaceNode* m_namespaceNode;
	SourceFile* m_sourceFile;
	NamespaceInfo(NamespaceNode* namespaceNode, SourceFile* sourceFile)
	{
		m_namespaceNode = namespaceNode;
		m_sourceFile = sourceFile;
	}
};

enum TypeUsage
{
	tu_as_base = 1,
	tu_by_value = 2,
	tu_by_ref = 4,
};

struct UsedType
{
	TypeInfo* typeInfo;
	int usage;
	bool operator == (const UsedType& arg) const
	{
		return typeInfo == arg.typeInfo;
	}
};

enum NameCategory
{
	nc_namespace = 1,
	nc_type = 2,
	//nc_class_template = 4,
	nc_all = 7,
};

class SourceFileManager
{
public:
	SourceFileManager();
public:
	int addSourceFile(const char* fileName);
	SourceFile* popSourceFile();
	void prepareParse(SourceFile* sourceFile, bool main);
	void attachSyntaxTree(ProgramNode* programNode);
	void checkTypeInfos();
	void checkSemantic();
	void useType(TypeInfo* typeInfo, TypeUsage usage);
	void outputUsedTypes(FILE* file, SourceFile* sourceFile);
	void outputUsedTypesForMetaSource(FILE* file, SourceFile* sourceFile);
	bool generateCode(const char* fileName);
	bool generateHeaderFile(const char* fileName);
	bool generateSourceFile(const char* fileName, const char* cppName);
	bool generateMetaHeaderFile(const char* fileName, const char* cppName);
	bool generateMetaSourceFile(const char* fileName, const char* cppName);
	char outputEmbededCodes(FILE* file, TokenNode* tokenNode);
	void registerNamespace(NamespaceNode* namespaceNode);
	void registerType(MemberNode* typeNode);
	void checkNameForRegister_(MemberNode* memberNode, const std::string& name, int nameCategories);
	TypeInfo* findTypeInfo(IdentifyNode* identifyNode, const std::string& typeName, bool isGlobal, ScopeNode* scopeNode);
private:
	void insertUnParsedSourceFile(const std::string& fileName);
public:
	SourceFile* m_currentSourceFile;
	SourceFile* m_mainSourceFile;
	int m_currentLineNo;
	bool m_outputLineDirective;
	size_t m_insertSourceFilePosition;
	std::vector<SourceFile*> m_unParsedSourceFiles;

	std::set<std::string> m_sourceFileNames;
	std::map<std::string, std::vector<NamespaceInfo>> m_namespaceInfos;
	std::map<std::string, TypeInfo> m_typeInfos;
	//std::map<std::string, TypeInfo> m_classTemplateTypeInfos;
	std::vector<UsedType> m_usedTypes;
};


extern SourceFileManager g_sourceFileManager;

#endif
