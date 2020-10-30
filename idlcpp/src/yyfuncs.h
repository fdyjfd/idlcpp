#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct SyntaxNode
{
	int m_nodeType;
};
typedef struct SyntaxNode SyntaxNode;

enum PredefinedType
{
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
	pt_string_t,
	pt_end,
};

typedef enum PredefinedType PredefinedType;

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
	snt_keyword_nometa = 258,
	snt_keyword_nocode,

	snt_keyword_begin_primitive,
	snt_keyword_void,
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
	snt_keyword_string_t,
	snt_keyword_end_primitive,

	snt_begin_output,

	snt_operator_scope,
	snt_operator_add_assign,
	snt_operator_sub_assign,
	snt_operator_mul_assign,
	snt_operator_div_assign,
	snt_operator_mod_assign,
	snt_operator_bit_xor_assign,
	snt_operator_bit_and_assign,
	snt_operator_bit_or_assign,
	snt_operator_left_shift,
	snt_operator_right_shift,
	snt_operator_left_shift_assign,
	snt_operator_right_shift_assign,
	snt_operator_equal,
	snt_operator_not_equal,
	snt_operator_less_equal,
	snt_operator_greater_equal,
	snt_operator_and,
	snt_operator_or,
	snt_operator_inc,
	snt_operator_dec,
	snt_operator_post_inc,
	snt_operator_post_dec,

	snt_keyword_namespace,
	snt_keyword_enum,
	snt_keyword_class,
	snt_keyword_struct,
	snt_keyword_template,
	snt_keyword_abstract,
	snt_keyword_virtual,
	snt_keyword_static,
	snt_keyword_const,
	snt_keyword_operator,
	snt_keyword_get,
	snt_keyword_set,
	snt_keyword_typedef,
	snt_keyword_delegate,

	snt_end_output,

	snt_keyword_primitive,
	snt_keyword_export,
	snt_keyword_override,
	snt_keyword_candidate,

	snt_identify,
	snt_identify_list,
	snt_enumerator,
	snt_enumerator_list,
	snt_enum,
	snt_scope_name,
	snt_scope_name_list,
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
	snt_operator,
	snt_class,
	snt_template_class_instance,
	snt_delegate,
	snt_typedef,
	snt_type_declaration,
	snt_namespace,
	snt_member_list,
	snt_token_list,
	snt_attribute,
	snt_attribute_list,
};

enum PropertyCategory
{
	simple_property,
	fixed_array_property,
	dynamic_array_property,
	list_property,
	map_property,
};

typedef enum PropertyCategory PropertyCategory;

void newCodeBlock(const char* str);
SyntaxNode* newToken(int nodeType);
SyntaxNode* newIdentify(const char* str);
SyntaxNode* newString(const char* str);

SyntaxNode* newPrimitiveType(SyntaxNode* keyword, PredefinedType type);

SyntaxNode* newIdentifyList(SyntaxNode* identifyList, SyntaxNode* delimiter, SyntaxNode* identify);

SyntaxNode* newAttribute(SyntaxNode* name, SyntaxNode* content, int u8content);
SyntaxNode* newAttributeList(SyntaxNode* attributeList, SyntaxNode* attribute);
void setAttributeList(SyntaxNode* member, SyntaxNode* attributeList);

SyntaxNode* newEnumerator(SyntaxNode* attributeList, SyntaxNode* identify);
SyntaxNode* newEnumeratorList(SyntaxNode* enumeratorList, SyntaxNode* delimiter, SyntaxNode* enumerator);
SyntaxNode* newEnum(SyntaxNode* keyword, SyntaxNode* keyword2, SyntaxNode* name, SyntaxNode* leftBrace, SyntaxNode* enumeratorList, SyntaxNode* rightBrace);
void setEnumSemicolon(SyntaxNode* enm, SyntaxNode* semicolon);

SyntaxNode* newScopeName(SyntaxNode* identify, SyntaxNode* lts, SyntaxNode* parameterList, SyntaxNode* gts);
SyntaxNode* newScopeNameList(SyntaxNode* scopeNameList, SyntaxNode* scopeName);
void setScopeNameListGlobal(SyntaxNode* scopeNameList);
SyntaxNode* newTypeName(SyntaxNode* scopeNameList);
SyntaxNode* newTypeNameList(SyntaxNode* typeNameList, SyntaxNode* delimiter, SyntaxNode* typeName);

void setTypeNameFilter(SyntaxNode* syntaxNode, SyntaxNode* filterNode);
void setMemberFilter(SyntaxNode* syntaxNode, SyntaxNode* filterNode);
void setNativeName(SyntaxNode* syntaxNode, SyntaxNode* nativeName);
SyntaxNode* newField(SyntaxNode* type, SyntaxNode* pointer, SyntaxNode* name, SyntaxNode* leftBracket, SyntaxNode* rightBracket);
void setFieldConstant(SyntaxNode* syntaxNode, SyntaxNode* constant);
void setFieldStatic(SyntaxNode* syntaxNode, SyntaxNode* stat);
void setFieldSemicolon(SyntaxNode* syntaxNode, SyntaxNode* semicolon);

