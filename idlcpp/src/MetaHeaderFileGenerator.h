#pragma once 
#include <stdio.h>

class SourceFile;
struct ProgramNode;
struct ClassNode;
struct EnumNode;
struct TemplateClassInstanceNode;
struct TypeAliasNode;
struct NamespaceNode;
struct TokenNode;
struct IdentifyNode;
struct FieldNode;
struct PropertyNode;
struct MethodNode;
struct TypeNameNode;
struct ParameterNode;
struct TypeNameListNode;

class MetaHeaderFileGenerator
{
public:
	static void generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName);
public:
	static void generateCode_Program(FILE* file, ProgramNode* programNode, const char* fullPathName, const char* baseName);
	static void generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation);	
	static void generateCode_Enum(FILE* file, EnumNode* enumNode, int indentation);
	static void generateCode_Class(FILE* file, ClassNode* classNode, int indentation);	
	static void generateCode_Interface(FILE* file, ClassNode* classNode, int indentation);	
	static void generateCode_TemplateClassInstance(FILE* file, TemplateClassInstanceNode* templateClassInstance, int indentation);	
	static void generateCode_TypeAlias(FILE* file, TypeAliasNode* typeAliasNode, int indentation);
};