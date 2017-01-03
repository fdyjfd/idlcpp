#include "InstanceMethod.h"
#include "Argument.h"
#include "InstanceMethod.mh"
#include "InstanceMethod.ic"
#include "InstanceMethod.mc"

BEGIN_PAFCORE

InstanceMethod::InstanceMethod(const char* name, Attributes* attributes, FunctionInvoker invoker, Overload* overloads, size_t overloadCount)
: Metadata(name, attributes)
{
	m_invoker = invoker;
	m_overloads = overloads;
	m_overloadCount = overloadCount;
}

size_t InstanceMethod::get_overloadCount() const
{
	return m_overloadCount;
}

Result* InstanceMethod::getResult(size_t overloadIndex)
{
	if(overloadIndex < m_overloadCount)
	{
		return m_overloads[overloadIndex].m_result;
	}
	return 0;
}

size_t InstanceMethod::getArgumentCount(size_t overloadIndex)
{
	if(overloadIndex < m_overloadCount)
	{
		return m_overloads[overloadIndex].m_argCount;
	}
	return 0;
}

Argument* InstanceMethod::getArgument(size_t overloadIndex, size_t index)
{
	if(overloadIndex < m_overloadCount)
	{
		if(index < m_overloads[overloadIndex].m_argCount)
		{
			return &m_overloads[overloadIndex].m_args[index];
		}
	}
	return 0;
}

END_PAFCORE