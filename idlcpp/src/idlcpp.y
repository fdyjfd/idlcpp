%{
#include "yyfuncs.h"
%}

%union
{
	struct SyntaxNode* sn;
}

%token <sn> BOOL CHAR WCHAR_T SHORT LONG INT FLOAT DOUBLE SIGNED UNSIGNED
%token <sn> NAMESPACE ENUM CLASS STRUCT STATIC VIRTUAL VOID CONST TYPEDEF PRIMITIVE NEW
%token <sn> ABSTRACT GET SET NOMETA NOCODE REF PTR EXPORT OVERRIDE LTS GTS
%token <sn> ',' '.' ':' ';' '(' ')' '[' ']' '{' '}' SCOPE IDENTIFY
%type <sn> field_0 field_1 field_2 field getter setter property_0 property_1 property_2 property
%type <sn> parameter_0 parameter parameterList method_0 method_1 method_2 method_3 method_4 method
%type <sn> primitive scopeName scopeNameList_0 scopeNameList typeName typeNameList enumeratorList classMemberList
%type <sn> templateParameterList templateParameters templateClassInstance_0 templateClassInstance
%type <sn> typeAlias_0 typeAlias enum_0 enum 
%type <sn> class_0 class_1 class_2 class_3 class_4 class_5 class namespaceMemberList namespace_0 namespace program
%start program

%%

primitive				: BOOL												{$$ = newPrimitiveType($1, pt_bool);}
						| CHAR												{$$ = newPrimitiveType($1, pt_char);}
						| SIGNED CHAR										{$$ = newPrimitiveType($1, pt_schar);}
						| UNSIGNED CHAR										{$$ = newPrimitiveType($1, pt_uchar);}
						| WCHAR_T											{$$ = newPrimitiveType($1, pt_wchar_t);}
						| SHORT												{$$ = newPrimitiveType($1, pt_short);}
						| SIGNED SHORT										{$$ = newPrimitiveType($1, pt_short);}
						| UNSIGNED SHORT									{$$ = newPrimitiveType($1, pt_ushort);}
						| LONG												{$$ = newPrimitiveType($1, pt_long);}
						| SIGNED LONG										{$$ = newPrimitiveType($1, pt_long);}
						| UNSIGNED LONG										{$$ = newPrimitiveType($1, pt_ulong);}
						| LONG LONG											{$$ = newPrimitiveType($1, pt_longlong);}
						| SIGNED LONG LONG									{$$ = newPrimitiveType($1, pt_longlong);}
						| UNSIGNED LONG LONG								{$$ = newPrimitiveType($1, pt_ulonglong);}
						| INT												{$$ = newPrimitiveType($1, pt_int);}
						| SIGNED INT										{$$ = newPrimitiveType($1, pt_int);}
						| SIGNED											{$$ = newPrimitiveType($1, pt_int);}
						| UNSIGNED INT										{$$ = newPrimitiveType($1, pt_uint);}
						| UNSIGNED											{$$ = newPrimitiveType($1, pt_uint);}
						| FLOAT												{$$ = newPrimitiveType($1, pt_float);}
						| DOUBLE											{$$ = newPrimitiveType($1, pt_double);}
						| LONG DOUBLE										{$$ = newPrimitiveType($1, pt_long_double);}
						| VOID												{$$ = newPrimitiveType($1, pt_void);}
;

enumeratorList			: IDENTIFY											{$$ = newEnumeratorList(NULL, NULL, $1);}
						| enumeratorList ',' IDENTIFY						{$$ = newEnumeratorList($1, $2, $3);}
;

enum_0					: ENUM IDENTIFY '{' enumeratorList '}' ';'			{$$ = newEnum($1, $2, $3, $4, $5, $6);}
						| ENUM IDENTIFY '{' enumeratorList ',' '}' ';'		{$$ = newEnum($1, $2, $3, $4, $6, $7);}
						| ENUM IDENTIFY '{' '}' ';'							{$$ = newEnum($1, $2, $3, NULL, $4, $5);}
