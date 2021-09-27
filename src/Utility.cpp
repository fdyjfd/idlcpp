#include "Utility.h"
#include <string.h>


const char g_tabs[] = { "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" };
const char g_strSpaces[] = { "                " };

char g_lastWrittenChar = 0;

bool isNumAlpha_(char c)
{
	return (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || '_' == c);
}

void writeStringToFile(const char* str, size_t length, FILE* file, int indentation)
{
	if (file)
	{
		if (indentation > 0)
		{
			fwrite(g_tabs, indentation, 1, file);
			g_lastWrittenChar = '\t';
		}
		fwrite(str, length, 1, file);
		if (length > 0)
		{
			g_lastWrittenChar = str[length - 1];
		}
	}
}

void writeStringToFile(const char* str, FILE* file, int indentation)
{
	writeStringToFile(str, strlen(str), file, indentation);
}

void writeSpaceToFile(FILE* file)
{
	writeStringToFile(" ", 1, file, 0);
}

char GetLastWrittenChar()
{
	return g_lastWrittenChar;
}