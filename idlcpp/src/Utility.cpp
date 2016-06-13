#include "Utility.h"
#include <string.h>


const char g_tabs[] = { "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" };
const char g_strSpaces[] = { "                " };


bool isNumAlpha_(char c)
{
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || '_' == c);
}

void writeStringToFile(const char* str, FILE* file, int indentation)
{
	if (file)
	{
		if (indentation > 0)
		{
			fwrite(g_tabs, indentation, 1, file);
		}
		fwrite(str, strlen(str), 1, file);
	}
}

void writeStringToFile(const char* str, size_t length, FILE* file, int indentation)
{
	if (file)
	{
		if (indentation > 0)
		{
			fwrite(g_tabs, indentation, 1, file);
		}
		fwrite(str, length, 1, file);
	}
}

void writeSpaceToFile(FILE* file)
{
	writeStringToFile(" ", 1, file, 0);
}
