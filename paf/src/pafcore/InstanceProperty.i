#import "ClassType.i"

namespace pafcore
{

#{
	class Variant;
	typedef ErrorCode(*InstancePropertyGetter)(Variant* that, Variant* value);
	typedef ErrorCode(*InstancePropertySetter)(Variant* that, Variant* value);
#}

	abstract class(instance_property)#PAFCORE_EXPORT InstanceProperty : Metadata
	{
		ClassType* objectType get;
		bool hasGetter get;
		bool hasSetter get;

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
		InstanceProperty(const char* name, ClassType* objectType, 
			InstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			InstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant);
	public:
		ClassType* m_objectType;
		InstancePropertyGetter m_getter;
		InstancePropertySetter m_setter;
		Type* m_getterType;
		Type* m_setterType;
		byte_t m_getterPassing;
		byte_t m_setterPassing;
		bool m_getterConstant;
		bool m_setterConstant;
#}
	};

}