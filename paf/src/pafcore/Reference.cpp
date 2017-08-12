#include "Reference.h"
#include "Reference.mh"
#include "Reference.ic"
#include "Reference.mc"

BEGIN_PAFCORE

bool Reference::isTypeOf(ClassType* classType)
{
	ClassType* thisType = getType();
	return thisType->isType(classType);
}

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
