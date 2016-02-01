#pragma once 
#include <stdio.h>
#include <vector>

class SourceFile;
struct ProgramNode;
struct NamespaceNode;
struct TypeAliasNode;
struct ClassNode;
struct TemplateParametersNode;
struct EnumNode;
struct TemplateParameterNode;
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
	static void generateCode_Class(FILE* file, ClassNode* classNode, int indentation);
	static void generateCode_TemplateHeader(FILE* file, ClassNode* classNode, int indentation);
	static void generateCode_AdditionalMethod(FILE* file, MethodNode* methodNode, int indentation);
};