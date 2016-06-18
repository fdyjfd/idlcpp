#include "Reference.h"
#include "Reference.mh"
#include "Reference.ic"
#include "Reference.mc"
#include "ClassType.mh"

BEGIN_PAFCORE

long_t Reference::addRef()
{
	return 0x40000000;
};

long_t Reference::release()
{
	return 0x40000000;
};

long_t Reference::get_refCount()
{
	addRef();
	return release();
};

void* Reference::castTo(ClassType* classType)
{
	size_t offset;
	ClassType* thisType = getType();
	if (thisType->getClassOffset(offset, classType))
	{
		size_t address = getAddress();
		return (void*)(address + offset);
	}
	return 0;
}

END_PAFCORE
