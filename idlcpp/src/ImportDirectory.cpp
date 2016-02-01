#include "ImportDirectory.h"
#include "Platform.h"

ImportDirectories g_importDirectories;

ImportDirectories::ImportDirectories()
{
	m_hasCurrentDirectory = false;
}

void ImportDirectories::addImportDirectory(const char* dir)
{
	std::string str;
	normalizeFileName(str, dir);
	if(str.length() > 0)
	{
		if(str.at(str.length() - 1) != '\\')
		{
			str += '\\';
		}
		m_directories.insert(m_directories.begin(), str);
	}
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