;

enum					: enum_0											{$$ = $1;}
						| NOCODE enum_0										{$$ = $2; setMetaOnly($$);}
						| NOMETA enum_0										{$$ = $2; setNativeOnly($$);}
;

scopeName				: IDENTIFY											{$$ = newScopeName($1, NULL, NULL, NULL);}
						| IDENTIFY LTS typeNameList GTS						{$$ = newScopeName($1, $2, $3, $4);}	
;

scopeNameList_0			: scopeName											{$$ = newScopeNameList(NULL, $1);}
						| scopeNameList_0 SCOPE scopeName					{$$ = newScopeNameList($1, $3);}
;

scopeNameList			: scopeNameList_0									{$$ = $1;}
						| SCOPE scopeNameList_0								{$$ = $2; setScopeNameListGlobal($$);}
;

typeName				: primitive											{$$ = $1;}
						| scopeNameList										{$$ = newTypeName($1);}
;

typeNameList			: typeName											{$$ = newTypeNameList(NULL, NULL, $1);}
						| typeNameList ',' typeName							{$$ = newTypeNameList($1, $2, $3);}
;

typeAlias_0				: TYPEDEF typeName IDENTIFY ';'						{$$ = newTypedef($1, $3, $2);}
						| PRIMITIVE IDENTIFY ';'							{$$ = newTypeDeclaration($2, primitive_type);}
						| ENUM IDENTIFY ';'									{$$ = newTypeDeclaration($2, enum_type);}
						| STRUCT IDENTIFY ';'								{$$ = newTypeDeclaration($2, value_type);}
						| CLASS IDENTIFY ';'								{$$ = newTypeDeclaration($2, reference_type);}
;

typeAlias				: typeAlias_0										{$$ = $1;}
						| NOCODE typeAlias_0								{$$ = $2; setMetaOnly($$);}
						| NOMETA typeAlias_0								{$$ = $2; setNativeOnly($$);}
;

field_0					: typeName IDENTIFY ';'								{$$ = newField($1, $2, NULL, NULL, $3);}
						| typeName IDENTIFY '[' ']'	';'						{$$ = newField($1, $2, $3, $4, $5);}
;

field_1					: field_0											{$$ = $1;}
						| CONST field_0										{$$ = $2; setFieldConstant($$, $1);}
;

field_2					: field_1											{$$ = $1;}
						| STATIC field_1									{$$ = $2; setFieldStatic($$, $1);}
;

field					: field_2											{$$ = $1;}
						| NOCODE field_2									{$$ = $2; setMetaOnly($$);}
						| NOMETA field_2									{$$ = $2; setNativeOnly($$);}
;

getter					: GET												{$$ = newGetterSetter($1, NULL, NULL, NULL);}
						| GET '(' typeName ')'								{$$ = newGetterSetter($1, NULL, $3, NULL);}
						| GET '(' typeName PTR ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| GET '(' typeName REF ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| GET '(' CONST typeName PTR ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
						| GET '(' CONST typeName REF ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
;

setter					: SET												{$$ = newGetterSetter($1, NULL, NULL, NULL);}
						| SET '(' typeName ')'								{$$ = newGetterSetter($1, NULL, $3, NULL);}
						| SET '(' typeName PTR ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| SET '(' typeName REF ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| SET '(' CONST typeName PTR ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
						| SET '(' CONST typeName REF ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
;


property_0				: typeName IDENTIFY									{$$ = newProperty(NULL, $1, NULL, $2);}
						| typeName PTR IDENTIFY								{$$ = newProperty(NULL, $1, $2, $3);}
						| typeName REF IDENTIFY 							{$$ = newProperty(NULL, $1, $2, $3);}
						| CONST typeName PTR IDENTIFY						{$$ = newProperty($1, $2, $3, $4);}
						| CONST typeName REF IDENTIFY						{$$ = newProperty($1, $2, $3, $4);}
