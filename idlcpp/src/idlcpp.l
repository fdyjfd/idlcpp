%option noyywrap nodefault yylineno
%x IFILE CODEBLOCK COMMENT

%{
#include "SourceFile.h"
#include "idlcpp.y.h"
#include "yyfuncs.h"

YY_BUFFER_STATE createBufferState(FILE* file);
int yytokenno = 0;
int yycolumnno = 1;
%}

%%

"#import"[ \t]*\"	{BEGIN IFILE;}
<IFILE>[^\"\n]+		{
						{
							int res;
							int c;
							while((c = input()) && c != '\n')
							{}
							addSourceFile(yytext);
							yycolumnno = 0;
							BEGIN INITIAL;
						}
					}
<IFILE>.|\n			{fprintf(stderr, "%d bad import line\n", yylineno); yyterminate();}

"$*"						{yycolumnno += 2; BEGIN CODEBLOCK;}
<CODEBLOCK>"*$"				{yycolumnno += 2; BEGIN INITIAL;}
<CODEBLOCK>[^*\n]+			{newCodeBlock(yytext); yycolumnno += strlen(yytext); yytokenno++;}
<CODEBLOCK>\n				{newCodeBlock(yytext); yycolumnno = 1; yytokenno++;}
<CODEBLOCK>.				{newCodeBlock(yytext); yycolumnno++; yytokenno++;}
<CODEBLOCK><<EOF>>			{unterminatedCode();yyterminate();}

"/*"						{yycolumnno += 2; BEGIN COMMENT;}
<COMMENT>"*/"				{yycolumnno += 2; BEGIN INITIAL;}
<COMMENT>[^*\n]+			{yycolumnno += strlen(yytext); }
<COMMENT>\n					{yycolumnno = 1; }
<COMMENT>.					{yycolumnno++;}
<COMMENT><<EOF>>			{unterminatedComment();yyterminate();}



"//".*\n			{}

<<EOF>>				{yyterminate();}

\$\$.*				{newCodeBlock(yytext + 2); yycolumnno += strlen(yytext); yytokenno++;}

\$[a-zA-Z_0-9]+		{newCodeBlock(yytext + 1); yycolumnno += strlen(yytext); yytokenno++;}

","	|
";"	|
":"	|
"{"	|
"}"	|
"["	|
"]"	|
"("	|
")"				{yylval.sn = newToken(yytext[0]); yycolumnno++; yytokenno++; return yytext[0];}

