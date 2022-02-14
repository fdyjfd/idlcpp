#pragma once

#include <string>
#include <filesystem>

bool fileExisting(const std::filesystem::path& file);
bool isAbsolutePath(const char* fileName);
void normalizeFileName(std::string& str, const char* fileName);
const char* getExtNameBegin(const char* normalizedFileName);
const char* getDirNameEnd(const char* normalizedFileName);
void GetRelativePath(std::string& str, std::filesystem::path pathFrom, const std::filesystem::path& fileTo);
void FormatPathForInclude(std::string& str);
void FormatPathForLine(std::string& str);
bool compareFileName(const std::string& str1, const std::string& str2);
std::filesystem::path convertToAbsoluteDirectory(const std::filesystem::path & currentPath, const std::filesystem::path & relativePath);
