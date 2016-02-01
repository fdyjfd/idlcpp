#include "Options.h"
#include <algorithm>

Options::Options()
{
	m_metaTypePostfix = "_Type";
	m_interfaceImplementorPostfix = "_Interface";
	m_partialSourceFilePostfix = ".ic";
	m_metaHeaderFilePostfix = ".mh";
	m_metaSourceFilePostfix = ".mc";
	m_outputLineDirective = false;
}


void Options::setPafcorePath(const char* path)
{
	m_pafcorePath = path;
	std::replace(m_pafcorePath.begin(), m_pafcorePath.end(), '/', '\\');
	if(m_pafcorePath.length() > 0 && m_pafcorePath.back() != '\\')
	{
		m_pafcorePath += '\\';
	}
}

Options g_options;