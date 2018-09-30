#include "Iterator.h"
#include "Iterator.mh"
#include "Iterator.ic"
#include "Iterator.mc"

BEGIN_PAFCORE

bool Iterator::isEnd()
{
	return true;
}

void Iterator::moveNext()
{
}

void Iterator::reset()
{
}

long_t Iterator::addRef()
{
	return ++m_refCount;
}

long_t Iterator::release()
{
	long_t refCount = --m_refCount;
	if (0 == refCount)
	{
		delete this;

	}
	return refCount;
}

END_PAFCORE
