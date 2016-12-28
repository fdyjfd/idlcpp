#import "ClassType.i"

namespace pafcore
{

#{
	class Variant;
	typedef ErrorCode(*StaticArrayPropertyGetter)(unsigned int index, Variant* value);
	typedef ErrorCode(*StaticArrayPropertySetter)(unsigned int index, Variant* value);
	typedef ErrorCode(*StaticArrayPropertySizer)(Variant* size);
	typedef ErrorCode(*StaticArrayPropertyResizer)(Variant* size);
#}

	abstract class(static_array_property)#PAFCORE_EXPORT StaticArrayProperty : Metadata
	{
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
		StaticArrayProperty(const char* name, 
			StaticArrayPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			StaticArrayPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			StaticArrayPropertySizer sizer, StaticArrayPropertyResizer resizer);
	public:
		StaticArrayPropertyGetter m_getter;
		StaticArrayPropertySetter m_setter;
		StaticArrayPropertySizer m_sizer;
		StaticArrayPropertyResizer m_resizer;
		Type* m_getterType;
		Type* m_setterType;
		byte_t m_getterPassing;
		byte_t m_setterPassing;
		bool m_getterConstant;
		bool m_setterConstant;
#}
	};

}