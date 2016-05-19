#pragma once

#ifdef __cplusplus
extern "C"
{
#endif


void lexError(int errorCode, const char* errorText);

struct SyntaxNode
{
	int m_nodeType;
};
typedef struct SyntaxNode SyntaxNode;

enum PrimitiveType
{
	pt_unknown,
	pt_void,
	pt_bool,
	pt_char,
	pt_schar,
	pt_uchar,
	pt_wchar_t,
	pt_short,
	pt_ushort,
	pt_long,
	pt_ulong,
	pt_longlong,
	pt_ulonglong,
	pt_int,
	pt_uint,
	pt_float,
	pt_double,
	pt_long_double,
};

typedef enum PrimitiveType PrimitiveType;

enum TypeCategory
{
	unknown_type,
	type_not_found,
	void_type,
	primitive_type,
	enum_type,
	value_type,
	reference_type,
	class_template,
	template_parameter,
};

typedef enum TypeCategory TypeCategory;

enum SyntaxNodeType
{
	snt_keyword_all = 258,

	snt_keyword_native,
	snt_keyword_meta,
	snt_keyword_none,

	snt_keyword_begin_primitive,
	snt_keyword_bool,
	snt_keyword_char,
	snt_keyword_wchar_t,
	snt_keyword_short,
	snt_keyword_long,
	snt_keyword_int,
	snt_keyword_signed,
	snt_keyword_unsigned,
	snt_keyword_float,
	snt_keyword_double,
	snt_keyword_end_primitive,

	snt_keyword_begin_output,
	snt_keyword_namespace,
	snt_keyword_enum,
	snt_keyword_class,
	snt_keyword_struct,
	snt_keyword_void,
	snt_keyword_abstract,
	snt_keyword_virtual,
	snt_keyword_static,
	snt_keyword_const,
	snt_keyword_get,
	snt_keyword_set,
	snt_keyword_new,
	snt_keyword_ptr,
	snt_keyword_ref,
	snt_keyword_typedef,
	snt_keyword_end_output,
	snt_keyword_scope,
	snt_keyword_export,
	snt_keyword_override,
	snt_identify,
	snt_scope_list,
	snt_enumerator_list,
	snt_type_name,
	snt_type_name_list,
	snt_parameter,
	snt_parameter_list,
	snt_template_parameter,
	snt_template_parameter_list,
	snt_template_parameters,
	snt_getter_setter,
	snt_field,
	snt_property,
	snt_method,
	snt_class,
	snt_enum,
	snt_template_class_instance,
	snt_type_alias,
	snt_namespace,
	snt_member_list,
};

void newCodeBlock(const char* str);
SyntaxNode* newToken(int nodeType);
SyntaxNode* newIdentify(const char* str);
SyntaxNode* newPrimitiveType(SyntaxNode* keyword, PrimitiveType type);
SyntaxNode* newScopeList(SyntaxNode* scopeList, SyntaxNode* identify);
void setScopeListGlobal(SyntaxNode* scopeList);
SyntaxNode* newTypeName(SyntaxNode* scopeList);
SyntaxNode* newTemplateTypeName(SyntaxNode* scopeList, SyntaxNode* lts, SyntaxNode* parameterList, SyntaxNode* gts);
SyntaxNode* newTypeNameList(SyntaxNode* typeNameList, SyntaxNode* delimiter, SyntaxNode* typeName);

void setMetaOnly(SyntaxNode* syntaxNode);
void setNativeOnly(SyntaxNode* syntaxNode);
SyntaxNode* newField(SyntaxNode* type, SyntaxNode* name, SyntaxNode* leftBracket, SyntaxNode* rightBracket, SyntaxNode* semicolon);
void setFieldConstant(SyntaxNode* syntaxNode, SyntaxNode* constant);
void setFieldStatic(SyntaxNode* syntaxNode, SyntaxNode* stat);

SyntaxNode* newGetterSetter(SyntaxNode* keyword, SyntaxNode* constant, SyntaxNode* type, SyntaxNode* passing);

SyntaxNode* newProperty(SyntaxNode* constant, SyntaxNode* type, SyntaxNode* passing, SyntaxNode* name);
void setPropertyGetter(SyntaxNode* property, SyntaxNode* getter);
void setPropertySetter(SyntaxNode* property, SyntaxNode* setter);
void setPropertyModifier(SyntaxNode* syntaxNode, SyntaxNode* modifier);

SyntaxNode* newParameter(SyntaxNode* type, SyntaxNode* out, SyntaxNode* passing, SyntaxNode* name);
void setParameterArray(SyntaxNode* parameter);
void setParameterConst(SyntaxNode* parameter, SyntaxNode* constant);
SyntaxNode* newParameterList(SyntaxNode* parameterList, SyntaxNode* delimiter, SyntaxNode* parameter);

SyntaxNode* newMethod(SyntaxNode* name, SyntaxNode* leftParenthesis, SyntaxNode* parameterList, SyntaxNode* rightParenthesis, SyntaxNode* constant, SyntaxNode* semicolon);
void setMethodResult(SyntaxNode* method, SyntaxNode* result, SyntaxNode* passing);
void setMethodResultArray(SyntaxNode* method);
void setMethodResultConst(SyntaxNode* method, SyntaxNode* constant);
void setMethodModifier(SyntaxNode* method, SyntaxNode* modifier);
void setMethodOverride(SyntaxNode* method);

SyntaxNode* newClassMemberList(SyntaxNode* memberList, SyntaxNode* member);
SyntaxNode* newClass(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* category);
void setClassBaseList(SyntaxNode* cls, SyntaxNode* colon, SyntaxNode* baseList);
void setClassMemberList(SyntaxNode* cls, SyntaxNode* leftBrace, SyntaxNode* memberList, SyntaxNode* rightBrace, SyntaxNode* semicolon);
void setClassModifier(SyntaxNode* cls, SyntaxNode* modifier);
void setClassOverride(SyntaxNode* cls);
void setClassTemplateParameters(SyntaxNode* cls, SyntaxNode* parameters);

SyntaxNode* newEnumeratorList(SyntaxNode* enumeratorList, SyntaxNode* delimiter, SyntaxNode* identify);
SyntaxNode* newEnum(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* leftBrace, SyntaxNode* enumeratorList, SyntaxNode* rightBrace, SyntaxNode* semicolon);

SyntaxNode* newTypeAlias(SyntaxNode* name, TypeCategory typeCategory);
SyntaxNode* newTypeDef(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* typeName);

SyntaxNode* newTemplateParameterList(SyntaxNode* list, SyntaxNode* delimiter, SyntaxNode* identify);
SyntaxNode* newTemplateParameters(SyntaxNode* lts, SyntaxNode* parameterList, SyntaxNode* gts);

SyntaxNode* newTemplateClassInstance(SyntaxNode* keyword, SyntaxNode* templateName, SyntaxNode* lts, SyntaxNode* typeNameList, SyntaxNode* gts, SyntaxNode* semicolon);
SyntaxNode* newNamespaceMemberList(SyntaxNode* memberList, SyntaxNode* member);
SyntaxNode* newNamespace(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* leftBrace, SyntaxNode* memberList, SyntaxNode* rightBrace);
SyntaxNode* newProgram(SyntaxNode* memberList);

int calcColumnAfterCodeBlock(char* s);
void yyerror(char* s);
void invalidString(char* s);
void unterminatedCode();
void unterminatedComment();

void attachSyntaxTree(SyntaxNode* tree);
void freetree();


#ifdef __cplusplus
}
#endif
