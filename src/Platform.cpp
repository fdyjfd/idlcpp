#include "Platform.h"
#include <algorithm>
#include <filesystem>
#include <string.h>
using namespace std;
using namespace std::filesystem;

bool fileExisting(const path& file)
{
	file_status s = status(file);
	return is_regular_file(s) && exists(s);
}

bool isAbsolutePath(const char* fileName)
{
	path path(fileName);
	return path.is_absolute();
}

void normalizeFileName(string& str, const char* fileName)
{
	auto path = absolute(fileName);
	str = path.u8string();

	//std::replace(str.begin(), str.end(), '/', '\\');
	//std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

const char* getExtNameBegin(const char* normalizedFileName)
{
	const char* lastDot = strrchr(normalizedFileName, '.');
	const char* lastBackSlash = strrchr(normalizedFileName, '/');
	if(lastDot < lastBackSlash)
	{
		return 0;
	}
	return lastDot;
}

const char* getDirNameEnd(const char* normalizedFileName)
{
	const char* lastBackSlash = strrchr(normalizedFileName, '/');
	return lastBackSlash;
}

void GetRelativePath(std::string& str, path pathFrom, const path& fileTo)
{
	pathFrom.remove_filename();
	auto path = relative(fileTo, pathFrom);
	str = path.u8string();
	//判断是file 还是directory, 目前通过名字判断，应该通过file metadata 判断
	if (!path.empty() && !path.has_extension()) {
		str += u8'/';
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