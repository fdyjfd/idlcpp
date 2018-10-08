#import "Metadata.i"
#import "Type.i"

namespace pafcore
{

#{
	struct Attributes;
	class StaticProperty;
	class Iterator;
	class Variant;

	typedef ErrorCode(*StaticPropertyGetter)(Variant* value);
	typedef ErrorCode(*StaticPropertySetter)(Variant* value);

	typedef ErrorCode(*ArrayStaticPropertyGetter)(size_t index, Variant* value);
	typedef ErrorCode(*ArrayStaticPropertySetter)(size_t index, Variant* value);
	typedef ErrorCode(*ArrayStaticPropertySizer)(Variant* size);
	typedef ErrorCode(*ArrayStaticPropertyResizer)(Variant* size);

	typedef ErrorCode(*MapStaticPropertyGetter)(Variant* key, Variant* value);
	typedef ErrorCode(*MapStaticPropertySetter)(Variant* key, Variant* value);
	typedef ErrorCode(*MapStaticPropertyGetIterator)(Variant* iterator);
	typedef ErrorCode(*MapStaticPropertyGetKey)(Iterator* iterator, Variant* key);
	typedef ErrorCode(*MapStaticPropertyGetValue)(Iterator* iterator, Variant* value);

#}

	abstract class(static_property)#PAFCORE_EXPORT StaticProperty : Metadata
	{
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
#{
	public:
		StaticProperty(const char* name, Attributes* attributes,
			StaticPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			StaticPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant);

		StaticProperty(const char* name, Attributes* attributes,
			ArrayStaticPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			ArrayStaticPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			ArrayStaticPropertySizer sizer, 
			ArrayStaticPropertyResizer resizer);

		StaticProperty(const char* name, Attributes* attributes,
			MapStaticPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
			MapStaticPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
			MapStaticPropertyGetIterator getIterator,
			MapStaticPropertyGetKey getKey,
			MapStaticPropertyGetValue getValue);
	public:
		union
		{
			struct
			{
				StaticPropertyGetter m_getter;
				StaticPropertySetter m_setter;
			};
			struct
			{
				ArrayStaticPropertyGetter m_arrayGetter;
				ArrayStaticPropertySetter m_arraySetter;
				ArrayStaticPropertySizer m_arraySizer;
				ArrayStaticPropertyResizer m_arrayResizer;
			};
			struct
			{
				MapStaticPropertyGetter m_mapGetter;
				MapStaticPropertySetter m_mapSetter;
				MapStaticPropertyGetIterator m_mapGetIterator;
				MapStaticPropertyGetKey m_mapGetKey;
				MapStaticPropertyGetValue m_mapGetValue;
			};
		};
		Type* m_getterType;
		Type* m_setterType;
		byte_t m_getterPassing;
		byte_t m_setterPassing;
		bool m_getterConstant;
		bool m_setterConstant;
		PropertyCategory m_category;
#}
	};

}