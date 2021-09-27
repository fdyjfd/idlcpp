#include "ImportDirectory.h"
#include "Platform.h"
#include <Windows.h>
ImportDirectories g_importDirectories;

ImportDirectories::ImportDirectories()
{
	m_hasCurrentDirectory = false;
}

void ImportDirectories::calcImportDirectories(const char* fileName)
{
	const char* lastSlash = strrchr(fileName, '\\');
	if (0 == lastSlash)
	{
		return;
	}
	std::string path(fileName, lastSlash + 1);
	::SetCurrentDirectory(path.c_str());
	auto it = m_directories.begin();
	auto end = m_directories.end();
	for (; it != end; ++it)
	{
		std::string fullName;
		normalizeFileName(fullName, it->c_str());
		if(fullName.length() > 0 && fullName.back() != '\\')
		{ 
			fullName.push_back('\\');
		}
		*it = fullName;
	}
}

void ImportDirectories::addImportDirectory(const char* dir)
{
	m_directories.insert(m_directories.begin(), dir);
}

void ImportDirectories::setCurrentDirectory(const char* dir)
{
	std::string str;
	normalizeFileName(str, dir);
	if(str.length() > 0)
	{
		if(str.at(str.length() - 1) != '\\')
		{
			str += '\\';
		}
		if(m_hasCurrentDirectory)
		{
			m_directories.pop_back();
		}
		m_directories.push_back(str);
		m_hasCurrentDirectory = true;
	}
}

