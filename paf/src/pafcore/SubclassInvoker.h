#pragma once

#include "Variant.h"

BEGIN_PAFCORE

class SubclassInvoker
{
public:
	virtual ~SubclassInvoker(){}
	virtual ErrorCode invoke(const char* name, Variant* result, Variant* self, Variant* args, size_t numArgs) = 0;
};

END_PAFCORE