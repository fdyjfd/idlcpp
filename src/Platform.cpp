#include "Platform.h"
#include <algorithm>
#include <filesystem>
#include <string.h>
namespace fs = std::filesystem;

bool fileExisting(const char* fileName)
{
	fs::file_status s = fs::status(fileName);
	return fs::is_regular_file(s);
}

bool isAbsolutePath(const char* fileName)
{
	size_t len = strlen(fileName);
	if(len > 2 && fileName[1] == ':')
	{
		return true;
	}
	return false;
}

void normalizeFileName(std::string& str, const char* fileName)
{
	auto path = fs::absolute(fileName);
	str = path.u8string();

	std::replace(str.begin(), str.end(), '/', '\\');
	//std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

const char* getExtNameBegin(const char* normalizedFileName)
{
	const char* lastDot = strrchr(normalizedFileName, '.');
	const char* lastBackSlash = strrchr(normalizedFileName, '\\');
	if(lastDot < lastBackSlash)
	{
		return 0;
	}
	return lastDot;
}

const char* getDirNameEnd(const char* normalizedFileName)
{
	const char* lastBackSlash = strrchr(normalizedFileName, '\\');
	return lastBackSlash;
}

void GetRelativePath(std::string& str, const char* fileFrom, const char* fileTo)
{
	fs::path pathFrom(fileFrom);
	pathFrom.remove_filename();
	auto path = fs::relative(fileTo, pathFrom);
	str = path.u8string();
}

void FormatPathForInclude(std::string& str)
{
	std::replace(str.begin(), str.end(), '\\', '/');
}

void FormatPathForLine(std::string& str)
{
	std::replace(str.begin(), str.end(), '\\', '/');
}

bool compareFileName(const std::string& str1, const std::string& str2)
{
	return strcmp(str1.c_str(), str2.c_str()) < 0;
}