;


property_1				: property_0 getter ';'								{$$ = $1; setPropertyGetter($1, $2);}
						| property_0 setter ';'								{$$ = $1; setPropertySetter($1, $2);}
						| property_0 getter setter ';'						{$$ = $1; setPropertyGetter($1, $2); setPropertySetter($1, $3);}
						| property_0 setter getter ';'						{$$ = $1; setPropertyGetter($1, $3); setPropertySetter($1, $2);}
;


property_2				: property_1										{$$ = $1;}
						| STATIC property_1									{$$ = $2; setPropertyModifier($$, $1);}
;

property				: property_2										{$$ = $1;}
						| NOCODE property_2									{$$ = $2; setMetaOnly($$);}
						| NOMETA property_2									{$$ = $2; setNativeOnly($$);}
;

parameter_0				: typeName IDENTIFY									{$$ = newParameter($1, NULL, NULL, $2);}
						| typeName PTR IDENTIFY								{$$ = newParameter($1, NULL, $2, $3);}
						| typeName REF IDENTIFY								{$$ = newParameter($1, NULL, $2, $3);}
						| typeName PTR PTR IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW PTR IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW '[' ']' PTR IDENTIFY					{$$ = newParameter($1, $2, $5, $6); setParameterArray($$);}
						| typeName PTR REF IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW REF IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW '[' ']' REF IDENTIFY					{$$ = newParameter($1, $2, $5, $6); setParameterArray($$);}
;

parameter				: parameter_0										{$$ = $1;}
						| CONST parameter_0									{$$ = $2; setParameterConst($$, $1);}
;

parameterList			: parameter											{$$ = newParameterList(NULL, NULL, $1);}
						| parameterList ',' parameter						{$$ = newParameterList($1, $2, $3);}
;

method_0				: IDENTIFY '(' ')' ';'								{$$ = newMethod($1, $2, NULL, $3, NULL, $4);}
						| IDENTIFY '(' parameterList ')' ';'				{$$ = newMethod($1, $2, $3, $4, NULL, $5);}
						| IDENTIFY '(' ')' CONST ';'						{$$ = newMethod($1, $2, NULL, $3, $4, $5);}
						| IDENTIFY '(' parameterList ')' CONST ';'			{$$ = newMethod($1, $2, $3, $4, $5, $6);}
;

method_1				: method_0											{$$ = $1;}
						| typeName method_0									{$$ = $2; setMethodResult($$, $1, NULL);}
						| typeName REF method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName PTR method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName NEW method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName NEW '[' ']' method_0						{$$ = $5; setMethodResult($$, $1, $2); setMethodResultArray($$);}
;

method_2				: method_1											{$$ = $1;}
						| CONST method_1									{$$ = $2; setMethodResultConst($$, $1);}
;

method_3				: method_2											{$$ = $1;}
						| ABSTRACT method_2									{$$ = $2; setMethodModifier($$, $1);}
						| VIRTUAL method_2									{$$ = $2; setMethodModifier($$, $1);}
						| STATIC method_2									{$$ = $2; setMethodModifier($$, $1);}
;

method_4				: method_3											{$$ = $1;}
						| OVERRIDE method_3									{$$ = $2; setMethodOverride($$);}
;

method					: method_4											{$$ = $1;}
						| NOCODE method_4									{$$ = $2; setMetaOnly($$);}
						| NOMETA method_4									{$$ = $2; setNativeOnly($$);}
;

classMemberList			: property											{$$ = newClassMemberList(NULL, $1);}
						| method											{$$ = newClassMemberList(NULL, $1);}
						| field												{$$ = newClassMemberList(NULL, $1);}
						| class												{$$ = newClassMemberList(NULL, $1);}
						| enum												{$$ = newClassMemberList(NULL, $1);}
						| ';'												{$$ = NULL;}
						| classMemberList property							{$$ = newClassMemberList($1, $2);}
						| classMemberList method							{$$ = newClassMemberList($1, $2);}
						| classMemberList field								{$$ = newClassMemberList($1, $2);}
						| classMemberList class								{$$ = newClassMemberList($1, $2);}
						| classMemberList enum								{$$ = newClassMemberList($1, $2);}
						| classMemberList ';'								{$$ = $1;}
