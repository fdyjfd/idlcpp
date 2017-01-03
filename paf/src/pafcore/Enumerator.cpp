#include "Enumerator.h"
#include "Enumerator.mh"
#include "Enumerator.ic"
#include "Enumerator.mc"

BEGIN_PAFCORE

Enumerator::Enumerator(const char* name, Attributes* attributes, Type* type, size_t value)
: Metadata(name, attributes)
{
	m_type = type;
	m_value = value;
}

Type* Enumerator::get__type_()
{
	return m_type;
}

int Enumerator::get__value_() const
{
	return m_value;
}

END_PAFCORE
