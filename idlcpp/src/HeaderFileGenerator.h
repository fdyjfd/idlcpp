#pragma once 
#include <stdio.h>
#include <vector>

class SourceFile;
struct ProgramNode;
struct NamespaceNode;
struct TypedefNode;
struct ClassNode;
struct TemplateParametersNode;
struct EnumNode;
struct TokenNode;
struct IdentifyNode;
struct FieldNode;
struct PropertyNode;
struct MethodNode;
struct OperatorNode;
struct TypeNameNode;
struct ParameterNode;
struct ScopeNode;

class HeaderFileGenerator
{
public:
	static void generateCode(FILE* dstFile, SourceFile* sourceFile);
public:
	static void generateCode_Program(FILE* file, SourceFile* sourceFile);
	static void generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation);
	static void generateCode_Enum(FILE* file, EnumNode* enumNode, int indentation);
	static void generateCode_Class(FILE* file, ClassNode* classNode, int indentation);
	static void generateCode_Typedef(FILE* file, TypedefNode* typedefNode, int indentation);
	static void generateCode_Field(FILE* file, FieldNode* fieldNode, int indentation);
	static void generateCode_Property(FILE* file, PropertyNode* propertyNode, int indentation);
	static void generateCode_Property_Get(FILE* file, PropertyNode* propertyNode, int indentation);
	static void generateCode_Property_Set(FILE* file, PropertyNode* propertyNode, int indentation);
	static void generateCode_Method(FILE* file, MethodNode* methodNode, int indentation);
	static void generateCode_Operator(FILE* file, OperatorNode* methodNode, int indentation);
};