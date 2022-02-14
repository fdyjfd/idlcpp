#pragma once 
#include <stdio.h>
#include <vector>
#include <string>

class SourceFile;
struct ProgramNode;
struct NamespaceNode;
struct TypedefNode;
struct ClassNode;
struct DelegateNode;
struct TemplateParametersNode;
struct EnumNode;
struct TokenNode;
struct IdentifyNode;
struct FieldNode;
struct PropertyNode;
struct MethodNode;
struct TypeNameNode;
struct ParameterNode;
struct ScopeNode;


class SourceFileGenerator
{
public:
	static void generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName);
public:
	static void generateCode_Program(FILE* file, ProgramNode* programNode, const char* fileName, const char* cppName);
	static void generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation);
	static void generateCode_Class(FILE* file, ClassNode* classNode, const std::string& scopeClassName, int indentation);
	static void generateCode_Delegate(FILE* file, DelegateNode* delegateNode, ScopeNode* scopeNode, const std::string& scopeClassName, int indentation);
	static void generateCode_TemplateHeader(FILE* file, ClassNode* classNode, int indentation);
	static void generateCode_AdditionalMethod(FILE* file, MethodNode* methodNode, const std::string& typeName, int indentation);
};