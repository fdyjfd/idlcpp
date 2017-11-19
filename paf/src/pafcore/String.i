#{
#include "Utility.h"
#}

namespace pafcore
{
	class(value_object) #PAFCORE_EXPORT String
	{
		String();
		String(const String& arg);
		String(const char* str);
		bool empty() const;
		const char* c_str() const;
		int compare(const char* str) const;
		int compare(const String& arg) const;
		void assign(const char* str);
		void assign(const String& arg);
		void append(const char* str);
		void append(const String& arg);
#{
	public:
		String(String&& arg);
		~String();
	public:
		String& operator=(String&& arg);
		String& operator=(const char* str);
		String& operator=(const String& arg);
		String& operator+=(const char* str);
		String& operator+=(const String& arg);
		bool operator < (const String& arg) const;
	public:
		char* m_str;
#}
	};

#{
	inline bool String::empty() const
	{
		return 0 == *m_str;
	}

	inline const char* String::c_str() const
	{
		return m_str;
	}
#}

}
