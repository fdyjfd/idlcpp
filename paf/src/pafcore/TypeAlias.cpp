#include "TypeAlias.h"
#include "TypeAlias.mh"
#include "TypeAlias.ic"
#include "TypeAlias.mc"

BEGIN_PAFCORE

TypeAlias::TypeAlias(const char* name, Type* type) : 
	Metadata(name),
	m_type(type),
	m_enclosing(0)
{
}

Type* TypeAlias::get_type()
{
	return m_type;
}


END_PAFCORE
