#import "Metadata.i"

namespace pafcore
{
	abstract class #PAFCORE_EXPORT Type : Metadata
	{
		size_t _size_ get;
#{
	public:
		Type(const char* name, Category category);
		~Type();
	public:
		virtual void destroyInstance(void* address);
		virtual void destroyArray(void* address);
		virtual void assign(void* dst, const void* src);
		virtual Metadata* findMember(const char* name) = 0;
	public:
		bool isPrimitive() const;
		bool isEnum() const;
		bool isValue() const;
		bool isReference() const;
	public:
		Category m_category;
		size_t m_size;
		Metadata* m_enclosing;
#}
	};

#{

	inline size_t Type::get__size_() const
	{
		return m_size;
	}
	inline bool Type::isPrimitive() const
	{
		return primitive_object == m_category;
	}
	inline bool Type::isEnum() const
	{
		return enum_object == m_category;
	}
	inline bool Type::isValue() const
	{
		return value_object == m_category;
	}
	inline bool Type::isReference() const
	{
		return reference_object <= m_category;
	}

#}

}
