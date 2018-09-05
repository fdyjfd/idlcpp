#import "ClassType.i"

namespace pafcore
{

#{
	struct Attributes;
	class InstanceProperty;
	class Variant;
	typedef ErrorCode(*InstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, Variant* value);
	typedef ErrorCode(*InstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	typedef ErrorCode(*ArrayInstancePropertyResizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
#}

	abstract class(instance_property)#PAFCORE_EXPORT InstanceProperty : Metadata
	{
		ClassType* objectType get;
		
		bool isArray get;

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
		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			InstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			InstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant);
		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			ArrayInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			ArrayInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			ArrayInstancePropertySizer sizer, ArrayInstancePropertyResizer resizer);
	public:
		ClassType * m_objectType;
		union
		{
			InstancePropertyGetter m_getter;
			ArrayInstancePropertyGetter m_arrayGetter;
		};
		union
		{
			InstancePropertySetter m_setter;
			ArrayInstancePropertySetter m_arraySetter;
		};
		ArrayInstancePropertySizer m_sizer;
		ArrayInstancePropertyResizer m_resizer;
		Type* m_getterType;
		Type* m_setterType;
		byte_t m_getterPassing;
		byte_t m_setterPassing;
		bool m_getterConstant;
		bool m_setterConstant;
		bool m_array;
#}
	};

}