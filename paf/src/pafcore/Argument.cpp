#include "Argument.h"
#include "Argument.mh"
#include "Argument.ic"
#include "Argument.mc"

BEGIN_PAFCORE

Argument::Argument(const char* name, Type* type, Passing passing, bool constant)
: Metadata(name)
{
	m_type = type;
	m_passing = passing;
	m_constant = constant;
}

Type* Argument::get_type()
{
	return m_type;
}

bool Argument::get_byValue()
{
	return by_value == m_passing;
}

bool Argument::get_byRef()
{
	return by_ref == m_passing;
}

bool Argument::get_byPtr()
{
	return by_ptr == m_passing;
}

bool Argument::get_byOutPtr()
{
	return by_out_ptr == m_passing;
}

bool Argument::get_byOutRef()
{
	return by_out_ref == m_passing;
}

bool Argument::get_byNewPtr()
{
	return by_new_ptr == m_passing;
}

bool Argument::get_byNewRef()
{
	return by_new_ref == m_passing;
}

bool Argument::get_byNewArrayPtr()
{
	return by_new_array_ptr == m_passing;
}

bool Argument::get_byNewArrayRef()
{
	return by_new_array_ref == m_passing;
}

bool Argument::get_isConstant()
{
	return m_constant;
}


END_PAFCORE