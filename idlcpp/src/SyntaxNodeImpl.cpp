#include "SyntaxNodeImpl.h"
#include <string.h>


//const char g_strStatic[] = {"static "};
//const char g_strVirtual[] = {"virtual "};
//const char g_strInterface[] = {"interface "};
//const char g_strClass[] = {"class "};
//const char g_strStruct[] = {"struct "};
//const char g_strEnum[] = {"enum "};
//const char g_strDelimiter[] = {", "};
//const char g_strColon[] = {": "};
//const char g_strSemicolon[] = {"; "};
//const char g_strRightParenthesis[] = {") "};
//const char g_strLeftBrace[] = {"{ "};
//const char g_strRightBrace[] = {"} "};

const char g_tabs[] = {"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"};
const char g_strSpaces[] = {"                "};


bool isNumAlpha_(char c)
{
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') ||('a' <= c && c <= 'z') || '_' == c);
}

void writeStringToFile(const char* str, FILE* file, int indentation)
{
	if(file)
	{
		if(indentation > 0)
		{
			fwrite(g_tabs, indentation, 1, file);
		}
		fwrite(str, strlen(str), 1, file);
	}
}

void writeStringToFile(const char* str, size_t length, FILE* file, int indentation)
{
	if(file)
	{
		if(indentation > 0)
		{
			fwrite(g_tabs, indentation, 1, file);
		}
		fwrite(str, length, 1, file);
	}
}