;

templateParameterList	: IDENTIFY											{$$ = newTemplateParameterList(NULL, NULL, $1);}
						| templateParameterList ',' IDENTIFY				{$$ = newTemplateParameterList($1, $2, $3);}
;

templateParameters		: LTS templateParameterList GTS						{$$ = newTemplateParameters($1, $2, $3);}
;

class_0					: CLASS IDENTIFY									{$$ = newClass($1, $2, NULL);}
						| CLASS IDENTIFY '(' IDENTIFY ')' 					{$$ = newClass($1, $2, $4);}
						| STRUCT IDENTIFY									{$$ = newClass($1, $2, NULL);}
						| STRUCT IDENTIFY '(' IDENTIFY ')' 					{$$ = newClass($1, $2, $4);}
;

class_1					: class_0											{$$ = $1;}
						| class_0 templateParameters						{$$ = $1; setClassTemplateParameters($$, $2);}
;

class_2					: class_1											{$$ = $1;}
						| class_1 ':' typeNameList							{$$ = $1; setClassBaseList($$, $2, $3);}
;

class_3					: class_2 '{' '}' ';'								{$$ = $1; setClassMemberList($$, $2, NULL, $3, $4);}
						| class_2 '{' classMemberList '}' ';'				{$$ = $1; setClassMemberList($$, $2, $3, $4, $5);}
;

class_4					: class_3											{$$ = $1;}
						| ABSTRACT class_3									{$$ = $2; setClassModifier($$, $1);}
;

class_5					: class_4											{$$ = $1;}
						| OVERRIDE class_4									{$$ = $2; setClassOverride($$);}
;

class					: class_5											{$$ = $1;}
						| NOCODE class_5									{$$ = $2; setMetaOnly($$);}
						| NOMETA class_5									{$$ = $2; setNativeOnly($$);}
;

templateClassInstance_0	: EXPORT IDENTIFY LTS typeNameList GTS ';'			{$$ = newTemplateClassInstance($2, $4);}
						

templateClassInstance	: templateClassInstance_0							{$$ = $1;}
						| NOCODE templateClassInstance_0					{$$ = $2; setMetaOnly($$);}
						| NOMETA templateClassInstance_0					{$$ = $2; setNativeOnly($$);}
;

namespaceMemberList		: class												{$$ = newNamespaceMemberList(NULL, $1);}
						| enum												{$$ = newNamespaceMemberList(NULL, $1);}
						| templateClassInstance								{$$ = newNamespaceMemberList(NULL, $1);}
						| typeAlias											{$$ = newNamespaceMemberList(NULL, $1);}
						| namespace											{$$ = newNamespaceMemberList(NULL, $1);}
						| ';'												{$$ = NULL;}
						| namespaceMemberList class							{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList enum							{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList templateClassInstance			{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList typeAlias						{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList namespace						{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList ';'							{$$ = $1;}
;

namespace_0				: NAMESPACE	IDENTIFY '{' '}'						{$$ = newNamespace($1, $2, $3, NULL, $4);}
						| NAMESPACE	IDENTIFY '{' namespaceMemberList '}'	{$$ = newNamespace($1, $2, $3, $4, $5);}
;

namespace				: namespace_0										{$$ = $1;}
						| NOCODE namespace_0								{$$ = $2; setMetaOnly($$);}
						| NOMETA namespace_0								{$$ = $2; setNativeOnly($$);}
;

program					:													{$$ = newProgram(NULL); attachSyntaxTree($$);}
						| namespaceMemberList								{$$ = newProgram($1); attachSyntaxTree($$);}
;
