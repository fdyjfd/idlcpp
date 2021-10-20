#include "ImportDirectory.h"
#include "Platform.h"
#include <string.h>
#include <filesystem>
#include <assert.h>
#include <iostream>
using namespace std::filesystem;
using namespace std;
ImportDirectories g_importDirectories;

void ImportDirectories::addImportDirectory(const char* dir)
{
	path path(dir);
	m_directories.push_back(path);
}

void ImportDirectories::convertToAbsoluteDirectory()
{
	path currentPath = current_path();
	for (size_t i = 0; i < m_directories.size(); i++) {
		path& oldPath = m_directories[i];
		path absolutePath = currentPath / oldPath;
		path absolutePathNormal = absolutePath.lexically_normal();
		file_status s = status(absolutePathNormal);
		if (!is_directory(s) || !exists(s)) {
			cerr << oldPath << " not exist." << endl;
			exit(0);
		}

		oldPath = absolutePathNormal;
	}
}

//传入文件的绝对路径
void ImportDirectories::setCurrentDirectory(path file)
{
	file.remove_filename();
	current_path(file);
}

bool ImportDirectories::find(const path& file, path&absFile) const
{
	if (file.is_absolute()) {
		absFile = file;
		return fileExisting(absFile);
	}

	path current_dir = current_path();
	path tryfile = current_dir / file;
	absFile = tryfile.lexically_normal();
	if(fileExisting(absFile))
		return true;

	for (const auto& dir : m_directories) {
		path tryfile = dir / file;
		absFile = tryfile.lexically_normal();
		if (fileExisting(absFile))
			return true;
	}
	cerr << file << " not exist." << endl;
	return false;
}
