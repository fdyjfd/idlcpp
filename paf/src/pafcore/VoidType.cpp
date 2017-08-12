#include "VoidType.h"
#include "VoidType.mh"
#include "VoidType.ic"
#include "VoidType.mc"
#include "NameSpace.h"
#include "AutoRun.h"

BEGIN_PAFCORE

VoidType::VoidType() : Type("void", void_object)
{
	m_size = 1;
	NameSpace::GetGlobalNameSpace()->registerMember(this);
}

Metadata* VoidType::findMember(const char* name)
{
	return 0;
}

VoidType VoidType::s_instance;

END_PAFCORE

AUTO_REGISTER_TYPE(pafcore::VoidType)

