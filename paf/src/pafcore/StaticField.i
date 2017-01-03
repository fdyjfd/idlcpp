#import "Type.i"

namespace pafcore
{

#{
	struct Attributes;
#}

	abstract class(static_field)#PAFCORE_EXPORT StaticField : Metadata
	{
		Type* type get;
		size_t address get;
		bool isConstant get;
		bool isArray get;
		bool isPointer get;
#{
	public:
		StaticField(const char* name, Attributes* attributes, Type* type, size_t address, size_t arraySize, bool constant, TypeCompound tc);
	public:
		bool isArray()
		{
			return tc_array == m_typeCompound;
		}
		bool isPointer()
		{
			return tc_pointer == m_typeCompound;
		}
		bool isConstant()
		{
			return m_constant;
		}
	public:
		Type* m_type;
		size_t m_address;
		size_t m_arraySize;
		bool m_constant;
		byte_t m_typeCompound;
#}
	};

}