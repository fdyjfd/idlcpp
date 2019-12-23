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
	typedef ErrorCode(*InstancePropertyCandidateCount)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	typedef ErrorCode(*InstancePropertyGetCandidate)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);

	typedef ErrorCode(*ArrayInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, size_t index, Variant* value);
	typedef ErrorCode(*ArrayInstancePropertySizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	typedef ErrorCode(*ArrayInstancePropertyResizer)(InstanceProperty* instanceProperty, Variant* that, Variant* size);
	typedef ErrorCode(*ArrayInstancePropertyGetIterator)(InstanceProperty* instanceProperty, Variant* that, Variant* iterator);
	typedef ErrorCode(*ArrayInstancePropertyGetValue)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* value);

	typedef ErrorCode(*ListInstancePropertyPushBack)(InstanceProperty* instanceProperty, Variant* that, Variant* value);
	typedef ErrorCode(*ListInstancePropertyGetIterator)(InstanceProperty* instanceProperty, Variant* that, Variant* iterator);
	typedef ErrorCode(*ListInstancePropertyGetValue)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* value);
	typedef ErrorCode(*ListInstancePropertyInsert)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* value); 
	typedef ErrorCode(*ListInstancePropertyErase)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator);//移除后 iterator 指向下一个

	typedef ErrorCode(*MapInstancePropertyGetter)(InstanceProperty* instanceProperty, Variant* that, Variant* key, Variant* value);
	typedef ErrorCode(*MapInstancePropertySetter)(InstanceProperty* instanceProperty, Variant* that, Variant* key, Variant* value);
	typedef ErrorCode(*MapInstancePropertyGetIterator)(InstanceProperty* instanceProperty, Variant* that, Variant* iterator);
	typedef ErrorCode(*MapInstancePropertyGetKey)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* key);
	typedef ErrorCode(*MapInstancePropertyGetValue)(InstanceProperty* instanceProperty, Variant* that, Iterator* iterator, Variant* value);

#}

	abstract class(instance_property)#PAFCORE_EXPORT InstanceProperty : Metadata
	{
		ClassType* objectType { get };
		
		bool isArray { get };
		bool isList { get };
		bool isMap { get };
		bool isSimple { get };

		bool hasGetter { get };
		bool hasSetter { get };
		bool hasSizer { get };
		bool hasResizer { get };
		bool hasCandidate { get };
		bool serializable { get };

		Type* type { get };
		bool isPtr{ get };
		Type* keyType { get };
		bool isKeyPtr { get };
#{
	public:
		InstanceProperty(
			const char* name, 
			Attributes* attributes, 
			ClassType* objectType,
			Type* type, 
			bool isPtr,
			InstancePropertyGetter getter,
			InstancePropertySetter setter,
			InstancePropertyCandidateCount candidateCount = 0,
			InstancePropertyGetCandidate getCandidate = 0);

		InstanceProperty(
			const char* name, 
			Attributes* attributes, 
			ClassType* objectType,
			Type* type,
			bool isPtr,
			ArrayInstancePropertyGetter getter,
			ArrayInstancePropertySetter setter,
			ArrayInstancePropertySizer sizer, 
			ArrayInstancePropertyResizer resizer,
			ArrayInstancePropertyGetIterator getIterator,
			ArrayInstancePropertyGetValue getValue);


		InstanceProperty(
			const char* name,
			Attributes* attributes,
			ClassType* objectType,
			Type* type,
			bool isPtr,
			ListInstancePropertyPushBack pushBack,
			ListInstancePropertyGetIterator getIterator,
			ListInstancePropertyGetValue getValue,
			ListInstancePropertyInsert insert,
			ListInstancePropertyErase erase);

		InstanceProperty(
			const char* name,
			Attributes* attributes,
			ClassType* objectType,
			Type* type,
			bool isPtr,
			Type* keyType, 
			bool isKeyPtr,
			MapInstancePropertyGetter getter,
			MapInstancePropertySetter setter,
			MapInstancePropertyGetIterator getIterator,
			MapInstancePropertyGetKey getKey,
			MapInstancePropertyGetValue getValue);

	public:
		ClassType * m_objectType;
		union
		{
			struct
			{
				InstancePropertyGetter m_getter;
				InstancePropertySetter m_setter;
				InstancePropertyCandidateCount m_candidateCount;
				InstancePropertyGetCandidate m_getCandidate;
			};
			struct
			{
				ArrayInstancePropertyGetter m_arrayGetter;
				ArrayInstancePropertySetter m_arraySetter;
				ArrayInstancePropertySizer m_arraySizer;
				ArrayInstancePropertyResizer m_arrayResizer;
				ArrayInstancePropertyGetIterator m_arrayGetIterator;
				ArrayInstancePropertyGetValue m_arrayGetValue;
			};
			struct
			{
				ListInstancePropertyPushBack m_listPushBack;
				ListInstancePropertyGetIterator m_listGetIterator;
				ListInstancePropertyGetValue m_listGetValue;
				ListInstancePropertyInsert m_listInsert;
				ListInstancePropertyErase m_listErase;
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
		Type* m_type;
		Type* m_keyType;
		byte_t m_category;
		bool m_isPtr;
		bool m_isKeyPtr;
		bool m_serializable;
#}
	};
#{
	inline ClassType* InstanceProperty::get_objectType() const
	{
		return m_objectType;
	}

	inline bool InstanceProperty::get_isSimple() const
	{
		return simple_property == m_category;
	}

	inline bool InstanceProperty::get_isArray() const
	{
		return array_property == m_category;
	}

	inline bool InstanceProperty::get_isList() const
	{
		return list_property == m_category;
	}

	inline bool InstanceProperty::get_isMap() const
	{
		return map_property == m_category;
	}

	inline bool InstanceProperty::get_hasGetter() const
	{
		return (0 != m_getter);
	}

	inline bool InstanceProperty::get_hasSetter() const
	{
		return (0 != m_setter);
	}

	inline bool InstanceProperty::get_hasSizer() const
	{
		return (0 != m_arraySizer);
	}

	inline bool InstanceProperty::get_hasResizer() const
	{
		return (0 != m_arrayResizer);
	}

	inline bool InstanceProperty::get_hasCandidate() const
	{
		return get_isSimple() && m_candidateCount && m_getCandidate;
	}

	inline Type* InstanceProperty::get_type() const
	{
		return m_type;
	}

	inline bool InstanceProperty::get_isPtr() const
	{
		return m_isPtr;
	}

	inline Type* InstanceProperty::get_keyType() const
	{
		return m_keyType;
	}

	inline bool InstanceProperty::get_isKeyPtr() const
	{
		return m_isKeyPtr;
	}

	inline bool InstanceProperty::get_serializable() const
	{
		return m_serializable;
	}

#}

}