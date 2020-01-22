#import "Reference.i"

namespace pafcore
{
	class(noncopyable) #PAFCORE_EXPORT Object : Reference
	{
#{
	public:
		virtual bool serializable() const
		{
			return true;
		}
#}
	};
}