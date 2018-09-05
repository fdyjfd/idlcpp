#include "Reference.h"
#include "Reference.mh"
#include "Reference.ic"
#include "Reference.mc"

#ifdef _DEBUG
#include "Debug.h"
#endif

BEGIN_PAFCORE

#ifdef _DEBUG

class ReferenceLeakReporter
{
public:
	~ReferenceLeakReporter()
	{
		m_liveObjects.lock();
		for (auto& item : m_liveObjects.m_objects)
		{
			Reference* reference = item.first;
			size_t serialNumber = item.second;
			if (!reference->isTypeOf<Metadata>())
			{
				char buf[1024];
				reference->addRef();
				long_t refCount = reference->release();
				pafcore::ClassType* classType = reference->getType();
				sprintf_s(buf, "pafcore Warning: Live Reference at 0x%p Type: %s, RefCount:%d, SerialNumber:%llu\n",
					reference, classType->get__name_().c_str(), refCount, serialNumber);
				OutputDebugStringA(buf);
			}
		}
		m_liveObjects.unlock();
	}
public:
	void onReferenceConstruct(Reference* reference)
	{
		m_liveObjects.addPtr(reference);
	}
	void onReferenceDestruct(Reference* reference)
	{
		m_liveObjects.removePtr(reference);
	}
public:
	LiveObjects<Reference> m_liveObjects;
public:
	static ReferenceLeakReporter* GetInstance()
	{
		static ReferenceLeakReporter s_instance;
		return &s_instance;
	}
};

Reference::Reference()
{
	ReferenceLeakReporter::GetInstance()->onReferenceConstruct(this);
}

Reference::Reference(const Reference&)
{
	ReferenceLeakReporter::GetInstance()->onReferenceConstruct(this);
}

Reference::~Reference()
{
	ReferenceLeakReporter::GetInstance()->onReferenceDestruct(this);
}

#endif//_DEBUG

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