SyntaxNode* newGetterSetter(SyntaxNode* keyword);
void setGetterIncRef(SyntaxNode* syntaxNode);
void setSetterDecRef(SyntaxNode* syntaxNode);
void setSetterAllowNull(SyntaxNode* syntaxNode);
void setGetterSetterNativeName(SyntaxNode* syntaxNode, SyntaxNode* nativeName);

SyntaxNode* newProperty(SyntaxNode* name, PropertyCategory category);
void setMapPropertyKeyType(SyntaxNode* property, SyntaxNode* type, SyntaxNode* passing);

void setPropertyType(SyntaxNode* property, SyntaxNode* type, SyntaxNode* passing);
void setPropertyGetter(SyntaxNode* property, SyntaxNode* getter);
void setPropertySetter(SyntaxNode* property, SyntaxNode* setter);
void setPropertyCandidate(SyntaxNode* property);
void setPropertyModifier(SyntaxNode* syntaxNode, SyntaxNode* modifier);

SyntaxNode* newParameter(SyntaxNode* type, SyntaxNode* passing, SyntaxNode* out, SyntaxNode* name);
void setParameterArray(SyntaxNode* parameter);
void setParameterConst(SyntaxNode* parameter, SyntaxNode* constant);
void setParameterAllowNull(SyntaxNode* parameter);
SyntaxNode* newParameterList(SyntaxNode* parameterList, SyntaxNode* delimiter, SyntaxNode* parameter);

SyntaxNode* newMethod(SyntaxNode* name, SyntaxNode* leftParenthesis, SyntaxNode* parameterList, SyntaxNode* rightParenthesis, SyntaxNode* constant);
void setMethodResult(SyntaxNode* method, SyntaxNode* result, SyntaxNode* passing);
void setMethodResultArray(SyntaxNode* method);
void setMethodResultConst(SyntaxNode* method, SyntaxNode* constant);
void setMethodModifier(SyntaxNode* method, SyntaxNode* modifier);
void setMethodOverride(SyntaxNode* method);
void setMethodSemicolon(SyntaxNode* syntaxNode, SyntaxNode* semicolon);

SyntaxNode* newOperator(SyntaxNode* keyword, SyntaxNode* sign, SyntaxNode* leftParenthesis, SyntaxNode* parameterList, SyntaxNode* rightParenthesis, SyntaxNode* constant, SyntaxNode* semicolon);
void setOperatorResult(SyntaxNode* opt, SyntaxNode* result, SyntaxNode* passing);
void setOperatorResultArray(SyntaxNode* opt);
void setOperatorResultConst(SyntaxNode* opt, SyntaxNode* constant);
void setOperatorModifier(SyntaxNode* opt, SyntaxNode* modifier);
void setOperatorOverride(SyntaxNode* opt);

SyntaxNode* newClassMemberList(SyntaxNode* memberList, SyntaxNode* member);
SyntaxNode* newClass(SyntaxNode* keyword, SyntaxNode* category, SyntaxNode* name);
void setClassBaseList(SyntaxNode* cls, SyntaxNode* colon, SyntaxNode* baseList);
void setClassMemberList(SyntaxNode* cls, SyntaxNode* leftBrace, SyntaxNode* memberList, SyntaxNode* rightBrace);
void setClassModifier(SyntaxNode* cls, SyntaxNode* modifier);
void setClassOverride(SyntaxNode* cls);
void setClassTemplateParameters(SyntaxNode* cls, SyntaxNode* parameters);
void setClassSemicolon(SyntaxNode* cls, SyntaxNode* semicolon);

SyntaxNode* newDelegate(SyntaxNode* name, SyntaxNode* leftParenthesis, SyntaxNode* parameterList, SyntaxNode* rightParenthesis, SyntaxNode* semicolon);
void setDelegateResult(SyntaxNode* delegate, SyntaxNode* result, SyntaxNode* passing);
void setDelegateResultArray(SyntaxNode* delegate);
void setDelegateResultConst(SyntaxNode* delegate, SyntaxNode* constant);
void setDelegateKeyword(SyntaxNode* delegate, SyntaxNode* keyword);

SyntaxNode* newTypeDeclaration(SyntaxNode* name, TypeCategory typeCategory);
SyntaxNode* newTypedef(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* typeName);

SyntaxNode* newTemplateParameterList(SyntaxNode* list, SyntaxNode* delimiter, SyntaxNode* identify);
SyntaxNode* newTemplateParameters(SyntaxNode* keyword, SyntaxNode* lts, SyntaxNode* parameterList, SyntaxNode* gts);

SyntaxNode* newTemplateClassInstance(SyntaxNode* name, SyntaxNode* typeNameList);

SyntaxNode* newTokenList(SyntaxNode* tokenList, SyntaxNode* token);
void setTemplateClassInstanceTokenList(SyntaxNode* tci, SyntaxNode* enumeratorList);

SyntaxNode* newNamespaceMemberList(SyntaxNode* memberList, SyntaxNode* member);
SyntaxNode* newNamespace(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* leftBrace, SyntaxNode* memberList, SyntaxNode* rightBrace);
SyntaxNode* newProgram(SyntaxNode* memberList);

void yyerror(char* s);
void invalidString(char* s);
void unterminatedCode();
void unterminatedComment();
void addSourceFile(const char* fileName);
void attachSyntaxTree(SyntaxNode* tree);

#ifdef __cplusplus
}
#endif
