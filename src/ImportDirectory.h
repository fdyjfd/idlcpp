#pragma once
#include <string>
#include <vector>

class ImportDirectories
{
public:
	ImportDirectories();
public:
	void addImportDirectory(const char* dir);
	void calcImportDirectories(const char* fileName);
	void setCurrentDirectory(const char* dir);
public:
	typedef std::vector<std::string> DirectoryContainer;
	DirectoryContainer m_directories;
	bool m_hasCurrentDirectory;
};

extern ImportDirectories g_importDirectories;
