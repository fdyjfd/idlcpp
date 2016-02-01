#pragma once

struct IdentifyNode;
struct TypeNameNode;

void RaiseError_InvalidTypeName(IdentifyNode* node);
void RaiseError_InvalidTypeName(TypeNameNode* node);
void RaiseError_InvalidClassTemplateName(IdentifyNode* node);
void RaiseError_TooManyTemplateArguments(IdentifyNode* node);
void RaiseError_TooFewTemplateArguments(IdentifyNode* node);
void RaiseError_InvalidTemplateArgument(TypeNameNode* node);
void RaiseError_TemplateParameterRedefinition(IdentifyNode* node);
void RaiseError_TemplateClassInstanceInvalidTypeName(const char* typeName, IdentifyNode* node);
void RaiseError_TemplateInterfaceNotSupported(IdentifyNode* node);
void RaiseError_MissingReferenceBaseType(IdentifyNode* node);
void RaiseError_InterfaceMethodIsNotVirtual(IdentifyNode* node);
