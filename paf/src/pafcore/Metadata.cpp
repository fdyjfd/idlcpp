#include "Metadata.h"
#include "Type.h"
#include "Metadata.mh"
#include "Metadata.ic"
#include "Metadata.mc"
#include <string.h>

BEGIN_PAFCORE

Metadata::Metadata(const char* name)
{
	m_name = name;
	m_scope = 0;
}

Category Metadata::get__category_()
{
	Type* type = getType();
	return type->m_category;
}

bool Metadata::operator < (const Metadata& arg) const
{
	return strcmp(m_name, arg.m_name) < 0;
}

bool CompareMetaDataPtrByName::operator()(const Metadata* m1, const Metadata* m2)
{
	return strcmp(m1->m_name, m2->m_name) < 0;
}

END_PAFCORE