"<"				{yylval.sn = newToken(yytext[0]);				yycolumnno += strlen(yytext); yytokenno++; return LAB;}
">"				{yylval.sn = newToken(yytext[0]);				yycolumnno += strlen(yytext); yytokenno++; return RAB;}
"::"			{yylval.sn = newToken(snt_keyword_scope);		yycolumnno += strlen(yytext); yytokenno++; return SCOPE;}
"bool"			{yylval.sn = newToken(snt_keyword_bool);		yycolumnno += strlen(yytext); yytokenno++; return BOOL;}
"char"			{yylval.sn = newToken(snt_keyword_char);		yycolumnno += strlen(yytext); yytokenno++; return CHAR;}
"wchar_t"		{yylval.sn = newToken(snt_keyword_wchar_t);		yycolumnno += strlen(yytext); yytokenno++; return WCHAR_T;}
"short"			{yylval.sn = newToken(snt_keyword_short);		yycolumnno += strlen(yytext); yytokenno++; return SHORT;}
"long"			{yylval.sn = newToken(snt_keyword_long);		yycolumnno += strlen(yytext); yytokenno++; return LONG;}
"int"			{yylval.sn = newToken(snt_keyword_int);			yycolumnno += strlen(yytext); yytokenno++; return INT;}
"signed"		{yylval.sn = newToken(snt_keyword_signed);		yycolumnno += strlen(yytext); yytokenno++; return SIGNED;}
"unsigned"		{yylval.sn = newToken(snt_keyword_unsigned);	yycolumnno += strlen(yytext); yytokenno++; return UNSIGNED;}
"float"			{yylval.sn = newToken(snt_keyword_float);		yycolumnno += strlen(yytext); yytokenno++; return FLOAT;}
"double"		{yylval.sn = newToken(snt_keyword_double);		yycolumnno += strlen(yytext); yytokenno++; return DOUBLE;}
"void"			{yylval.sn = newToken(snt_keyword_void);		yycolumnno += strlen(yytext); yytokenno++; return VOID;}
"ref"			{yylval.sn = newToken(snt_keyword_ref);			yycolumnno += strlen(yytext); yytokenno++; return REF;}
"ptr"			{yylval.sn = newToken(snt_keyword_ptr);			yycolumnno += strlen(yytext); yytokenno++; return PTR;}
"new"			{yylval.sn = newToken(snt_keyword_new);			yycolumnno += strlen(yytext); yytokenno++; return NEW;}
"abstract"		{yylval.sn = newToken(snt_keyword_abstract);	yycolumnno += strlen(yytext); yytokenno++; return ABSTRACT;}
"namespace"		{yylval.sn = newToken(snt_keyword_namespace);	yycolumnno += strlen(yytext); yytokenno++; return NAMESPACE;}
"enum"			{yylval.sn = newToken(snt_keyword_enum);		yycolumnno += strlen(yytext); yytokenno++; return ENUM;}
"class"			{yylval.sn = newToken(snt_keyword_class);		yycolumnno += strlen(yytext); yytokenno++; return CLASS;}
"struct"		{yylval.sn = newToken(snt_keyword_struct);		yycolumnno += strlen(yytext); yytokenno++; return STRUCT;}
"virtual"		{yylval.sn = newToken(snt_keyword_virtual);		yycolumnno += strlen(yytext); yytokenno++; return VIRTUAL;}
"static"		{yylval.sn = newToken(snt_keyword_static);		yycolumnno += strlen(yytext); yytokenno++; return STATIC;}
"const"			{yylval.sn = newToken(snt_keyword_const);		yycolumnno += strlen(yytext); yytokenno++; return CONST;}
"template"		{yylval.sn = newToken(snt_keyword_template);	yycolumnno += strlen(yytext); yytokenno++; return TEMPLATE;}
"typename"		{yylval.sn = newToken(snt_keyword_typename);	yycolumnno += strlen(yytext); yytokenno++; return TYPENAME;}
"typedef"		{yylval.sn = newToken(snt_keyword_typedef);		yycolumnno += strlen(yytext); yytokenno++; return TYPEDEF;}
"get"			{yylval.sn = newToken(snt_keyword_get);			yycolumnno += strlen(yytext); yytokenno++; return GET;}
"set"			{yylval.sn = newToken(snt_keyword_set);			yycolumnno += strlen(yytext); yytokenno++; return SET;}
"all"			{yylval.sn = newToken(snt_keyword_all);			yycolumnno += strlen(yytext); yytokenno++; return ALL;}
"native"		{yylval.sn = newToken(snt_keyword_native);		yycolumnno += strlen(yytext); yytokenno++; return NATIVE;}
"meta"			{yylval.sn = newToken(snt_keyword_meta);		yycolumnno += strlen(yytext); yytokenno++; return META;}
"export"		{yylval.sn = newToken(snt_keyword_export);	yycolumnno += strlen(yytext); yytokenno++; return EXPORT;}

[a-zA-Z_][a-zA-Z_0-9]*	{yylval.sn = newIdentify(yytext);		yycolumnno += strlen(yytext); yytokenno++; return IDENTIFY;}

[ \t]			{++yycolumnno;}
"\n"			{newCodeBlock(yytext); yycolumnno = 1;}

[^ ,;:{}\[\]<>()\$\"/\t\n]* {invalidString(yytext); yycolumnno += strlen(yytext);}
.			 {invalidString(yytext); yycolumnno += strlen(yytext);}

%%

YY_BUFFER_STATE createBufferState(FILE* file)
{
	YY_BUFFER_STATE bs;
	bs = yy_create_buffer(file, YY_BUF_SIZE);
	return bs;
}