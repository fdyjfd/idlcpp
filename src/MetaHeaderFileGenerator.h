#pragma once 
#include <stdio.h>

class SourceFile;
struct ProgramNode;
struct ClassNode;
struct EnumNode;
struct TemplateClassInstanceNode;
struct TypedefNode;
struct TypeDeclarationNode;
struct NamespaceNode;
struct TokenNode;
struct IdentifyNode;
struct FieldNode;
struct PropertyNode;
struct MethodNode;
struct TypeNameNode;
struct ParameterNode;
struct TypeNameListNode;
struct TemplateArguments;
struct DelegateNode;

class MetaHeaderFileGenerator
{
public:
	static void generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName);
public:
	static void generateCode_Program(FILE* file, SourceFile* sourceFile, ProgramNode* programNode, const char* fullPathName, const char* baseName);
	static void generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation);	
	static void generateCode_Enum(FILE* file, EnumNode* enumNode, TemplateArguments* templateArguments, int indentation);
	static void generateCode_Delegate(FILE* file, DelegateNode* delegateNode, TemplateArguments* templateArguments, int indentation);
	static void generateCode_Class(FILE* file, ClassNode* classNode, TemplateClassInstanceNode* templateClassInstance, int indentation);
	static void generateCode_SubclassProxy(FILE* file, ClassNode* classNode, TemplateArguments* templateArguments, int indentation);
	static void generateCode_TemplateClassInstance(FILE* file, TemplateClassInstanceNode* templateClassInstance, int indentation);
	static void generateCode_Typedef(FILE* file, TypedefNode* typedefNode, TemplateArguments* templateArguments, int indentation);
	static void generateCode_TypeDeclaration(FILE* file, TypeDeclarationNode* typeDeclarationNode, TemplateArguments* templateArguments, int indentation);
};