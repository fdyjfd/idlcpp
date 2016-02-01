#import "Typedef.i"
#import "Type.i"

$$#include "Utility.h"

namespace pafcore
{

	class $PAFCORE_EXPORT Reference
	{
	meta:
		virtual Type ptr getType();
		$*
	public:
		virtual ~Reference(){}
		virtual long_t addRef();
		virtual long_t release();
		virtual void* getAddress();
		*$
	};
}