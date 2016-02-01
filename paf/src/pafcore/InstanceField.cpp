#include "InstanceField.h"
#include <assert.h>
#include "InstanceField.mh"
#include "InstanceField.ic"
#include "InstanceField.mc"

BEGIN_PAFCORE

InstanceField::InstanceField(const char* name, ClassType* objectType, Type* type, size_t offset, size_t arraySize, bool constant, bool array)
: Metadata(name)
{
	m_objectType = objectType;
	m_type = type;
	m_offset = offset;
	m_arraySize = arraySize;
	m_constant = constant;
	m_array = array;
}

Type* InstanceField::get_type()
{
	return m_type;
}

ClassType* InstanceField::get_objectType()
{
	return m_objectType;
}

bool InstanceField::get_isArray()
{
	return m_array;
}

bool InstanceField::get_isConstant()
{
	return m_constant;
}

size_t InstanceField::get_offset()
{
	return m_offset;
}


END_PAFCORE
