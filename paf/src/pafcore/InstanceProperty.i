#import "ClassType.i"

namespace pafcore
{

#{
	struct Attributes;
	class InstanceProperty;
	class Iterator;
	class Variant;
	
	typedef ErrorCode(*InstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, Variant* value);
	typedef ErrorCode(*InstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, Variant* value);

	typedef ErrorCode(*ArrayInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	typedef ErrorCode(*ArrayInstancePropertyResizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	
	typedef ErrorCode(*MapInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, Variant* key, Variant* value);
	typedef ErrorCode(*MapInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, Variant* key, Variant* value);
	typedef ErrorCode(*MapInstancePropertyGetIterator)(InstanceProperty* instanceProperty, Variant* that, Variant* iterator);
	typedef ErrorCode(*MapInstancePropertyGetKey)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* key);
	typedef ErrorCode(*MapInstancePropertyGetValue)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* value);

#}

	abstract class(instance_property)#PAFCORE_EXPORT InstanceProperty : Metadata
	{
		ClassType* objectType get;
		
		bool isArray get;
		bool isMap get;
		bool isSimple get;

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

		Type* keyType get;
		bool keyByValue get;
		bool keyByRef get;
		bool keyByPtr get;
		bool keyConstant get;

#{
	public:
		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			InstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			InstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant);

		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			ArrayInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			ArrayInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			ArrayInstancePropertySizer sizer, 
			ArrayInstancePropertyResizer resizer);

		InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
			MapInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			MapInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			MapInstancePropertyGetIterator getIterator, 
			MapInstancePropertyGetKey getKey,
			MapInstancePropertyGetValue getValue,
			Type* keyType, Passing keyPassing, bool keyConstant);
	public:
		ClassType * m_objectType;
		union
		{
			struct
			{
				InstancePropertyGetter m_getter;
				InstancePropertySetter m_setter;
			};
			struct
			{
				ArrayInstancePropertyGetter m_arrayGetter;
				ArrayInstancePropertySetter m_arraySetter;
				ArrayInstancePropertySizer m_arraySizer;
				ArrayInstancePropertyResizer m_arrayResizer;
			};
			struct
			{
				MapInstancePropertyGetter m_mapGetter;
				MapInstancePropertySetter m_mapSetter;
				MapInstancePropertyGetIterator m_mapGetIterator;
				MapInstancePropertyGetKey m_mapGetKey;
				MapInstancePropertyGetValue m_mapGetValue;
			};
		};
		Type* m_getterType;
		Type* m_setterType;
		Type* m_keyType;
		byte_t m_getterPassing;
		byte_t m_setterPassing;
		byte_t m_keyPassing;
		bool m_getterConstant;
		bool m_setterConstant;
		bool m_keyConstant;
		PropertyCategory m_category;
#}
	};

}