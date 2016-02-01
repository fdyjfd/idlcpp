#import "Type.i"
#import "Enumerator.i"


namespace pafcore
{
	$*
	class Variant;
	class InstanceProperty;
	*$

	abstract class $PAFCORE_EXPORT EnumType(enum_type) : Type
	{
		size_t _getEnumeratorCount_();
		Enumerator ptr _getEnumerator_(size_t index);
		Enumerator ptr _getEnumeratorByValue_(int value);
		Enumerator ptr _getEnumeratorByName_(const char ptr name);
		$*
	public:
		EnumType(const char* name);
	public:
		Enumerator* findEnumerator(const char * name);
		Metadata* findMember(const char* name);
	public:
		static pafcore::ErrorCode Enum_get__name_(pafcore::Variant* that, pafcore::Variant* value);
	public:
		Enumerator* m_enumerators;
		size_t m_enumeratorCount;
		InstanceProperty* m_properties;
		size_t m_propertyCount;
		*$
	};
}