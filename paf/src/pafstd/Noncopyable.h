#pragma once

#include "Utility.h"

BEGIN_PAFSTD

namespace Noncopyable_  // protection from unintended ADL  
{
	class Noncopyable
	{
	protected:
		Noncopyable() {}
		~Noncopyable() {}
	private:  // emphasize the following members are private  
		Noncopyable(const Noncopyable&);
		const Noncopyable& operator=(const Noncopyable&);
	};
}

typedef Noncopyable_::Noncopyable Noncopyable;

END_PAFSTD
