#pragma once
#include <string>
#include <set>
#include <map>
#include <vector>

const char* getCurrentSourceFileName();

const int import_file_failed = -1;
const int import_file_succeeded = 0;
const int import_file_already_import = 1;



struct TokenNode;
struct IdentifyNode;
struct ScopeNode;
struct MemberNode;
struct ClassNode;
struct TypedefNode;
struct NamespaceNode;
struct TemplateClassInstanceNode;
struct ProgramNode;
struct TypeNameNode;
struct TemplateArguments;

class SourceFile;
struct TypeNode;

enum TypeUsage
{
	tu_use_definition = 1,
	tu_use_declaration = 2,
	tu_use_meta = 4,
	tu_use_all = 7,
};

struct UsedType
{
	TypeNode* typeNode;
	int usage;
	int tokenNo;
	bool operator == (const UsedType& arg) const
	{
		return typeNode == arg.typeNode;
	}
};


bool compareFileName(const std::string& str1, const std::string& str2);

struct CompareFileName
{
	bool operator () (const std::string& str1, const std::string& str2) const
	{
		return compareFileName(str1, str2);
	}
};

class Compiler
{
public:
	Compiler();
public:
	int addSourceFile(const char* fileName);
	SourceFile* popSourceFile();
	void prepareParse(SourceFile* sourceFile, bool main);
	void attachSyntaxTree(ProgramNode* programNode);
	void collectTypes();
	void extendInternalCode();
	void checkTypeNames();
	void checkSemantic();
	void useType(TypeNode* typeNode, TemplateArguments* templateArguments, TypeUsage usage, TypeNameNode* typeNameNode);
	void useType(TypeNode* typeNode, TypeUsage usage, TypeNameNode* typeNameNode);
	void outputUsedTypes(FILE* file, SourceFile* sourceFile);
	void outputUsedTypesForMetaHeader(FILE* file, SourceFile* sourceFile);
	void outputUsedTypesForMetaSource(FILE* file, SourceFile* sourceFile);
	bool generateCode(const char* fileName);
	bool generateHeaderFile(const char* fileName);
	bool generateSourceFile(const char* fileName, const char* cppName);
	bool generateMetaHeaderFile(const char* fileName, const char* cppName);
	bool generateMetaSourceFile(const char* fileName, const char* cppName);
	void outputEmbededCodes(FILE* file, TokenNode* tokenNode);
private:
	void insertUnParsedSourceFile(const std::string& fileName);
public:
	SourceFile* m_currentSourceFile;
	SourceFile* m_mainSourceFile;
	int m_currentLineNo;
	bool m_outputLineDirective;
	size_t m_insertSourceFilePosition;
	std::vector<SourceFile*> m_unParsedSourceFiles;
	std::set<std::string, CompareFileName> m_sourceFileNames;
	std::vector<UsedType> m_usedTypes;
};


extern Compiler g_compiler;