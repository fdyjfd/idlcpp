#pragma once

#include <stdio.h>
#include "yyfuncs.h"

struct SyntaxNodeImpl : SyntaxNode
{
};

extern const char g_strSpaces[];
extern const char g_tabs[];

bool isNumAlpha_(char c);
void writeStringToFile(const char* str, FILE* file, int indentation = 0);
void writeStringToFile(const char* str, size_t length, FILE* file, int indentation = 0);

