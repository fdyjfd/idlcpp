#import "ClassType.i"

namespace pafcore
{

#{
	class Variant;
	typedef ErrorCode(*InstanceArrayPropertyGetter)(Variant* that, unsigned int index, Variant* value);
	typedef ErrorCode(*InstanceArrayPropertySetter)(Variant* that, unsigned int index, Variant* value);
	typedef ErrorCode(*InstanceArrayPropertySizer)(Variant* that, Variant* size);
	typedef ErrorCode(*InstanceArrayPropertyResizer)(Variant* that, Variant* size);
#}

	abstract class(instance_array_property)#PAFCORE_EXPORT InstanceArrayProperty : Metadata
	{
		ClassType* objectType get;
		bool hasGetter get;
		bool hasSetter get;
		bool hasSizer get;
		bool hasResizer get;

		Type* getterType get;
		bool getterByValue get;
		bool getterByRef get;
		bool getterByPtr get;
		bool getterConstant get;

		Type* setterType get;
		bool setterByValue get;
		bool setterByRef get;
		bool setterByPtr get;
		bool setterConstant get;

#{
	public:
		InstanceArrayProperty(const char* name, ClassType* objectType, 
			InstanceArrayPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			InstanceArrayPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			InstanceArrayPropertySizer sizer, InstanceArrayPropertyResizer resizer);
	public:
		ClassType* m_objectType;
		InstanceArrayPropertyGetter m_getter;
		InstanceArrayPropertySetter m_setter;
		InstanceArrayPropertySizer m_sizer;
		InstanceArrayPropertyResizer m_resizer;
		Type* m_getterType;
		Type* m_setterType;
		byte_t m_getterPassing;
		byte_t m_setterPassing;
		bool m_getterConstant;
		bool m_setterConstant;
#}
	};

}