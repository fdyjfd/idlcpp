#pragma once
#include "Utility.h"

BEGIN_PAFCORE

class PAFCORE_EXPORT RefCount
{
public:
	virtual long_t addRef() = 0;
	virtual long_t release() = 0;
};

END_PAFCORE
