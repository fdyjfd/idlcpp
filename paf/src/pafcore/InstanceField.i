#import "ClassType.i"

namespace pafcore
{

	abstract class(instance_field)$PAFCORE_EXPORT InstanceField : Metadata
	{
		Type* type get;
		ClassType* objectType get;
		size_t offset get;
		bool isArray get;
		bool isPointer get;
		bool isConstant get;
		$*
	public:
		InstanceField(const char* name, ClassType* objectType, Type* type, size_t offset, size_t arraySize, bool constant, TypeCompound tc);
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
		ClassType* m_objectType;
		size_t m_offset;
		size_t m_arraySize;
		bool m_constant;
		byte_t m_typeCompound;
		*$
	};

}