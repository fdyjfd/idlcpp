#include "Options.h"
#include <algorithm>
#include "Platform.h"
using namespace std;
using namespace std::filesystem;
Options::Options()
{
	m_metaTypePostfix = "_Type";
	m_subclassProxyPostfix = "_Proxy";
	m_internalSourceFilePostfix = ".ic";
	m_metaHeaderFilePostfix = ".mh";
	m_metaSourceFilePostfix = ".mc";
	m_outputLineDirective = false;
	m_strictArgumentsCount = false;
	m_checkConstant = false;
	//m_forceU8AttributeContent = true;
}


void Options::setPafcorePath(const char* path)
{
	m_pafcorePath = path;
}

void Options::convertToAbsoluteDirectory()
{
	path currentPath = current_path();
	m_pafcorePath = ::convertToAbsoluteDirectory(currentPath, m_pafcorePath);
}

Options g_options;