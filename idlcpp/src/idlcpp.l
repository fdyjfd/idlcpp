%option noyywrap nodefault yylineno
%x IFILE CODEBLOCK COMMENT

%{
#include <stdlib.h>
#include <string.h>
#include "idlcpp.y.h"
#include "yyfuncs.h"

YY_BUFFER_STATE createBufferState(FILE* file);
int yytokenno = 0;
int yycolumnno = 1;
int yyHasArrayProperty = 0;
int yyHasListProperty = 0;
int yyHasMapProperty = 0;
int yyHasDelegate = 0;
%}

%%

"#import"[ \t]*\"	{BEGIN IFILE;}
<IFILE>[^\"\n]+		{
						{
							int c;
							while((c = input()) && c != '\n')
							{}
							addSourceFile(yytext);
							yycolumnno = 0;
							BEGIN INITIAL;
						}
					}
<IFILE>.|\n			{fprintf(stderr, "%d bad import line\n", yylineno); yyterminate();}

"#{"						{yycolumnno += 2; BEGIN CODEBLOCK;}
<CODEBLOCK>"#}"				{yycolumnno += 2; BEGIN INITIAL;}
<CODEBLOCK>[^#\n]+			{newCodeBlock(yytext); yycolumnno += strlen(yytext); yytokenno++;}
<CODEBLOCK>\n				{newCodeBlock(yytext); yycolumnno = 1; yytokenno++;}
<CODEBLOCK>.				{newCodeBlock(yytext); yycolumnno++; yytokenno++;}
<CODEBLOCK><<EOF>>			{unterminatedCode();yyterminate();}

"/*"						{yycolumnno += 2; BEGIN COMMENT;}
<COMMENT>"*/"				{yycolumnno += 2; BEGIN INITIAL;}
<COMMENT>[^*\n]+			{yycolumnno += strlen(yytext); }
<COMMENT>\n					{newCodeBlock("\n"); yycolumnno = 1; }
<COMMENT>.					{yycolumnno++;}
<COMMENT><<EOF>>			{unterminatedComment();yyterminate();}



"//".*\n			{newCodeBlock("\n"); yycolumnno = 1;}

<<EOF>>				{yyterminate();}

\#\#.*				{newCodeBlock(yytext + 2); yycolumnno += strlen(yytext); yytokenno++;}

\#[a-zA-Z_0-9]+		{newCodeBlock(yytext + 1); yycolumnno += strlen(yytext); yytokenno++;}

"+" |
"-" |
"*" |
"/" |
"%" |
"^" |
"&" |
"|" |
"~" |
"!" |
"=" |
"<" |
">" |
"{"	|
"}"	|
"["	|
"]"	|
"("	|
")"	|
","	|
";"	|
":"	|
"?"				{yylval.sn = newToken(yytext[0]);				yycolumnno++; yytokenno++; return yytext[0];}

"::"			{yylval.sn = newToken(snt_operator_scope);					yycolumnno += strlen(yytext); yytokenno++; return SCOPE;}
"+="			{yylval.sn = newToken(snt_operator_add_assign);				yycolumnno += strlen(yytext); yytokenno++; return ADD_ASSIGN;}
"-="			{yylval.sn = newToken(snt_operator_sub_assign);				yycolumnno += strlen(yytext); yytokenno++; return SUB_ASSIGN;}
"*="			{yylval.sn = newToken(snt_operator_mul_assign);				yycolumnno += strlen(yytext); yytokenno++; return MUL_ASSIGN;}
"/="			{yylval.sn = newToken(snt_operator_div_assign);				yycolumnno += strlen(yytext); yytokenno++; return DIV_ASSIGN;}
"%="			{yylval.sn = newToken(snt_operator_mod_assign);				yycolumnno += strlen(yytext); yytokenno++; return MOD_ASSIGN;}
"^="			{yylval.sn = newToken(snt_operator_bit_xor_assign);			yycolumnno += strlen(yytext); yytokenno++; return BIT_XOR_ASSIGN;}
"&="			{yylval.sn = newToken(snt_operator_bit_and_assign);			yycolumnno += strlen(yytext); yytokenno++; return BIT_AND_ASSIGN;}
"|="			{yylval.sn = newToken(snt_operator_bit_or_assign);			yycolumnno += strlen(yytext); yytokenno++; return BIT_OR_ASSIGN;}
"<<"			{yylval.sn = newToken(snt_operator_left_shift);				yycolumnno += strlen(yytext); yytokenno++; return LEFT_SHIFT;}
">>"			{yylval.sn = newToken(snt_operator_right_shift);			yycolumnno += strlen(yytext); yytokenno++; return RIGHT_SHIFT;}
"<<="			{yylval.sn = newToken(snt_operator_left_shift_assign);		yycolumnno += strlen(yytext); yytokenno++; return LEFT_SHIFT_ASSIGN;}
">>="			{yylval.sn = newToken(snt_operator_right_shift_assign);		yycolumnno += strlen(yytext); yytokenno++; return RIGHT_SHIFT_ASSIGN;}
"=="			{yylval.sn = newToken(snt_operator_equal);					yycolumnno += strlen(yytext); yytokenno++; return EQUAL;}
"!="			{yylval.sn = newToken(snt_operator_not_equal);				yycolumnno += strlen(yytext); yytokenno++; return NOT_EQUAL;}
"<="			{yylval.sn = newToken(snt_operator_less_equal);				yycolumnno += strlen(yytext); yytokenno++; return LESS_EQUAL;}
">="			{yylval.sn = newToken(snt_operator_greater_equal);			yycolumnno += strlen(yytext); yytokenno++; return GREATER_EQUAL;}
"&&"			{yylval.sn = newToken(snt_operator_and);					yycolumnno += strlen(yytext); yytokenno++; return AND;}
"||"			{yylval.sn = newToken(snt_operator_or);						yycolumnno += strlen(yytext); yytokenno++; return OR;}
"++"			{yylval.sn = newToken(snt_operator_inc);					yycolumnno += strlen(yytext); yytokenno++; return INC;}
"--"			{yylval.sn = newToken(snt_operator_dec);					yycolumnno += strlen(yytext); yytokenno++; return DEC;}

"bool"			{yylval.sn = newToken(snt_keyword_bool);					yycolumnno += strlen(yytext); yytokenno++; return BOOL;}
"char"			{yylval.sn = newToken(snt_keyword_char);					yycolumnno += strlen(yytext); yytokenno++; return CHAR;}
"wchar_t"		{yylval.sn = newToken(snt_keyword_wchar_t);					yycolumnno += strlen(yytext); yytokenno++; return WCHAR_T;}
"short"			{yylval.sn = newToken(snt_keyword_short);					yycolumnno += strlen(yytext); yytokenno++; return SHORT;}
"long"			{yylval.sn = newToken(snt_keyword_long);					yycolumnno += strlen(yytext); yytokenno++; return LONG;}
"int"			{yylval.sn = newToken(snt_keyword_int);						yycolumnno += strlen(yytext); yytokenno++; return INT;}
"signed"		{yylval.sn = newToken(snt_keyword_signed);					yycolumnno += strlen(yytext); yytokenno++; return SIGNED;}
"unsigned"		{yylval.sn = newToken(snt_keyword_unsigned);				yycolumnno += strlen(yytext); yytokenno++; return UNSIGNED;}
"float"			{yylval.sn = newToken(snt_keyword_float);					yycolumnno += strlen(yytext); yytokenno++; return FLOAT;}
"double"		{yylval.sn = newToken(snt_keyword_double);					yycolumnno += strlen(yytext); yytokenno++; return DOUBLE;}
"void"			{yylval.sn = newToken(snt_keyword_void);					yycolumnno += strlen(yytext); yytokenno++; return VOID;}
"string_t"		{yylval.sn = newToken(snt_keyword_string_t);				yycolumnno += strlen(yytext); yytokenno++; return STRING_T;}
"abstract"		{yylval.sn = newToken(snt_keyword_abstract);				yycolumnno += strlen(yytext); yytokenno++; return ABSTRACT;}
"namespace"		{yylval.sn = newToken(snt_keyword_namespace);				yycolumnno += strlen(yytext); yytokenno++; return NAMESPACE;}
"enum"			{yylval.sn = newToken(snt_keyword_enum);					yycolumnno += strlen(yytext); yytokenno++; return ENUM;}
"class"			{yylval.sn = newToken(snt_keyword_class);					yycolumnno += strlen(yytext); yytokenno++; return CLASS;}
"struct"		{yylval.sn = newToken(snt_keyword_struct);					yycolumnno += strlen(yytext); yytokenno++; return STRUCT;}
"virtual"		{yylval.sn = newToken(snt_keyword_virtual);					yycolumnno += strlen(yytext); yytokenno++; return VIRTUAL;}
"static"		{yylval.sn = newToken(snt_keyword_static);					yycolumnno += strlen(yytext); yytokenno++; return STATIC;}
"const"			{yylval.sn = newToken(snt_keyword_const);					yycolumnno += strlen(yytext); yytokenno++; return CONST;}
"operator"		{yylval.sn = newToken(snt_keyword_operator);				yycolumnno += strlen(yytext); yytokenno++; return OPERATOR;}
"typedef"		{yylval.sn = newToken(snt_keyword_typedef);					yycolumnno += strlen(yytext); yytokenno++; return TYPEDEF;}
"primitive"		{yylval.sn = newToken(snt_keyword_primitive);				yycolumnno += strlen(yytext); yytokenno++; return PRIMITIVE;}
"get"			{yylval.sn = newToken(snt_keyword_get);						yycolumnno += strlen(yytext); yytokenno++; return GET;}
"set"			{yylval.sn = newToken(snt_keyword_set);						yycolumnno += strlen(yytext); yytokenno++; return SET;}
"candidate"		{yylval.sn = newToken(snt_keyword_candidate);				yycolumnno += strlen(yytext); yytokenno++; return CANDIDATE;}
"nocode"		{yylval.sn = newToken(snt_keyword_nocode);					yycolumnno += strlen(yytext); yytokenno++; return NOCODE;}
"nometa"		{yylval.sn = newToken(snt_keyword_nometa);					yycolumnno += strlen(yytext); yytokenno++; return NOMETA;}
"export"		{yylval.sn = newToken(snt_keyword_export);					yycolumnno += strlen(yytext); yytokenno++; return EXPORT;}
"override"		{yylval.sn = newToken(snt_keyword_override);				yycolumnno += strlen(yytext); yytokenno++; return OVERRIDE;}
"template"		{yylval.sn = newToken(snt_keyword_template);				yycolumnno += strlen(yytext); yytokenno++; return TEMPLATE;}
"delegate"		{yylval.sn = newToken(snt_keyword_delegate);				yycolumnno += strlen(yytext); yytokenno++; return DELEGATE;}


[a-zA-Z_][a-zA-Z_0-9]*	{yylval.sn = newIdentify(yytext);					yycolumnno += strlen(yytext); yytokenno++; return IDENTIFY;}

\"[^\"]*\"				{yylval.sn = newString(yytext + 1);					yycolumnno += strlen(yytext); yytokenno++; return STRING;}
u8\"[^\"]*\"			{yylval.sn = newString(yytext + 3);					yycolumnno += strlen(yytext); yytokenno++; return U8STRING;}

[ \t]							{++yycolumnno;}
"\n"							{newCodeBlock(yytext); yycolumnno = 1;}

[^ ,;:{}\[\]<>()&*^$"/+%^|!~=?\-\t\n]*		{invalidString(yytext); yycolumnno += strlen(yytext);}
.								{invalidString(yytext); yycolumnno += strlen(yytext);}

%%

YY_BUFFER_STATE createBufferState(FILE* file)
{
	YY_BUFFER_STATE bs;
	bs = yy_create_buffer(file, YY_BUF_SIZE);
	return bs;
}