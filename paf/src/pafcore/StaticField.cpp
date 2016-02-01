#include "StaticField.h"
#include <assert.h>
#include "StaticField.mh"
#include "StaticField.ic"
#include "StaticField.mc"

BEGIN_PAFCORE

StaticField::StaticField(const char* name, Type* type, size_t offset, size_t arraySize, bool constant, bool array)
: Metadata(name)
{
	m_type = type;
	m_address = offset;
	m_arraySize = arraySize;
	m_constant = constant;
	m_array = array;
}

Type* StaticField::get_type()
{
	return m_type;
}

bool StaticField::get_isArray()
{
	return m_array;
}

bool StaticField::get_isConstant()
{
	return m_constant;
}

size_t StaticField::get_address()
{
	return m_address;
}


END_PAFCORE
