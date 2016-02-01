#pragma once

#include <string>
#include <set>

class Options
{
public:
	Options();
public:
	std::string m_metaTypePostfix;
	std::string m_interfaceImplementorPostfix;
	std::string m_partialSourceFilePostfix;
	std::string m_metaHeaderFilePostfix;
	std::string m_metaSourceFilePostfix;
	std::string m_pafcorePath;
	std::string m_exportMacro;
	bool m_outputLineDirective;
public:
	void setPafcorePath(const char* path);
};

extern Options g_options;
