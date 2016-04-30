#pragma once

#include <string>

bool fileExisting(const char* fileName);
bool isAbsolutePath(const char* fileName);
void normalizeFileName(std::string& str, const char* fileName);
const char* getExtNameBegin(const char* normalizedFileName);
const char* getDirNameEnd(const char* normalizedFileName);
void GetRelativePath(std::string& str, const char* fileFrom, const char* fileTo);
void FormatPathForInclude(std::string& str);
void FormatPathForLine(std::string& str);
bool compareFileName(const std::string& str1, const std::string& str2);
