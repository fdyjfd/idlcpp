#pragma once

#include <stdio.h>

bool isNumAlpha_(char c);
void writeStringToFile(const char* str, FILE* file, int indentation = 0);
void writeStringToFile(const char* str, size_t length, FILE* file, int indentation = 0);
void writeSpaceToFile(FILE* file);
char GetLastWrittenChar();