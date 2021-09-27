#include "TemplateArguments.h"
#include "IdentifyNode.h"

TypeNode* TemplateArguments::findTypeNode(const std::string& name)
{
	auto it = m_arguments.begin();
	auto end = m_arguments.end();
	for (; it != end; ++it)
	{
		if (it->m_name == name)
		{
			return it->m_typeNode;
		}
	}
	return 0;
}
