#pragma once
#include "Utility.h"

BEGIN_PAFCORE

class PAFCORE_EXPORT RefCount : public VirtualDestructor
{
public:
	virtual long_t addRef() = 0;
	virtual long_t release() = 0;
};

#define PAF_DECL_REFCOUNT_INTERFACE \
	virtual long_t addRef();\
	virtual long_t release();

#define PAF_DECL_REFCOUNT_INTERFACE_PURE \
	virtual long_t addRef() = 0;\
	virtual long_t release() = 0;

#define PAF_DECL_REFCOUNT_INTERFACE_IMPL \
	virtual long_t addRef(){return ++m_refCount;}\
	virtual long_t release(){long_t refCount = --m_refCount; if(0 == refCount) delete this; return refCount;}\
	private: long_t m_refCount; public:

#define PAF_DECL_REFCOUNT_INTERFACE_DUMMY_IMPL \
	virtual long_t addRef(){return 0;}\
	virtual long_t release(){delete this; return 0;}

//#define PAF_IMPL_REFCOUNT_INTERFACE(a) \
//	long_t a::addRef(){return ++m_refCount;}\
//	long_t a::release(){long_t refCount = --m_refCount; if(0 == refCount) delete this; return refCount;}
//
//#define PAF_IMPL_DUMMY_REFCOUNT_INTERFACE(a) \
//	long_t a::addRef(){return 0;}\
//	long_t a::release(){delete this; return 0;}


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
