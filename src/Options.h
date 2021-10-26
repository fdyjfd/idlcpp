#pragma once

#include <string>
#include <set>
#include <filesystem>
class Options
{
public:
	Options();
public:
	std::string m_metaTypePostfix;
	std::string m_subclassProxyPostfix;
	std::string m_internalSourceFilePostfix;
	std::string m_metaHeaderFilePostfix;
	std::string m_metaSourceFilePostfix;
	std::filesystem::path m_pafcorePath;
	std::string m_exportMacro;
	bool m_outputLineDirective;
	bool m_strictArgumentsCount;
	bool m_checkConstant;
	//bool m_forceU8AttributeContent;
public:
	void setPafcorePath(const char* path);
	void convertToAbsoluteDirectory();
};

extern Options g_options;
