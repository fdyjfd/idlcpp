#include "Reference.h"
#include "Type.mh"
#include "Reference.mh"
#include "Reference.ic"
#include "Reference.mc"

BEGIN_PAFCORE

long_t Reference::addRef()
{
	return 0x40000000;
};

long_t Reference::release()
{
	return 0x40000000;
};

long_t Reference::getRefCount()
{
	return 0x40000000;
};

END_PAFCORE
