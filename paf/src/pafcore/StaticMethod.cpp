#include "StaticMethod.h"
#include "StaticMethod.mh"
#include "StaticMethod.ic"
#include "StaticMethod.mc"
#include "Argument.h"

BEGIN_PAFCORE

StaticMethod::StaticMethod(const char* name, Attributes* attributes, FunctionInvoker invoker, Overload* overloads, size_t overloadCount)
: Metadata(name, attributes)
{
	m_invoker = invoker;
	m_overloads = overloads;
	m_overloadCount = overloadCount;
}

size_t StaticMethod::get_overloadCount() const
{
	return m_overloadCount;
}

Result* StaticMethod::getResult(size_t overloadIndex)
{
	if(overloadIndex < m_overloadCount)
	{
		return m_overloads[overloadIndex].m_result;
	}
	return 0;
}

size_t StaticMethod::getArgumentCount(size_t overloadIndex)
{
	if(overloadIndex < m_overloadCount)
	{
		return m_overloads[overloadIndex].m_argCount;
	}
	return 0;
}

Argument* StaticMethod::getArgument(size_t overloadIndex, size_t index)
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