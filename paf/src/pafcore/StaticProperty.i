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
	typedef ErrorCode(*StaticPropertyCandidateCount)(Variant* size);
	typedef ErrorCode(*StaticPropertyGetCandidate)(size_t index, Variant* value);

	typedef ErrorCode(*ArrayStaticPropertyGetter)(size_t index, Variant* value);
	typedef ErrorCode(*ArrayStaticPropertySetter)(size_t index, Variant* value);
	typedef ErrorCode(*ArrayStaticPropertySizer)(Variant* size);
	typedef ErrorCode(*ArrayStaticPropertyResizer)(Variant* size);
	typedef ErrorCode(*ArrayStaticPropertyGetIterator)(Variant* iterator);
	typedef ErrorCode(*ArrayStaticPropertyGetValue)(Iterator* iterator, Variant* value);

	typedef ErrorCode(*ListStaticPropertyPushBack)(Variant* value);
	typedef ErrorCode(*ListStaticPropertyGetIterator)(Variant* iterator);
	typedef ErrorCode(*ListStaticPropertyGetValue)(Iterator* iterator, Variant* value);
	typedef ErrorCode(*ListStaticPropertyInsert)(Iterator* iterator, Variant* value);
	typedef ErrorCode(*ListStaticPropertyErase)(Iterator* iterator);

	typedef ErrorCode(*MapStaticPropertyGetter)(Variant* key, Variant* value);
	typedef ErrorCode(*MapStaticPropertySetter)(Variant* key, Variant* value);
	typedef ErrorCode(*MapStaticPropertyGetIterator)(Variant* iterator);
	typedef ErrorCode(*MapStaticPropertyGetKey)(Iterator* iterator, Variant* key);
	typedef ErrorCode(*MapStaticPropertyGetValue)(Iterator* iterator, Variant* value);

#}

	abstract class(static_property)#PAFCORE_EXPORT StaticProperty : Metadata
	{
		bool isSimple { get };
		bool isArray { get };
		bool isList { get };
		bool isMap { get };

		bool hasGetter { get };
		bool hasSetter { get };
		bool hasSizer { get };
		bool hasResizer { get };
		bool hasCandidate{ get };

		Type* type { get };
		bool isPtr { get };

		Type* keyType { get };
		bool isKeyPtr { get };
#{
	public:
		StaticProperty(
			const char* name, 
			Attributes* attributes,
			Type* type,
			bool isPtr,
			StaticPropertyGetter getter,
			StaticPropertySetter setter,
			StaticPropertyCandidateCount candidateCount = 0,
			StaticPropertyGetCandidate getCandidate = 0);

		StaticProperty(
			const char* name,
			Attributes* attributes,
			Type* type,
			bool isPtr,
			ArrayStaticPropertyGetter getter,
			ArrayStaticPropertySetter setter,
			ArrayStaticPropertySizer sizer,
			ArrayStaticPropertyResizer resizer,
			ArrayStaticPropertyGetIterator getIterator,
			ArrayStaticPropertyGetValue getValue);

		StaticProperty(
			const char* name,
			Attributes* attributes,
			Type* type,
			bool isPtr,
			ListStaticPropertyPushBack pushBack,
			ListStaticPropertyGetIterator getIterator,
			ListStaticPropertyGetValue getValue,
			ListStaticPropertyInsert insert,
			ListStaticPropertyErase erase);

		StaticProperty(
			const char* name,
			Attributes* attributes,
			Type* type,
			bool isPtr,
			Type* keyType,
			bool isKeyPtr,
			MapStaticPropertyGetter getter,
			MapStaticPropertySetter setter,
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
				StaticPropertyCandidateCount m_candidateCount;
				StaticPropertyGetCandidate m_getCandidate;
			};
			struct
			{
				ArrayStaticPropertyGetter m_arrayGetter;
				ArrayStaticPropertySetter m_arraySetter;
				ArrayStaticPropertySizer m_arraySizer;
				ArrayStaticPropertyResizer m_arrayResizer;
				ArrayStaticPropertyGetIterator m_arrayGetIterator;
				ArrayStaticPropertyGetValue m_arrayGetValue;
			};
			struct
			{
				ListStaticPropertyPushBack m_listPushBack;
				ListStaticPropertyGetIterator m_listGetIterator;
				ListStaticPropertyGetValue m_listGetValue;
				ListStaticPropertyInsert m_listInsert;
				ListStaticPropertyErase m_listErase;
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
		Type* m_type;
		Type* m_keyType;
		bool m_isPtr;
		bool m_isKeyPtr;
		byte_t m_category;
#}
	};

}