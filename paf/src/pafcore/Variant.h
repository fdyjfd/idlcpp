#pragma once

#include "Utility.h"

BEGIN_PAFCORE

class Type;
class Reference;
class Value;

const size_t max_primitive_type_size = 8;//(longlong_t, double_t, string_t);
const size_t unknown_array_size = ((size_t)-1) >> 1;

class PAFCORE_EXPORT Variant
{
public:
	enum Semantic
	{
		by_value,
		by_ref,
		by_ptr,
		by_array,
		by_new_ptr,
		by_new_array,
	};
public:
	Variant();
	~Variant();
private:
	Variant(const Variant& var);
	Variant& operator = (const Variant& var);
public:
	Semantic getSemantic();
	bool isNull();
	bool byValue();
	bool byRef();
	//bool isArray();
	bool isConstant();
	void clear();
	void unhold();
	void move(Variant& var);
	bool subscript(Variant& var, size_t index);

	void assignPrimitive(Type* type, const void* pointer);
	void assignPrimitiveForNew(Type* type, const void* pointer);
	void assignEnum(Type* type, const void* pointer);
	
	void assignVoidPtr(const void* pointer, bool constant);
	void assignPrimitivePtr(Type* type, const void* pointer, bool constant, Semantic semantic);
	void assignEnumPtr(Type* type, const void* pointer, bool constant, Semantic semantic);
	void assignValuePtr(Type* type, const void* pointer, bool constant, Semantic semantic);
	void assignReferencePtr(Type* type, const void* pointer, bool constant, Semantic semantic);
	void assignReferencePtr(Reference* pointer, bool constant, Semantic semantic);

	void assignNullPrimitive(Type* type);
	void assignNullEnum(Type* type);
	void assignNullPtr(Type* type);
	
	void assignPtr(Type* type, const void* pointer, bool constant, Semantic semantic);
	void assignArray(Type* type, const void* pointer, size_t arraySize, bool constant, Semantic semantic);

	bool castToPrimitive(Type* dstType, void* dst) const;
	bool castToEnum(Type* dstType, void* dst) const;
	bool castToValue(Type* dstType, void* dst) const;
	bool castToReference(Type* dstType, void* dst) const;

	bool castToVoidPtr(void** dst) const;
	bool castToPrimitivePtr(Type* dstType, void** dst) const;
	bool castToEnumPtr(Type* dstType, void** dst) const;
	bool castToValuePtr(Type* dstType, void** dst) const;
	bool castToReferencePtr(Type* dstType, void** dst) const;

	bool castToVoidPtrAllowNull(void** dst) const;
	bool castToPrimitivePtrAllowNull(Type* dstType, void** dst) const;
	bool castToEnumPtrAllowNull(Type* dstType, void** dst) const;
	bool castToValuePtrAllowNull(Type* dstType, void** dst) const;
	bool castToReferencePtrAllowNull(Type* dstType, void** dst) const;

	bool castToObjectPtr(Type* dstType, void** dst) const;
	bool castToObject(Type* dstType, void* dst) const;

	void reinterpretCastToPtr(Variant& var, Type* dstType) const;

	void setTemporary();
	bool isTemporary() const;

	void setSubClassProxy();
	bool isSubClassProxy() const;
public:
	Type* m_type;
	void* m_pointer;
	byte_t m_primitiveValue[max_primitive_type_size];
	size_t m_arraySize;
	byte_t m_semantic;
	bool m_constant;
	bool m_temporary;
	bool m_subClassProxy;
};

//------------------------------------------------------------------------------
inline bool Variant::isNull()
{
	return 0 == m_pointer;
}

inline bool Variant::byValue()
{
	return (by_value == m_semantic);
}

inline bool Variant::byRef()
{
	return (by_ref == m_semantic);
}
//
//inline bool Variant::isArray()
//{
//	return (by_array == m_semantic || by_new_array == m_semantic);
//}

inline bool Variant::isConstant()
{
	return m_constant;
}

inline Variant::Semantic Variant::getSemantic()
{
	return (Semantic)m_semantic;
}

inline void Variant::setTemporary()
{
	m_temporary = true;
}

inline bool Variant::isTemporary() const
{
	return m_temporary;
}

inline void Variant::setSubClassProxy()
{
	m_subClassProxy = true;
}

inline bool Variant::isSubClassProxy() const
{
	return m_subClassProxy;
}

END_PAFCORE
