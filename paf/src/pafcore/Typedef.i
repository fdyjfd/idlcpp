#{

typedef bool					bool_t;
typedef char					char_t;
typedef signed char				schar_t;
typedef unsigned char			uchar_t;
typedef short					short_t;
typedef unsigned short			ushort_t;
typedef long					long_t;
typedef unsigned long			ulong_t;
typedef long long				longlong_t;
typedef unsigned long long		ulonglong_t;
typedef int						int_t;
typedef unsigned int			uint_t;
typedef float					float_t;
typedef double					double_t;
typedef long double				longdouble_t;

typedef unsigned char			byte_t;
typedef signed char				int8_t;
typedef unsigned char			uint8_t;
typedef short					int16_t;
typedef unsigned short			uint16_t;
typedef int						int32_t;
typedef unsigned int			uint32_t;
typedef long long				int64_t;
typedef unsigned long long		uint64_t;

#ifdef _WIN64
typedef unsigned __int64		size_t;
typedef __int64					ptrdiff_t;
#else
typedef unsigned int			size_t;
typedef int						ptrdiff_t;
#endif

class string_t
{
public:
	string_t() : m_str("")
	{}
	string_t(const char* str) : m_str(str ? str : "")
	{}
public:
	const char* c_str() const
	{
		return m_str;
	}
	operator const char* () const
	{
		return m_str;
	}
	bool empty() const
	{
		return (0 == *m_str);
	}
	void assign(const char* str)
	{
		m_str = str ? str : "";
	}
protected:
	const char* m_str;
};

template<typename T>
struct RuntimeTypeOf
{};

#}

primitive bool_t;
primitive char_t;
primitive schar_t;
primitive uchar_t;
primitive short_t;
primitive ushort_t;
primitive long_t;
primitive ulong_t;
primitive longlong_t;
primitive ulonglong_t;
primitive int_t;
primitive uint_t;
primitive float_t;
primitive double_t;
primitive longdouble_t;
primitive byte_t;
primitive int8_t;
primitive uint8_t;
primitive int16_t;
primitive uint16_t;
primitive int32_t;
primitive uint32_t;
primitive int64_t;
primitive uint64_t;
primitive size_t;
primitive ptrdiff_t;

namespace pafcore
{
	struct Buffer
	{
#{
		void* pointer;
		size_t size;
		Buffer()
		{}
		Buffer(void*p, size_t s) : pointer(p), size(s)
		{}
#}
	};
}