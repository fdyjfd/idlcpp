#include "Platform.h"
#include <Windows.h>
#include <shlwapi.h>
#include "TempBuffer.h"
#include <algorithm>

#pragma comment(lib, "shlwapi.lib")

bool fileExisting(const char* fileName)
{
	DWORD attr = GetFileAttributes(fileName);
	return ((attr != INVALID_FILE_ATTRIBUTES) && ((attr & FILE_ATTRIBUTE_DIRECTORY) == 0));
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
	char buf[MAX_PATH];
	*buf = 0;
	char* fp;
	if(0 != GetFullPathName(fileName, MAX_PATH, buf, &fp))
	{
		str = buf;
	}
	else
	{
		str = fileName;
	}
	std::replace(str.begin(), str.end(), '/', '\\');
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
	char buf[MAX_PATH];
	if(PathRelativePathTo(buf, fileFrom, 0, fileTo, 0))
	{
		str = buf;
	}
	else
	{
		str = fileTo;
	}
}

void FormatPathForInclude(std::string& str)
{
	std::replace(str.begin(), str.end(), '\\', '/');
}

void FormatPathForLine(std::string& str)
{
	std::replace(str.begin(), str.end(), '\\', '/');
}
