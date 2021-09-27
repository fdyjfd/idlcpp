#pragma once

struct IdentifyNode;
struct TypeNameNode;
struct ScopeNameListNode;
struct TokenNode;
struct ParameterNode;
struct MethodNode;
struct OperatorNode;
struct PropertyNode;
struct FieldNode;
struct DelegateNode;

void RaiseError_NestedTemplateClass(IdentifyNode* node);
void RaiseError_InvalidTypeName(IdentifyNode* node);
void RaiseError_InvalidTypeName(ScopeNameListNode* node);
void RaiseError_InvalidTypeName(TypeNameNode* node);
void RaiseError_InvalidParameterType(ParameterNode* node);
void RaiseError_InvalidResultType(MethodNode* node);
void RaiseError_InvalidResultType(OperatorNode* node);
void RaiseError_InvalidResultType(DelegateNode* node);
void RaiseError_InvalidFieldType(FieldNode* node);
void RaiseError_InvalidPropertyType(PropertyNode* node);
void RaiseError_InvalidClassTemplateName(IdentifyNode* node);
void RaiseError_InvalidClassTemplateName(TypeNameNode* node);
void RaiseError_TooManyTemplateArguments(IdentifyNode* node);
void RaiseError_TooFewTemplateArguments(IdentifyNode* node);
void RaiseError_InvalidTemplateArgument(TypeNameNode* node);
void RaiseError_TemplateParameterRedefinition(IdentifyNode* node);
void RaiseError_TemplateClassInstanceInvalidTypeName(const char* typeName, IdentifyNode* node);
void RaiseError_TemplateInterfaceNotSupported(IdentifyNode* node);
void RaiseError_MissingReferenceBaseType(IdentifyNode* node);
void RaiseError_InterfaceMethodIsNotVirtual(IdentifyNode* node);
void RaiseError_TooFewFormalParameters(OperatorNode* node);
void RaiseError_TooManyFormalParameters(OperatorNode* node);
void RaiseError_StaticOperator(OperatorNode* node);
