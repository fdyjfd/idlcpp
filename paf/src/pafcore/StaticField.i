#import "Type.i"

namespace pafcore
{

	abstract class $PAFCORE_EXPORT StaticField(static_field) : Metadata
	{
		Type ptr type get;
		size_t address get;
		bool isConstant get;
		bool isArray get;
		$*
	public:
		StaticField(const char* name, Type* type, size_t address, size_t arraySize, bool constant, bool array);
	public:
		bool isArray()
		{
			return m_array;
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
		bool m_array;
		*$
	};

}