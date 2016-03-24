#pragma once 
#include <stdio.h>
#include <vector>
#include <string>
#include "TypeNameNode.h"

class SourceFile;
struct ProgramNode;
struct NamespaceNode;
struct ClassNode;
struct EnumNode;
struct TypeAliasNode;
struct TemplateClassInstanceNode;
struct TokenNode;
struct IdentifyNode;
struct FieldNode;
struct PropertyNode;
struct MethodNode;
struct TypeNameNode;
struct ParameterNode;


class MetaSourceFileGenerator
{
public:
	static void generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName);
public:
	static void generateCode_Program(FILE* file, SourceFile* sourceFile, const char* fullPathName, const char* baseName);
	static void generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation);
	static void generateCode_Enum(FILE* file, EnumNode* enumNode, int indentation);
	static void generateCode_Class(FILE* file, ClassNode* classNode, TemplateArgumentMap* templateArguments, int indentation);
	static void generateCode_Interface(FILE* file, ClassNode* classNode, TemplateArgumentMap* templateArguments, int indentation);
	static void generateCode_TemplateClassInstance(FILE* file, TemplateClassInstanceNode* templateClassInstance, int indentation);
	static void generateCode_TypeAlias(FILE* file, TypeAliasNode* typeAliasNode, int indentation);
};