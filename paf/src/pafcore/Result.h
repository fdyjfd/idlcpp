//DO NOT EDIT THIS FILE, it is generated by idlcpp
//aifeng_peng@hotmail.com

#pragma once

#include "./Metadata.h"
namespace pafcore{ class Type; }

namespace pafcore
{
class Variant;

	class PAFCORE_EXPORT Result : public Metadata
	{
	public:
		virtual ::pafcore::Type* getType();

		Type* get_type();
		bool get_byValue();
		bool get_byRef();
		bool get_byPtr();
		bool get_byNew();
		bool get_byNewArray();
		bool get_isConstant();

	public:
		Result(Type* type, bool constant, Passing passing);
	public:
		Type* m_type;
		bool m_constant;
		byte_t m_passing;
		
	};

}