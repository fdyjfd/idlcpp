#import "Type.i"
#import "Enumerator.i"


namespace pafcore
{
#{
	class Variant;
	class InstanceProperty;
#}

	abstract class(enum_type)#PAFCORE_EXPORT EnumType : Type
	{
		size_t _getEnumeratorCount_();
		Enumerator* _getEnumerator_(size_t index);
		Enumerator* _getEnumeratorByValue_(int value);
		Enumerator* _getEnumeratorByName_(string_t name);
#{
	public:
		EnumType(const char* name, const char* declarationFile);
	public:
		Enumerator* findEnumerator(const char* name);
		Metadata* findMember(const char* name);
	public:
		static pafcore::ErrorCode Enum_get__name_(pafcore::InstanceProperty* instanceProperty, pafcore::Variant* that, pafcore::Variant* value);
	public:
		Enumerator* m_enumerators;
		size_t m_enumeratorCount;
		InstanceProperty* m_instanceProperties;
		size_t m_instancePropertyCount;
#}
	};
}