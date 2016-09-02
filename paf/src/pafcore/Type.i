#import "Metadata.i"

namespace pafcore
{
	abstract class #PAFCORE_EXPORT Type : Metadata
	{
		size_t _size_ get;
#{
	public:
		Type(const char* name, Category category);
	public:
		virtual void destroyInstance(void* address);
		virtual void destroyArray(void* address);
		virtual void assign(void* dst, const void* src);
		virtual Metadata* findMember(const char* name) = 0;
	public:
		bool isPrimitive();
		bool isEnum();
		bool isValue();
		bool isReference();
	public:
		Category m_category;
		size_t m_size;
#}
	};

#{

	inline size_t Type::get__size_()
	{
		return m_size;
	}
	inline bool Type::isPrimitive()
	{
		return primitive_object == m_category;
	}
	inline bool Type::isEnum()
	{
		return enum_object == m_category;
	}
	inline bool Type::isValue()
	{
		return value_object == m_category;
	}
	inline bool Type::isReference()
	{
		return reference_object <= m_category;
	}

#}

}
