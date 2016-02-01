#import "ClassType.i"

namespace pafcore
{

	abstract class $PAFCORE_EXPORT InstanceField(instance_field) : Metadata
	{
		Type ptr type get;
		ClassType ptr objectType get;
		size_t offset get;
		bool isArray get;
		bool isConstant get;
		$*
	public:
		InstanceField(const char* name, ClassType* objectType, Type* type, size_t offset, size_t arraySize, bool constant, bool array);
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
		ClassType* m_objectType;
		size_t m_offset;
		size_t m_arraySize;
		bool m_constant;
		bool m_array;
		*$
	};

}