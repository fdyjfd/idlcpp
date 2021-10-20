#pragma once
#include <string>
#include <vector>
#include <filesystem>
class ImportDirectories
{
public:
	ImportDirectories() = default;
public:
	void addImportDirectory(const char* dir);
	void convertToAbsoluteDirectory();
	void setCurrentDirectory(std::filesystem::path file);
	bool find(const std::filesystem::path& file, std::filesystem::path& absFile) const;
public:
	typedef std::vector<std::filesystem::path> DirectoryContainer;
	//°üº¬-pc -IÄ¿Â¼
	DirectoryContainer m_directories;
};

extern ImportDirectories g_importDirectories;
