#{
#include "Utility.h"
#}

namespace pafstd
{
	class(value_object) #PAFSTD_EXPORT FixedString
	{
#{
	public:
		FixedString(const char* str);
		~FixedString();
		const char* c_str() const;
		size_t length() const;
	private:
		FixedString(const FixedString& arg);
	public:
		char* m_str;
		size_t m_length;
#}
	};

#{
	inline const char* FixedString::c_str() const
	{
		return m_str;
	}

	inline size_t FixedString::length() const
	{
		return m_length;
	}
#}

}
