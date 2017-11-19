#pragma once
#include "Utility.h"

BEGIN_PAFCORE

class PAFCORE_EXPORT RefCount
{
public:
	virtual long_t addRef() = 0;
	virtual long_t release() = 0;
};

#define PAF_DECL_REFCOUNT_INTERFACE_0 \
	virtual long_t addRef() = 0;\
	virtual long_t release() = 0;

#define PAF_DECL_REFCOUNT_INTERFACE \
	virtual long_t addRef();\
	virtual long_t release();


struct AutoRelease
{
	AutoRelease(RefCount* refCount)
	{
		m_refCount = refCount;
	}
	~AutoRelease()
	{
		SafeRelease(m_refCount);
	}
	RefCount* m_refCount;
};

struct AutoReleaseByAddress
{
	AutoReleaseByAddress(RefCount** refCount)
	{
		PAF_ASSERT(0 != refCount);
		m_refCount = refCount;
	}
	~AutoReleaseByAddress()
	{
		SafeRelease(*m_refCount);
	}
	RefCount** m_refCount;
};

END_PAFCORE
