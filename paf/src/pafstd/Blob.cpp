#include "Blob.h"
#include "Blob.mh"
#include "Blob.ic"
#include "Blob.mc"
#include "../pafcore/RefCountImpl.h"
#include <new>

BEGIN_PAFSTD

Blob::Blob(void* data, uint32_t length) : m_length(length), m_data(data)
{

}

class BlobImpl : public Blob
{
public:
	BlobImpl(void* data, uint32_t length) :
		Blob(data, length),
		m_refCount(1)
	{}

	virtual long_t addRef()
	{
		return pafcore::Atomic_Increment(&m_refCount);
	}
	virtual long_t release()
	{
		long_t res = pafcore::Atomic_Decrement(&m_refCount);
		if (0 == res)
		{
			this->~BlobImpl();
			PAF_ASSERT(m_data == (void*)(this + 1));
			char* buffer = (char*)this;
			delete[] buffer;
		}
		return res;
	}
public:
	long_t m_refCount;
};


class PartBlob : public Blob
{
public:
	PartBlob(Blob* blob, void* data, uint32_t length) :
		Blob(data, length),
		m_blob(blob)
	{
		blob->addRef();
	}
	~PartBlob()
	{
		m_blob->release();
	}
public:
	Blob* m_blob;
};

Blob* Blob::New(uint32_t length)
{
	uint32_t size = sizeof(BlobImpl) + length;
	char* buffer = paf_new char[size];
	BlobImpl* res = new(buffer)BlobImpl(buffer + sizeof(BlobImpl), length);
	return res;
}

Blob* Blob::PointerToBlob_(void* pointer, uint32_t length)
{
	Blob* blob = paf_new ::pafcore::AtomicRefCountImpl<Blob>(pointer, length);
	return blob;
}

Blob* Blob::SubBlob_(Blob* blob, uint32_t offset, uint32_t length)
{
	void* pointer = (byte_t*)blob->getData() + offset;
	PartBlob* res = paf_new::pafcore::AtomicRefCountImpl<PartBlob>(blob, pointer, length);
	return res;
}

END_PAFSTD
