#include "StaticField.h"
#include "StaticField.mh"
#include "StaticField.ic"
#include "StaticField.mc"

BEGIN_PAFCORE

StaticField::StaticField(const char* name, Type* type, size_t offset, size_t arraySize, bool constant, TypeCompound tc)
: Metadata(name)
{
	m_type = type;
	m_address = offset;
	m_arraySize = arraySize;
	m_constant = constant;
	m_typeCompound = tc;
}

Type* StaticField::get_type()
{
	return m_type;
}

bool StaticField::get_isArray() const
{
	return tc_array == m_typeCompound;
}

bool StaticField::get_isPointer() const
{
	return tc_pointer == m_typeCompound;
}

bool StaticField::get_isConstant() const
{
	return m_constant;
}

size_t StaticField::get_address() const
{
	return m_address;
}


END_PAFCORE
