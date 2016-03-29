#include "NullType.h"
#include "NameSpace.h"
#include "AutoRun.h"
#include "NullType.mh"
#include "NullType.ic"
#include "NullType.mc"

BEGIN_PAFCORE

NullType::NullType() : Type("null_t", null_object)
{
	NameSpace::GetGlobalNameSpace()->registerMember(this);
}

Metadata* NullType::findMember(const char* name)
{
	return 0;
}

NullType* NullType::GetSingleton()
{
	static NullType s_instance;
	return &s_instance;
}

END_PAFCORE

AUTO_REGISTER_TYPE(pafcore::NullType)

