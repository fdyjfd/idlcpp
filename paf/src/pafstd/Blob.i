#import "Reference.i"

#{
#include "Utility.h"
#}

namespace pafstd
{
	class #PAFSTD_EXPORT Blob : Reference
	{
		void* getData();
		uint32_t getLength() const;
		static Blob+ New(uint32_t length);
#{
	public:
		static Blob* SubBlob_(Blob* blob, uint32_t offset, uint32_t length);
		static Blob* PointerToBlob_(void* pointer, uint32_t length);
	public:
		Blob(void* data, uint32_t length);
	public:
		const void* getData() const
		{
			return m_data;
		}
	public:
		void* m_data;
		uint32_t m_length;
#}
	};

#{
	inline void* Blob::getData()
	{
		return m_data;
	}

	inline uint32_t Blob::getLength() const
	{
		return m_length;
	}
#}
}

