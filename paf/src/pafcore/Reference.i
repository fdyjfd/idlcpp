#import "Typedef.i"
#import "Type.i"

$$#include "Utility.h"

namespace pafcore
{
	class $PAFCORE_EXPORT Reference
	{
		$*
	public:
		virtual ~Reference() {}
		*$
		virtual long_t addRef();
		virtual long_t release();
		virtual long_t getRefCount();
	meta:
		virtual Type ptr getType();
		virtual size_t getAddress();
	};
}