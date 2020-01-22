#import "Object.i"

namespace pafcore
{

	class(noncopyable) #PAFCORE_EXPORT FlexiblePropertySource : Object
	{
#{
	public:
		virtual bool propertyAvailabilityTest(string_t propertyName) const
		{
			return true;
		}

		virtual uint32_t dynamicInstancePropertyCount() const
		{
			return 0;
		}

		virtual InstanceProperty* dynamicInstanceProperty(uint32_t index) const
		{
			return 0;
		}

#}
	};
}