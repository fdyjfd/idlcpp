#include <new.h>
#include "Python.h"
#include "../pafcore/Variant.h"
#include "../pafcore/InstanceMethod.h"
#include "../pafcore/NameSpace.h"
#include "../pafcore/NameSpace.mh"
#include "../pafcore/Metadata.mh"
#include "../pafcore/Type.mh"
#include "../pafcore/ClassType.h"
#include "../pafcore/EnumType.h"
#include "../pafcore/EnumType.mh"
#include "../pafcore/InstanceField.h"
#include "../pafcore/StaticField.h"
#include "../pafcore/InstanceProperty.h"
#include "../pafcore/InstanceArrayProperty.h"
#include "../pafcore/StaticProperty.h"
#include "../pafcore/StaticArrayProperty.h"
#include "../pafcore/InstanceMethod.h"
#include "../pafcore/StaticMethod.h"
#include "../pafcore/Enumerator.h"
#include "../pafcore/PrimitiveType.h"

#include "Utility.h"
#include "PythonWrapper.h"
#include "PythonSubclassInvoker.h"

BEGIN_PAFPYTHON

const size_t max_param_count = 20;

struct VariantWrapper
{
	PyObject_HEAD
	char m_var[sizeof(pafcore::Variant)];
};

static PyTypeObject s_VariantWrapper_Type = 
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"PafPython.Object",
	sizeof(VariantWrapper),
};

struct InstanceArrayPropertyWrapper
{
	PyObject_HEAD
	pafcore::InstanceArrayProperty* m_property;
	VariantWrapper* m_self;
};

static PyTypeObject s_InstanceArrayPropertyWrapper_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"PafPython.InstanceArrayProperty",
	sizeof(InstanceArrayPropertyWrapper),
};

struct StaticArrayPropertyWrapper
{
	PyObject_HEAD
	pafcore::StaticArrayProperty* m_property;
};

static PyTypeObject s_StaticArrayPropertyWrapper_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"PafPython.StaticArrayProperty",
	sizeof(StaticArrayPropertyWrapper),
};

struct InstanceMethodWrapper
{
	PyObject_HEAD
	pafcore::InstanceMethod* m_method;
	VariantWrapper* m_self;
};

static PyTypeObject s_InstanceMethodWrapper_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"PafPython.InstanceMethod",
	sizeof(InstanceMethodWrapper),
};

struct FunctionInvokerWrapper
{
	PyObject_HEAD
	pafcore::FunctionInvoker m_invoker;
};

static PyTypeObject s_FunctionInvokerWrapper_Type = 
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"PafPython.FunctionInvoker",
	sizeof(FunctionInvokerWrapper),
};

struct ProxyCreatorWrapper
{
	PyObject_HEAD
	pafcore::ClassType* m_classType;
};

static PyTypeObject s_ProxyCreatorWrapper_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"PafPython.ProxyCreator",
	sizeof(ProxyCreatorWrapper),
};

struct TypeCasterWrapper
{
	PyObject_HEAD
	pafcore::Type* m_type;
};

static PyTypeObject s_TypeCasterWrapper_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"PafPython.TypeCaster",
	sizeof(TypeCasterWrapper),
};

PyObject* VariantWrapper_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	VariantWrapper* self;
	self = (VariantWrapper*)type->tp_alloc(type, 0);
	if (self != NULL)
	{
		void* var = self->m_var;
		pafcore::Variant* variant = new(var)pafcore::Variant;
	}
	return (PyObject*)self;
}

void VariantWrapper_dealloc(VariantWrapper* self)
{
	pafcore::Variant* variant = (pafcore::Variant*)self->m_var;
	variant->~Variant();
	Py_TYPE(self)->tp_free((PyObject*)self);
}

PyObject* FunctionInvokerWrapper_new(PyTypeObject* type, PyObject *args, PyObject *kwds)
{
	FunctionInvokerWrapper* self;
	self = (FunctionInvokerWrapper*)type->tp_alloc(type, 0);
	self->m_invoker = 0;
	return (PyObject*)self;
}

void InstanceArrayPropertyWrapper_dealloc(InstanceArrayPropertyWrapper* self)
{
	Py_XDECREF(self->m_self);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

PyObject* InstanceArrayPropertyWrapper_new(PyTypeObject* type, PyObject *args, PyObject *kwds)
{
	InstanceArrayPropertyWrapper* self;
	self = (InstanceArrayPropertyWrapper*)type->tp_alloc(type, 0);
	self->m_property = 0;
	self->m_self = 0;
	return (PyObject*)self;
}

PyObject* StaticArrayPropertyWrapper_new(PyTypeObject* type, PyObject *args, PyObject *kwds)
{
	StaticArrayPropertyWrapper* self;
	self = (StaticArrayPropertyWrapper*)type->tp_alloc(type, 0);
	self->m_property = 0;
	return (PyObject*)self;
}

void InstanceMethodWrapper_dealloc(InstanceMethodWrapper* self)
{
	Py_XDECREF(self->m_self);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

PyObject* InstanceMethodWrapper_new(PyTypeObject* type, PyObject *args, PyObject *kwds)
{
	InstanceMethodWrapper* self;
	self = (InstanceMethodWrapper*)type->tp_alloc(type, 0);
	self->m_method = 0;
	self->m_self = 0;
	return (PyObject*)self;
}

PyObject* ProxyCreatorWrapper_new(PyTypeObject* type, PyObject *args, PyObject *kwds)
{
	ProxyCreatorWrapper* self;
	self = (ProxyCreatorWrapper*)type->tp_alloc(type, 0);
	self->m_classType = 0;
	return (PyObject*)self;
}

PyObject* TypeCasterWrapper_new(PyTypeObject* type, PyObject *args, PyObject *kwds)
{
	TypeCasterWrapper* self;
	self = (TypeCasterWrapper*)type->tp_alloc(type, 0);
	self->m_type = 0;
	return (PyObject*)self;
}


PyObject* VariantToPython(pafcore::Variant* variant)
{
	PyObject* object = VariantWrapper_new(&s_VariantWrapper_Type, 0, 0);
	pafcore::Variant* var = (pafcore::Variant*)((VariantWrapper*)object)->m_var;
	var->move(*variant);
	return object;
}


pafcore::Variant* PythonToVariant(pafcore::Variant* value, PyObject* pyObject)
{
	pafcore::Variant* res = value;
	PyObject* type = PyObject_Type(pyObject); 

	if(PyObject_TypeCheck(pyObject, &s_VariantWrapper_Type))
	{
		res = (pafcore::Variant*)((VariantWrapper*)pyObject)->m_var;
	}
	else if(PyBool_Check(pyObject))
	{
		bool b = (pyObject != Py_False);
		value->assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &b);
		value->setTemporary();
	}
	else if(PyLong_Check(pyObject))
	{
		PY_LONG_LONG i = PyLong_AsLongLong(pyObject);
		value->assignPrimitive(RuntimeTypeOf<PY_LONG_LONG>::RuntimeType::GetSingleton(), &i);
		value->setTemporary();
	}
	else if(PyFloat_Check(pyObject))
	{
		double d = PyFloat_AsDouble(pyObject);
		value->assignPrimitive(RuntimeTypeOf<double>::RuntimeType::GetSingleton(), &d);
		value->setTemporary();
	}
	else if(PyUnicode_Check(pyObject))
	{
		Py_ssize_t size;
		char* s = PyUnicode_AsUTF8AndSize(pyObject, &size);
		value->assignPrimitivePtr(RuntimeTypeOf<char>::RuntimeType::GetSingleton(), (void*)s, true, ::pafcore::Variant::by_ptr);
	}
	return res;
}

pafcore::ErrorCode GetStaticField(PyObject*& pyObject, pafcore::StaticField* field)
{
	pafcore::Variant value;
	if(field->isArray())
	{
		value.assignArray(field->m_type, (void*)field->m_address, field->m_arraySize, field->m_constant, ::pafcore::Variant::by_array);
	}
	else
	{
		value.assignPtr(field->m_type, (void*)field->m_address, field->m_constant, ::pafcore::Variant::by_ref);
	}
	pyObject = VariantToPython(&value);
	return pafcore::s_ok;
}

pafcore::ErrorCode SetStaticField(pafcore::StaticField* field, PyObject* pyAttr)
{
	if(field->isArray())
	{
		return pafcore::e_field_is_an_array;
	}
	if(field->isConstant())
	{
		return pafcore::e_field_is_constant;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	if(!attr->castToObject(field->m_type, (void*)field->m_address))
	{
		return pafcore::e_invalid_field_type;
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode GetInstanceField(PyObject*& pyObject, pafcore::Variant* that, pafcore::InstanceField* field)
{
	size_t baseOffset;
	if(!static_cast<pafcore::ClassType*>(that->m_type)->getClassOffset(baseOffset, field->m_objectType))
	{
		return pafcore::e_invalid_type;
	}
	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
	pafcore::Variant value;

	if(field->isArray())
	{
		value.assignArray(field->m_type, (void*)fieldAddress, field->m_arraySize, field->m_constant, ::pafcore::Variant::by_array);
	}
	else
	{
		value.assignPtr(field->m_type, (void*)fieldAddress, field->m_constant, ::pafcore::Variant::by_ref);
	}
	pyObject = VariantToPython(&value);
	return pafcore::s_ok;
}

pafcore::ErrorCode SetInstanceField(pafcore::Variant* that, pafcore::InstanceField* field, PyObject* pyAttr)
{
	if(field->isArray())
	{
		return pafcore::e_field_is_an_array;
	}
	if(field->isConstant())
	{
		return pafcore::e_field_is_constant;
	}
	size_t baseOffset;
	if(!static_cast<pafcore::ClassType*>(that->m_type)->getClassOffset(baseOffset, field->m_objectType))
	{
		return pafcore::e_invalid_object_type;
	}
	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	if(!attr->castToObject(field->m_type, (void*)fieldAddress))
	{
		return pafcore::e_invalid_field_type;
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode GetStaticProperty(PyObject*& pyObject, pafcore::StaticProperty* property)
{
	if(0 == property->m_getter)
	{
		return pafcore::e_property_is_write_only;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(&value);
	if(pafcore::s_ok == errorCode)
	{
		pyObject = VariantToPython(&value);
	}
	return errorCode;
}

pafcore::ErrorCode GetStaticArrayPropertySize(PyObject*& pyObject, pafcore::StaticArrayProperty* property)
{
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_sizer)(&value);
	if (pafcore::s_ok == errorCode)
	{
		pyObject = VariantToPython(&value);
	}
	return errorCode;
}

pafcore::ErrorCode GetStaticArrayProperty(PyObject*& pyObject, pafcore::StaticArrayProperty* property, size_t index)
{
	if (0 == property->m_getter)
	{
		return pafcore::e_property_is_write_only;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(index, &value);
	if (pafcore::s_ok == errorCode)
	{
		pyObject = VariantToPython(&value);
	}
	return errorCode;
}

pafcore::ErrorCode SetStaticProperty(pafcore::StaticProperty* property, PyObject* pyAttr)
{
	if(0 == property->m_setter)
	{
		return pafcore::e_property_is_read_only;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	pafcore::ErrorCode errorCode = (*property->m_setter)(attr);
	return errorCode;
}

pafcore::ErrorCode SetStaticArrayPropertySize(pafcore::StaticArrayProperty* property, PyObject* pyAttr)
{
	if (0 == property->m_resizer)
	{
		return pafcore::e_array_property_is_not_dynamic;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	pafcore::ErrorCode errorCode = (*property->m_resizer)(attr);
	return errorCode;
}

pafcore::ErrorCode SetStaticArrayProperty(pafcore::StaticArrayProperty* property, size_t index, PyObject* pyAttr)
{
	if (0 == property->m_setter)
	{
		return pafcore::e_property_is_read_only;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	pafcore::ErrorCode errorCode = (*property->m_setter)(index, attr);
	return errorCode;
}

pafcore::ErrorCode MakeStaticArrayProperty(PyObject*& pyObject, pafcore::StaticArrayProperty* property)
{
	PyObject* object = StaticArrayPropertyWrapper_new(&s_StaticArrayPropertyWrapper_Type, 0, 0);
	((StaticArrayPropertyWrapper*)object)->m_property = property;
	pyObject = object;
	return pafcore::s_ok;
}

pafcore::ErrorCode GetInstanceProperty(PyObject*& pyObject, pafcore::Variant* that, pafcore::InstanceProperty* property)
{
	if(0 == property->m_getter)
	{
		return pafcore::e_property_is_write_only;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(that, &value);
	if(pafcore::s_ok == errorCode)
	{
		pyObject = VariantToPython(&value);
	}
	return errorCode;
}

pafcore::ErrorCode GetInstanceArrayPropertySize(PyObject*& pyObject, pafcore::Variant* that, pafcore::InstanceArrayProperty* property)
{
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_sizer)(that, &value);
	if (pafcore::s_ok == errorCode)
	{
		pyObject = VariantToPython(&value);
	}
	return errorCode;
}

pafcore::ErrorCode GetInstanceArrayProperty(PyObject*& pyObject, pafcore::Variant* that, pafcore::InstanceArrayProperty* property, size_t index)
{
	if (0 == property->m_getter)
	{
		return pafcore::e_property_is_write_only;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(that, index, &value);
	if (pafcore::s_ok == errorCode)
	{
		pyObject = VariantToPython(&value);
	}
	return errorCode;
}

pafcore::ErrorCode SetInstanceProperty(pafcore::Variant* that, pafcore::InstanceProperty* property, PyObject* pyAttr)
{
	if(0 == property->m_setter)
	{
		return pafcore::e_property_is_read_only;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	pafcore::ErrorCode errorCode = (*property->m_setter)(that, attr);
	return errorCode;
}


pafcore::ErrorCode SetInstanceArrayPropertySize(pafcore::Variant* that, pafcore::InstanceArrayProperty* property, PyObject* pyAttr)
{
	if (0 == property->m_resizer)
	{
		return pafcore::e_array_property_is_not_dynamic;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	pafcore::ErrorCode errorCode = (*property->m_resizer)(that, attr);
	return errorCode;
}

pafcore::ErrorCode SetInstanceArrayProperty(pafcore::Variant* that, pafcore::InstanceArrayProperty* property, size_t index, PyObject* pyAttr)
{
	if (0 == property->m_setter)
	{
		return pafcore::e_property_is_read_only;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	pafcore::ErrorCode errorCode = (*property->m_setter)(that, index, attr);
	return errorCode;
}

pafcore::ErrorCode MakeInstanceArrayProperty(PyObject*& pyObject, VariantWrapper* self, pafcore::InstanceArrayProperty* property)
{
	PyObject* object = InstanceArrayPropertyWrapper_new(&s_InstanceArrayPropertyWrapper_Type, 0, 0);
	((InstanceArrayPropertyWrapper*)object)->m_property = property;
	((InstanceArrayPropertyWrapper*)object)->m_self = self;
	Py_INCREF(self);
	pyObject = object;
	return pafcore::s_ok;
}

pafcore::ErrorCode SetArraySize(pafcore::Variant* that, PyObject* pyAttr)
{
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	if (!attr->castToPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &that->m_arraySize))
	{
		return pafcore::e_invalid_property_type;
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode MakeFunctionInvoker(PyObject*& pyObject, pafcore::FunctionInvoker invoker)
{
	PyObject* object = FunctionInvokerWrapper_new(&s_FunctionInvokerWrapper_Type, 0, 0);
	((FunctionInvokerWrapper*)object)->m_invoker = invoker;
	pyObject = object;
	return pafcore::s_ok;
}

pafcore::ErrorCode MakeInstanceMethod(PyObject*& pyObject, VariantWrapper* self, pafcore::InstanceMethod* method)
{
	PyObject* object = InstanceMethodWrapper_new(&s_InstanceMethodWrapper_Type, 0, 0);
	((InstanceMethodWrapper*)object)->m_method = method;
	((InstanceMethodWrapper*)object)->m_self = self;
	Py_INCREF(self);
	pyObject = object;
	return pafcore::s_ok;
}

pafcore::ErrorCode GetNestedType(PyObject*& pyObject, pafcore::Type* nestedType)
{
	pafcore::Variant value;
	value.assignReferencePtr(RuntimeTypeOf<pafcore::Type>::RuntimeType::GetSingleton(), nestedType, false, ::pafcore::Variant::by_ptr);
	pyObject = VariantToPython(&value);
	return pafcore::s_ok;
}


pafcore::ErrorCode GetPrimitiveOrEnum(PyObject*& pyObject, pafcore::Variant* variant)
{
	if(variant->m_type->isPrimitive())
	{
		if(variant->byValue() || variant->byRef())
		{
			pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
			switch(primitiveType->m_typeCategory)
			{
			case pafcore::float_type:
			case pafcore::double_type:
			case pafcore::long_double_type:
				{
					double value;
					primitiveType->castTo(&value, RuntimeTypeOf<double>::RuntimeType::GetSingleton(), variant->m_pointer);
					pyObject = PyFloat_FromDouble(value); 
				}
				break;
			case pafcore::bool_type:
				{
					bool value;
					primitiveType->castTo(&value, RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), variant->m_pointer);
					pyObject = value ? Py_True : Py_False;
				}
				break;
			case pafcore::unsigned_long_long_type:
				{
					unsigned PY_LONG_LONG value;
					primitiveType->castTo(&value, RuntimeTypeOf<unsigned PY_LONG_LONG>::RuntimeType::GetSingleton(), variant->m_pointer);
					pyObject = PyLong_FromUnsignedLongLong(value);
				}
				break;
			case pafcore::long_long_type:
				{
					PY_LONG_LONG value;
					primitiveType->castTo(&value, RuntimeTypeOf<PY_LONG_LONG>::RuntimeType::GetSingleton(), variant->m_pointer);
					pyObject = PyLong_FromLongLong(value);
				}
				break;
			case pafcore::unsigned_char_type:
			case pafcore::unsigned_short_type:
			case pafcore::unsigned_int_type:
			case pafcore::unsigned_long_type:
				{
					unsigned long value;
					primitiveType->castTo(&value, RuntimeTypeOf<unsigned long>::RuntimeType::GetSingleton(), variant->m_pointer);
					pyObject = PyLong_FromUnsignedLong(value);
				}
				break;
			default:
				{
					long value;
					primitiveType->castTo(&value, RuntimeTypeOf<long>::RuntimeType::GetSingleton(), variant->m_pointer);
					pyObject = PyLong_FromLong(value);
				}
			}
			return pafcore::s_ok;
		}
		else
		{
			pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
			if(pafcore::char_type == primitiveType->m_typeCategory)
			{
				pyObject = PyUnicode_FromString((const char*)variant->m_pointer);
				return pafcore::s_ok;
			}
			else if(pafcore::wchar_type == primitiveType->m_typeCategory)
			{
				pyObject = PyUnicode_FromWideChar((const wchar_t*)variant->m_pointer, -1); 
				return pafcore::s_ok;
			}
		}
	}
	else if(variant->m_type->isEnum())
	{
		if(variant->byValue() || variant->byRef())
		{
			long value;
			variant->castToPrimitive(RuntimeTypeOf<long>::RuntimeType::GetSingleton(), &value);
			pyObject = PyLong_FromLong(value);
			return pafcore::s_ok;
		}
	}
	return pafcore::e_invalid_type;
}

pafcore::ErrorCode SetPrimitiveOrEnum(pafcore::Variant* variant, PyObject* pyAttr)
{
	if (variant->isConstant())
	{
		return pafcore::e_field_is_constant;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	if (!attr->castToPrimitive(variant->m_type, variant->m_pointer))
	{
		return pafcore::e_invalid_property_type;
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode MakeProxyCreator(PyObject*& pyObject, pafcore::ClassType* classType)
{
	PyObject* object = ProxyCreatorWrapper_new(&s_ProxyCreatorWrapper_Type, 0, 0);
	((ProxyCreatorWrapper*)object)->m_classType = classType;
	pyObject = object;
	return pafcore::s_ok;
}

pafcore::ErrorCode MakeTypeCaster(PyObject*& pyObject, pafcore::Type* type)
{
	PyObject* object = TypeCasterWrapper_new(&s_TypeCasterWrapper_Type, 0, 0);
	((TypeCasterWrapper*)object)->m_type = type;
	pyObject = object;
	return pafcore::s_ok;
}

pafcore::ErrorCode Variant_GetAttr(PyObject*& pyObject, VariantWrapper* self, const char *name)
{
	pafcore::Variant* variant = (pafcore::Variant*)self->m_var;
	if(variant->isNull())
	{
		if (strcmp(name, "_isNullPtr_") == 0)//_isNullPtr_
		{
			bool isNullPtr = (0 == variant->m_pointer);
			pafcore::Variant var;
			var.assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &isNullPtr);
			pyObject = VariantToPython(&var);
			return pafcore::s_ok;
		}
		return pafcore::e_void_variant;
	}
	switch(variant->m_type->m_category)
	{
	case pafcore::name_space:
		{
			pafcore::NameSpace* ns = (pafcore::NameSpace*)variant->m_pointer;
			pafcore::Metadata* member = ns->findMember(name);
			if(0 != member)
			{
				pafcore::Variant value;
				value.assignReferencePtr(RuntimeTypeOf<pafcore::Metadata>::RuntimeType::GetSingleton(), member, false, ::pafcore::Variant::by_ptr);
				pyObject = VariantToPython(&value);
				return pafcore::s_ok;
			}
		}
		break;
	case pafcore::class_type:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)variant->m_pointer;
			pafcore::Metadata* member = type->findClassMember(name, true, true);
			if(0 != member)
			{
				pafcore::Type* memberType = member->getType();
				switch(memberType->m_category)
				{
				case pafcore::static_field:
					return GetStaticField(pyObject, static_cast<pafcore::StaticField*>(member));
				case pafcore::static_property:
					return GetStaticProperty(pyObject, static_cast<pafcore::StaticProperty*>(member));
				case pafcore::static_array_property:
					return MakeStaticArrayProperty(pyObject, static_cast<pafcore::StaticArrayProperty*>(member));
				case pafcore::static_method:
					return MakeFunctionInvoker(pyObject, static_cast<pafcore::StaticMethod*>(member)->m_invoker);
				case pafcore::enum_type:
				case pafcore::class_type:
					return GetNestedType(pyObject, static_cast<pafcore::Type*>(member));
				}
			}
		}
		break;
	case pafcore::primitive_type:
		{
			pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_pointer;
			pafcore::Metadata* member = type->findTypeMember(name);
			if(0 != member)
			{
				pafcore::Type* memberType = member->getType();
				switch(memberType->m_category)
				{
				case pafcore::static_method:
					return MakeFunctionInvoker(pyObject, static_cast<pafcore::StaticMethod*>(member)->m_invoker);
				default:
					assert(false);
				}
			}
		}
		break;
	case pafcore::enum_type:
		{
			pafcore::EnumType* et = (pafcore::EnumType*)variant->m_pointer;
			pafcore::Enumerator* enumerator = et->findEnumerator(name);
			if(0 != enumerator)
			{
				pafcore::Variant value;
				value.assignEnum(enumerator->m_type, &enumerator->m_value);
				pyObject = VariantToPython(&value);
				return pafcore::s_ok;
			}
		}
		break;
	}
	pafcore::Metadata* member;
	member = variant->m_type->findMember(name);
	if(0 != member)
	{
		pafcore::Type* memberType = member->getType();
		switch(memberType->m_category)
		{
		case pafcore::instance_field:
			return GetInstanceField(pyObject, variant, static_cast<pafcore::InstanceField*>(member));
		case pafcore::static_field:
			return GetStaticField(pyObject, static_cast<pafcore::StaticField*>(member));
		case pafcore::instance_property:
			return GetInstanceProperty(pyObject, variant, static_cast<pafcore::InstanceProperty*>(member));
		case pafcore::static_property:
			return GetStaticProperty(pyObject, static_cast<pafcore::StaticProperty*>(member));
		case pafcore::instance_array_property:
			return MakeInstanceArrayProperty(pyObject, self, static_cast<pafcore::InstanceArrayProperty*>(member));
		case pafcore::static_array_property:
			return MakeStaticArrayProperty(pyObject, static_cast<pafcore::StaticArrayProperty*>(member));
		case pafcore::instance_method:
			return MakeInstanceMethod(pyObject, self, static_cast<pafcore::InstanceMethod*>(member));
		case pafcore::static_method:
			return MakeFunctionInvoker(pyObject, static_cast<pafcore::StaticMethod*>(member)->m_invoker);
		case pafcore::enum_type:
		case pafcore::class_type:
			return GetNestedType(pyObject, static_cast<pafcore::Type*>(member));
		default:
			assert(false);
		}
	}
	else if (name[0] == '_')
	{
		switch (name[1])
		{
		case '\0'://_			
			if (variant->m_type->isPrimitive() || variant->m_type->isEnum())
			{
				return GetPrimitiveOrEnum(pyObject, variant);
			}
			break;
		case 'C':
			if (strcmp(&name[2], "astPtr_") == 0)//_CastPtr_
			{
				if (pafcore::void_type == variant->m_type->m_category ||
					pafcore::primitive_type == variant->m_type->m_category ||
					pafcore::enum_type == variant->m_type->m_category ||
					pafcore::class_type == variant->m_type->m_category)
				{
					pafcore::Type* type = (pafcore::Type*)variant->m_pointer;
					return MakeTypeCaster(pyObject, type);
				}
				else
				{
					return pafcore::e_is_not_type;
				}
			}
			break;
		case 'D':
			if (strcmp(&name[2], "erive_") == 0)//_Derive_
			{
				if (pafcore::class_type == variant->m_type->m_category)
				{
					pafcore::ClassType* classType = (pafcore::ClassType*)variant->m_pointer;
					return MakeProxyCreator(pyObject, classType);
				}
				else
				{
					return pafcore::e_is_not_class;
				}
			}
			break;
		case 'a':
			if (strcmp(&name[2], "ddress_") == 0)//_address_
			{
				pafcore::Variant address;
				address.assignPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &variant->m_pointer);
				pyObject = VariantToPython(&address);
				return pafcore::s_ok;
			}
			break;
		case 'c':
			if (strcmp(&name[2], "ount_") == 0)//_count_
			{
				pafcore::Variant count;
				count.assignPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &variant->m_arraySize);
				pyObject = VariantToPython(&count);
				return pafcore::s_ok;
			}
			break;
		case 'i':
			if (strcmp(&name[2], "sNullPtr_") == 0)//_isNullPtr_
			{
				bool isNullPtr = (0 == variant->m_pointer);
				pafcore::Variant var;
				var.assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &isNullPtr);
				pyObject = VariantToPython(&var);
				return pafcore::s_ok;
			}
			break;
		case 'n':
			if (strcmp(&name[2], "ullPtr_") == 0)//_nullPtr_
			{
				if (pafcore::void_type == variant->m_type->m_category ||
					pafcore::primitive_type == variant->m_type->m_category ||
					pafcore::enum_type == variant->m_type->m_category ||
					pafcore::class_type == variant->m_type->m_category)
				{
					pafcore::Type* type = (pafcore::Type*)variant->m_pointer;
					pafcore::Variant var;
					var.assignPtr(type, 0, false, pafcore::Variant::by_ptr);
					pyObject = VariantToPython(&var);
					return pafcore::s_ok;
				}
				else
				{
					return pafcore::e_is_not_type;
				}
			}
			break;
		case 's':
			if (strcmp(&name[2], "ize_") == 0)//_size_
			{
				pafcore::Variant size;
				size.assignPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &variant->m_type->m_size);
				pyObject = VariantToPython(&size);
				return pafcore::s_ok;
			}
			break;
		case 't':
			if (strcmp(&name[2], "ype_") == 0)//_type_
			{
				pafcore::Variant typeVar;
				typeVar.assignReferencePtr(RuntimeTypeOf<pafcore::Type>::RuntimeType::GetSingleton(), variant->m_type, false, ::pafcore::Variant::by_ptr);
				pyObject = VariantToPython(&typeVar);
				return pafcore::s_ok;
			}
			break;
		}
	}
	return pafcore::e_member_not_found;
}


pafcore::ErrorCode Variant_SetAttr(pafcore::Variant* variant, char* name, PyObject* pyAttr)
{
	switch(variant->m_type->m_category)
	{
	case pafcore::class_type:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)variant->m_pointer;
			pafcore::Metadata* member = type->findClassMember(name, true, true);
			if(0 != member)
			{
				pafcore::Type* memberType = member->getType();
				switch(memberType->m_category)
				{
				case pafcore::static_field:
					return SetStaticField(static_cast<pafcore::StaticField*>(member), pyAttr);
				case pafcore::static_property:
					return SetStaticProperty(static_cast<pafcore::StaticProperty*>(member), pyAttr);
				}
			}
		}
		break;
	}
	pafcore::Metadata* member;
	member = variant->m_type->findMember(name);
	if(0 != member)
	{
		pafcore::Type* memberType = member->getType();
		switch(memberType->m_category)
		{
		case pafcore::instance_field:
			return SetInstanceField(variant, static_cast<pafcore::InstanceField*>(member), pyAttr);
		case pafcore::static_field:
			return SetStaticField(static_cast<pafcore::StaticField*>(member), pyAttr);
		case pafcore::instance_property:
			return SetInstanceProperty(variant, static_cast<pafcore::InstanceProperty*>(member), pyAttr);
		case pafcore::static_property:
			return SetStaticProperty(static_cast<pafcore::StaticProperty*>(member), pyAttr);
		}
	}
	else if (name[0] == '_')
	{
		switch (name[1])
		{
		case '\0':
			if ((variant->m_type->isPrimitive() || variant->m_type->isEnum()) &&
				(variant->byValue() || variant->byRef()))//_
			{
				return SetPrimitiveOrEnum(variant, pyAttr);
			}
			break;
		case 'c':
			if (strcmp(&name[2], "ount_") == 0)//_count_
			{
				return SetArraySize(variant, pyAttr);
			}
			break;
		}
	}
	return pafcore::e_member_not_found;
}

pafcore::ErrorCode Variant_Subscript(PyObject*& pyObject, VariantWrapper* wrapper, size_t index)
{
	pafcore::Variant* variant = (pafcore::Variant*)wrapper->m_var;
	pafcore::Variant item;
	if(!variant->subscript(item, index))
	{
		return pafcore::e_index_out_of_range;
	}
	pyObject = VariantToPython(&item);
	return pafcore::s_ok;
}

pafcore::ErrorCode Variant_AssignSubscript(VariantWrapper* wrapper, size_t index, PyObject* pyAttr)
{
	pafcore::Variant* variant = (pafcore::Variant*)wrapper->m_var;
	pafcore::Variant item;
	if(!variant->subscript(item, index))
	{
		return pafcore::e_index_out_of_range;
	}
	pafcore::Variant value;
	pafcore::Variant* attr = PythonToVariant(&value, pyAttr);
	if(!attr->castToObject(item.m_type, item.m_pointer))
	{
		return pafcore::e_invalid_type;
	}
	return pafcore::s_ok;
}

PyObject* VariantWrapper_getattr(VariantWrapper* wrapper, char* name)
{
	PyObject* res = 0;
	pafcore::ErrorCode errorCode = Variant_GetAttr(res, wrapper, name);
	if(pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	return res;
}

int VariantWrapper_setattr(VariantWrapper* wrapper, char* name, PyObject* pyAttr)
{
	pafcore::Variant* self = (pafcore::Variant*)wrapper->m_var;
	pafcore::ErrorCode errorCode = Variant_SetAttr(self, name, pyAttr);
	if(pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 1;
	}
	return 0;
}

PyObject* VariantWrapper_call(VariantWrapper* wrapper, PyObject* parameters, PyObject*)
{
	pafcore::FunctionInvoker invoker = 0;
	pafcore::Variant* self = (pafcore::Variant*)wrapper->m_var;
	switch(self->m_type->m_category)
	{
	case pafcore::class_type:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)self->m_pointer;
			pafcore::Metadata* member = type->findClassMember("New", false, true);
			if(0 != member)
			{
				pafcore::Type* memberType = member->getType();
				if(pafcore::static_method == memberType->m_category)
				{
					invoker = static_cast<pafcore::StaticMethod*>(member)->m_invoker;
				}
			}
		}
		break;
	case pafcore::primitive_type:
		{
			pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)self->m_pointer;
			assert(strcmp(type->m_staticMethods[0].m_name, "New") == 0);
			invoker = type->m_staticMethods[0].m_invoker;
		}
		break;
	case pafcore::static_method:
		{
			pafcore::StaticMethod* method = (pafcore::StaticMethod*)self->m_pointer;
			invoker = method->m_invoker;
		}
		break;
	case pafcore::instance_method:
		{
			pafcore::InstanceMethod* method = (pafcore::InstanceMethod*)self->m_pointer;
			invoker = method->m_invoker;
		}
		break;
	}
	
	if(0 != invoker)
	{
		pafcore::Variant arguments[max_param_count];
		pafcore::Variant* args[max_param_count]; 

		Py_ssize_t numArgs = PyTuple_Size(parameters);
		for(Py_ssize_t i = 0; i < numArgs; ++i)
		{
			PyObject* pyArg = PyTuple_GetItem(parameters, i); 
			args[i] = PythonToVariant(&arguments[i], pyArg);
		}
		pafcore::Variant result;
		pafcore::ErrorCode errorCode = (*invoker)(&result, args, numArgs);
		if(pafcore::s_ok == errorCode)
		{
			PyObject* pyObject = VariantToPython(&result);
			return pyObject;
		}
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	else
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_is_not_type));
	}
	return 0;
}


Py_ssize_t VariantWrapper_length(VariantWrapper* wrapper)
{
	pafcore::ErrorCode errorCode;
	Py_ssize_t len;
	pafcore::Variant* variant = (pafcore::Variant*)wrapper->m_var;

	if (pafcore::void_object == variant->m_type->m_category && variant->byValue())
	{
		errorCode = pafcore::e_void_variant;
	}
	else
	{
		errorCode = pafcore::s_ok;
		len = variant->m_arraySize;
	}

	if (pafcore::s_ok == errorCode)
	{
		return len;
	}
	else
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 0;
	}
}

bool VariantWrapper_ParseSubscript(size_t& num, PyObject* pyObject)
{
	PyObject* type = PyObject_Type(pyObject); 

	if(PyObject_TypeCheck(pyObject, &s_VariantWrapper_Type))
	{
		pafcore::Variant* variant = (pafcore::Variant*)((VariantWrapper*)pyObject)->m_var;
		if(variant->byValue() || variant->byRef())
		{
			if(variant->castToPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &num))
			{
				return true;
			}
		}
	}
	if(PyLong_Check(pyObject))
	{
		num = PyLong_AsSize_t(pyObject);
		return true;
	}
	return false;
}

PyObject* VariantWrapper_subscript(VariantWrapper* wrapper, PyObject* subscript)
{
	size_t index;
	if(!VariantWrapper_ParseSubscript(index, subscript))
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_subscript_type));
		return 0;
	}
	PyObject* res = 0;
	pafcore::ErrorCode errorCode = Variant_Subscript(res, wrapper, index);
	if(pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	return res;
}

int VariantWrapper_assign_subscript(VariantWrapper* wrapper, PyObject* subscript, PyObject* value)
{
	size_t index;
	if(!VariantWrapper_ParseSubscript(index, subscript))
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_subscript_type));
		return 1;
	}
	pafcore::ErrorCode errorCode = Variant_AssignSubscript(wrapper, index, value);
	if(pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 1;
	}
	return 0;
}

PyObject* InstanceArrayPropertyWrapper_getattr(InstanceArrayPropertyWrapper* wrapper, char* name)
{
	PyObject* res = 0;
	pafcore::ErrorCode errorCode;
	if (strcmp("_count_", name) == 0)
	{
		errorCode = GetInstanceArrayPropertySize(res, (pafcore::Variant*)wrapper->m_self->m_var, wrapper->m_property);
	}
	else
	{
		errorCode = pafcore::e_member_not_found;
	}
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	return res;
}

int InstanceArrayPropertyWrapper_setattr(InstanceArrayPropertyWrapper* wrapper, char* name, PyObject* pyAttr)
{
	pafcore::ErrorCode errorCode;
	if (strcmp("_count_", name) == 0)
	{
		errorCode = SetInstanceArrayPropertySize((pafcore::Variant*)wrapper->m_self->m_var, wrapper->m_property, pyAttr);
	}
	else
	{
		errorCode = pafcore::e_member_not_found;
	}
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 1;
	}
	return 0;
}

Py_ssize_t InstanceArrayPropertyWrapper_length(InstanceArrayPropertyWrapper* wrapper)
{
	pafcore::ErrorCode errorCode;
	pafcore::Variant value;
	errorCode = (*wrapper->m_property->m_sizer)((pafcore::Variant*)wrapper->m_self->m_var, &value);
	if (pafcore::s_ok == errorCode)
	{
		Py_ssize_t len;
		value.castToPrimitive(RuntimeTypeOf<Py_ssize_t>::RuntimeType::GetSingleton(), &len);
		return len;
	}
	else
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 0;
	}
}

PyObject* InstanceArrayPropertyWrapper_subscript(InstanceArrayPropertyWrapper* wrapper, PyObject* subscript)
{
	size_t index;
	if (!VariantWrapper_ParseSubscript(index, subscript))
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_subscript_type));
		return 0;
	}
	PyObject* res = 0;
	pafcore::ErrorCode errorCode = GetInstanceArrayProperty(res, (pafcore::Variant*)wrapper->m_self->m_var, wrapper->m_property, index);
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	return res;
}

int InstanceArrayPropertyWrapper_assign_subscript(InstanceArrayPropertyWrapper* wrapper, PyObject* subscript, PyObject* value)
{
	size_t index;
	if (!VariantWrapper_ParseSubscript(index, subscript))
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_subscript_type));
		return 1;
	}
	pafcore::ErrorCode errorCode = SetInstanceArrayProperty((pafcore::Variant*)wrapper->m_self->m_var, wrapper->m_property, index, value);
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 1;
	}
	return 0;
}

PyObject* StaticArrayPropertyWrapper_getattr(StaticArrayPropertyWrapper* wrapper, char* name)
{
	PyObject* res = 0;
	pafcore::ErrorCode errorCode;
	if (strcmp("_count_", name) == 0)
	{
		errorCode = GetStaticArrayPropertySize(res, wrapper->m_property);
	}
	else
	{
		errorCode = pafcore::e_member_not_found;
	}
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	return res;
}

int StaticArrayPropertyWrapper_setattr(StaticArrayPropertyWrapper* wrapper, char* name, PyObject* pyAttr)
{
	pafcore::ErrorCode errorCode;
	if (strcmp("_count_", name) == 0)
	{
		errorCode = SetStaticArrayPropertySize(wrapper->m_property, pyAttr);
	}
	else
	{
		errorCode = pafcore::e_member_not_found;
	}
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 1;
	}
	return 0;
}

Py_ssize_t StaticArrayPropertyWrapper_length(StaticArrayPropertyWrapper* wrapper)
{
	pafcore::ErrorCode errorCode;
	pafcore::Variant value;
	errorCode = (*wrapper->m_property->m_sizer)(&value);
	if (pafcore::s_ok == errorCode)
	{
		Py_ssize_t len;
		value.castToPrimitive(RuntimeTypeOf<Py_ssize_t>::RuntimeType::GetSingleton(), &len);
		return len;
	}
	else
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 0;
	}
}

PyObject* StaticArrayPropertyWrapper_subscript(StaticArrayPropertyWrapper* wrapper, PyObject* subscript)
{
	size_t index;
	if (!VariantWrapper_ParseSubscript(index, subscript))
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_subscript_type));
		return 0;
	}
	PyObject* res = 0;
	pafcore::ErrorCode errorCode = GetStaticArrayProperty(res, wrapper->m_property, index);
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	return res;
}

int StaticArrayPropertyWrapper_assign_subscript(StaticArrayPropertyWrapper* wrapper, PyObject* subscript, PyObject* value)
{
	size_t index;
	if (!VariantWrapper_ParseSubscript(index, subscript))
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_subscript_type));
		return 1;
	}
	pafcore::ErrorCode errorCode = SetStaticArrayProperty(wrapper->m_property, index, value);
	if (pafcore::s_ok != errorCode)
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
		return 1;
	}
	return 0;
}

PyObject* InstanceMethodWrapper_call(InstanceMethodWrapper* wrapper, PyObject* parameters, PyObject*)
{
	pafcore::InstanceMethod* method = wrapper->m_method;
	VariantWrapper* self = wrapper->m_self;

	pafcore::Variant arguments[max_param_count];
	pafcore::Variant* args[max_param_count + 1]; 

	args[0] = (pafcore::Variant*)self->m_var;
	Py_ssize_t numArgs = PyTuple_Size(parameters);
	for(Py_ssize_t i = 0; i < numArgs; ++i)
	{
		PyObject* pyArg = PyTuple_GetItem(parameters, i); 
		args[i+1] = PythonToVariant(&arguments[i], pyArg);
	}
	pafcore::Variant result;
	pafcore::ErrorCode errorCode = (*method->m_invoker)(&result, args, numArgs + 1);
	if(pafcore::s_ok == errorCode)
	{
		PyObject* pyObject = VariantToPython(&result);
		return pyObject;
	}
	PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	return 0;
}

PyObject* FunctionInvokerWrapper_call(FunctionInvokerWrapper* wrapper, PyObject* parameters, PyObject*)
{
	pafcore::FunctionInvoker invoker = wrapper->m_invoker;

	pafcore::Variant arguments[max_param_count];
	pafcore::Variant* args[max_param_count]; 

	Py_ssize_t numArgs = PyTuple_Size(parameters);
	for(Py_ssize_t i = 0; i < numArgs; ++i)
	{
		PyObject* pyArg = PyTuple_GetItem(parameters, i); 
		args[i] = PythonToVariant(&arguments[i], pyArg);
	}
	pafcore::Variant result;
	pafcore::ErrorCode errorCode = (*invoker)(&result, args, numArgs);
	if(pafcore::s_ok == errorCode)
	{
		PyObject* pyObject = VariantToPython(&result);
		return pyObject;
	}
	PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	return 0;
}

PyObject* ProxyCreatorWrapper_call(ProxyCreatorWrapper* wrapper, PyObject* parameters, PyObject*)
{
	pafcore::ClassType* classType = wrapper->m_classType;
	Py_ssize_t numArgs = PyTuple_Size(parameters);
	PyObject* pyArg = PyTuple_GetItem(parameters, 0); 
	if(pyArg)
	{
		PythonSubclassInvoker* subclassInvoker = paf_new PythonSubclassInvoker(pyArg);
		void* implementor = classType->createSubclassProxy(subclassInvoker);
		pafcore::Variant impVar;
		if(classType->isValue())
		{
			impVar.assignValuePtr(classType, implementor, false, ::pafcore::Variant::by_new_ptr);
		}
		else
		{
			impVar.assignReferencePtr(classType, implementor, false, ::pafcore::Variant::by_new_ptr);
		}
		return VariantToPython(&impVar);
	}
	PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_arg_type_1));
	return 0;
}

PyObject* TypeCasterWrapper_call(TypeCasterWrapper* wrapper, PyObject* parameters, PyObject*)
{
	pafcore::Type* type = wrapper->m_type;
	Py_ssize_t numArgs = PyTuple_Size(parameters);
	PyObject* pyArg = PyTuple_GetItem(parameters, 0);
	if (pyArg)
	{
		pafcore::Variant value;
		pafcore::Variant* arg = PythonToVariant(&value, pyArg);
		pafcore::Variant dstPtr;
		arg->reinterpretCastToPtr(dstPtr, type);
		return VariantToPython(&dstPtr);
	}
	PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_invalid_arg_type_1));
	return 0;
}



PyObject* VariantWrapper_unaryOperator(PyObject* pyObject, const char* op)
{
	pafcore::Variant arguments[1];
	pafcore::Variant* args[1];
	args[0] = PythonToVariant(&arguments[0], pyObject);

	pafcore::InstanceMethod* method;

	switch (args[0]->m_type->m_category)
	{
	case pafcore::primitive_object:
		{
			pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)args[0]->m_type;
			method = type->findInstanceMethod(op);
		}
		break;
	case pafcore::value_object:
	case pafcore::reference_object:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)args[0]->m_type;
			method = type->findInstanceMethod(op, true);
		}
		break;
	default:
		method = 0;
	};
	if (0 != method)
	{
		pafcore::Variant result;
		pafcore::ErrorCode errorCode = (*method->m_invoker)(&result, args, 1);
		if (pafcore::s_ok == errorCode)
		{
			PyObject* pyObject = VariantToPython(&result);
			return pyObject;
		}
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	else
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_member_not_found));
	}
	return 0;
}

PyObject* VariantWrapper_binaryOperator(PyObject* pyObject1, PyObject* pyObject2, const char* op)
{
	pafcore::Variant arguments[2];
	pafcore::Variant* args[2];
	args[0] = PythonToVariant(&arguments[0], pyObject1);
	args[1] = PythonToVariant(&arguments[1], pyObject2);

	pafcore::InstanceMethod* method;

	switch (args[0]->m_type->m_category)
	{
	case pafcore::primitive_object:
		{
			pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)args[0]->m_type;
			method = type->findInstanceMethod(op);
		}
		break;
	case pafcore::value_object:
	case pafcore::reference_object:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)args[0]->m_type;
			method = type->findInstanceMethod(op, true);
		}
		break;
	default:
		method = 0;
	};
	if (0 != method)
	{
		pafcore::Variant result;
		pafcore::ErrorCode errorCode = (*method->m_invoker)(&result, args, 2);
		if (pafcore::s_ok == errorCode)
		{
			PyObject* pyObject = VariantToPython(&result);
			return pyObject;
		}
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
	}
	else
	{
		PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(pafcore::e_member_not_found));
	}
	return 0;
}

//PyObject* VariantWrapper_compoundAssignmentOperator(PyObject* pyObject1, PyObject* pyObject2, pafcore::FunctionInvoker invoker)
//{
//	pafcore::Variant arguments[2];
//	pafcore::Variant* args[2];
//	args[0] = PythonToVariant(&arguments[0], pyObject1);
//	args[1] = PythonToVariant(&arguments[1], pyObject2);
//	pafcore::Variant result;
//	pafcore::ErrorCode errorCode = (*invoker)(&result, args, 2);
//	if(pafcore::s_ok == errorCode)
//	{
//		Py_INCREF(pyObject1);
//		return pyObject1;
//	}
//	PyErr_SetString(PyExc_RuntimeError, ErrorCodeToString(errorCode));
//	return 0;
//}

PyObject* VariantWrapper_add(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_add");
}

PyObject* VariantWrapper_subtract(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_subtract");
}

PyObject* VariantWrapper_multiply(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_multiply");
}

PyObject* VariantWrapper_mod(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_mod");
}

PyObject* VariantWrapper_negative(PyObject* pyObject)
{
	return VariantWrapper_unaryOperator(pyObject, "op_negate");
}

PyObject* VariantWrapper_positive(PyObject* pyObject)
{
	return VariantWrapper_unaryOperator(pyObject, "op_plus");
}

PyObject* VariantWrapper_invert(PyObject* pyObject)
{
	return VariantWrapper_unaryOperator(pyObject, "op_bitwiseNot");
}

PyObject* VariantWrapper_lshift(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_leftShift");
}

PyObject* VariantWrapper_rshift(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_rightShift");
}

PyObject* VariantWrapper_and(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_bitwiseAnd");
}

PyObject* VariantWrapper_xor(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_bitwiseXor");
}

PyObject* VariantWrapper_or(PyObject* pyObject1, PyObject* pyObject2)
{
	return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_bitwiseOr");
}
//
//PyObject* VariantWrapper_inplace_add(PyObject* pyObject1, PyObject* pyObject2)
//{
//	return VariantWrapper_compoundAssignmentOperator(pyObject1, pyObject2, pafcore::PrimitiveType::Primitive_op_addAssign);
//}

static PyNumberMethods s_VariantWrapper_Operators = 
{
	VariantWrapper_add,//binaryfunc nb_add;
	VariantWrapper_subtract,//binaryfunc nb_subtract;
	VariantWrapper_multiply,//binaryfunc nb_multiply;
	VariantWrapper_mod,//binaryfunc nb_remainder;
	0,//binaryfunc nb_divmod;
	0,//ternaryfunc nb_power;
	VariantWrapper_negative,//unaryfunc nb_negative;
	VariantWrapper_positive,//unaryfunc nb_positive;
	0,//unaryfunc nb_absolute;
	0,//inquiry nb_bool;
	VariantWrapper_invert,//unaryfunc nb_invert;
	VariantWrapper_lshift,//binaryfunc nb_lshift;
	VariantWrapper_rshift,//binaryfunc nb_rshift;
	VariantWrapper_and,//binaryfunc nb_and;
	VariantWrapper_xor,//binaryfunc nb_xor;
	VariantWrapper_or,//binaryfunc nb_or;
	0,//unaryfunc nb_int;
	0,//void *nb_reserved;  /* the slot formerly known as nb_long */
	0,//unaryfunc nb_float;
	0,//binaryfunc nb_inplace_add;
	0,//binaryfunc nb_inplace_subtract;
	0,//binaryfunc nb_inplace_multiply;
	0,//binaryfunc nb_inplace_remainder;
	0,//ternaryfunc nb_inplace_power;
	0,//binaryfunc nb_inplace_lshift;
	0,//binaryfunc nb_inplace_rshift;
	0,//binaryfunc nb_inplace_and;
	0,//binaryfunc nb_inplace_xor;
	0,//binaryfunc nb_inplace_or;
	0,//binaryfunc nb_floor_divide;
	0,//binaryfunc nb_true_divide;
	0,//binaryfunc nb_inplace_floor_divide;
	0,//binaryfunc nb_inplace_true_divide;
	0,//unaryfunc nb_index;
	0,//binaryfunc nb_matrix_multiply;
	0,//binaryfunc nb_inplace_matrix_multiply;
};

PyObject* VariantWrapper_richcmp(PyObject* pyObject1, PyObject* pyObject2, int op)
{
	switch(op)
	{
	case Py_LT:
		return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_less");
	case Py_LE:
		return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_lessEqual");
	case Py_EQ:
		return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_equal");
	case Py_NE:
		return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_notEqual");
	case Py_GT:
		return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_greater");
	case Py_GE:
		return VariantWrapper_binaryOperator(pyObject1, pyObject2, "op_greaterEqual");
	}
	return 0;
}

static PyMappingMethods s_VariantWrapper_Array_Methods =
{
	(lenfunc)VariantWrapper_length,
	(binaryfunc)VariantWrapper_subscript,
	(objobjargproc)VariantWrapper_assign_subscript
};

static PyMappingMethods s_InstanceArrayPropertyWrapper_Array_Methods =
{
	(lenfunc)InstanceArrayPropertyWrapper_length,
	(binaryfunc)InstanceArrayPropertyWrapper_subscript,
	(objobjargproc)InstanceArrayPropertyWrapper_assign_subscript
};

static PyMappingMethods s_StaticArrayPropertyWrapper_Array_Methods =
{
	(lenfunc)StaticArrayPropertyWrapper_length,
	(binaryfunc)StaticArrayPropertyWrapper_subscript,
	(objobjargproc)StaticArrayPropertyWrapper_assign_subscript
};


static PyModuleDef s_PafPythonModule = 
{
	PyModuleDef_HEAD_INIT,
	"PafPython",
	0,
	-1,
};

PyMODINIT_FUNC PyInit_PafPython_()
{
	PyObject* module;

	s_VariantWrapper_Type.tp_dealloc = (destructor)VariantWrapper_dealloc;
	s_VariantWrapper_Type.tp_getattr = (getattrfunc)VariantWrapper_getattr;
	s_VariantWrapper_Type.tp_setattr = (setattrfunc)VariantWrapper_setattr;
	s_VariantWrapper_Type.tp_call = (ternaryfunc)VariantWrapper_call;
	s_VariantWrapper_Type.tp_flags = Py_TPFLAGS_DEFAULT;
	s_VariantWrapper_Type.tp_new = VariantWrapper_new;
	s_VariantWrapper_Type.tp_as_number = &s_VariantWrapper_Operators;
	s_VariantWrapper_Type.tp_as_mapping = &s_VariantWrapper_Array_Methods;
	s_VariantWrapper_Type.tp_richcompare = &VariantWrapper_richcmp;

	if (PyType_Ready(&s_VariantWrapper_Type) < 0)
	{
		return NULL;
	}

	s_InstanceArrayPropertyWrapper_Type.tp_dealloc = (destructor)InstanceArrayPropertyWrapper_dealloc;
	s_InstanceArrayPropertyWrapper_Type.tp_getattr = (getattrfunc)InstanceArrayPropertyWrapper_getattr;
	s_InstanceArrayPropertyWrapper_Type.tp_setattr = (setattrfunc)InstanceArrayPropertyWrapper_setattr;
	s_InstanceArrayPropertyWrapper_Type.tp_flags = Py_TPFLAGS_DEFAULT;
	s_InstanceArrayPropertyWrapper_Type.tp_new = InstanceArrayPropertyWrapper_new;
	s_InstanceArrayPropertyWrapper_Type.tp_as_mapping = &s_InstanceArrayPropertyWrapper_Array_Methods;
	if (PyType_Ready(&s_InstanceArrayPropertyWrapper_Type) < 0)
	{
		return NULL;
	}

	s_StaticArrayPropertyWrapper_Type.tp_getattr = (getattrfunc)StaticArrayPropertyWrapper_getattr;
	s_StaticArrayPropertyWrapper_Type.tp_setattr = (setattrfunc)StaticArrayPropertyWrapper_setattr;
	s_StaticArrayPropertyWrapper_Type.tp_flags = Py_TPFLAGS_DEFAULT;
	s_StaticArrayPropertyWrapper_Type.tp_new = StaticArrayPropertyWrapper_new;
	s_StaticArrayPropertyWrapper_Type.tp_as_mapping = &s_StaticArrayPropertyWrapper_Array_Methods;
	if (PyType_Ready(&s_StaticArrayPropertyWrapper_Type) < 0)
	{
		return NULL;
	}

	s_InstanceMethodWrapper_Type.tp_dealloc = (destructor)InstanceMethodWrapper_dealloc;
	s_InstanceMethodWrapper_Type.tp_call = (ternaryfunc)InstanceMethodWrapper_call;
	s_InstanceMethodWrapper_Type.tp_flags = Py_TPFLAGS_DEFAULT;
	s_InstanceMethodWrapper_Type.tp_new = InstanceMethodWrapper_new;
	if (PyType_Ready(&s_InstanceMethodWrapper_Type) < 0)
	{
		return NULL;
	}

	s_FunctionInvokerWrapper_Type.tp_call = (ternaryfunc)FunctionInvokerWrapper_call;
	s_FunctionInvokerWrapper_Type.tp_flags = Py_TPFLAGS_DEFAULT;
	s_FunctionInvokerWrapper_Type.tp_new = FunctionInvokerWrapper_new;
	if (PyType_Ready(&s_FunctionInvokerWrapper_Type) < 0)
	{
		return NULL;
	}

	s_ProxyCreatorWrapper_Type.tp_flags = Py_TPFLAGS_DEFAULT;
	s_ProxyCreatorWrapper_Type.tp_new = ProxyCreatorWrapper_new;
	s_ProxyCreatorWrapper_Type.tp_call = (ternaryfunc)ProxyCreatorWrapper_call;
	if (PyType_Ready(&s_ProxyCreatorWrapper_Type) < 0)
	{
		return NULL;
	}

	s_TypeCasterWrapper_Type.tp_flags = Py_TPFLAGS_DEFAULT;
	s_TypeCasterWrapper_Type.tp_new = TypeCasterWrapper_new;
	s_TypeCasterWrapper_Type.tp_call = (ternaryfunc)TypeCasterWrapper_call;
	if (PyType_Ready(&s_TypeCasterWrapper_Type) < 0)
	{
		return NULL;
	}

	module = PyModule_Create(&s_PafPythonModule);
	if (module == NULL)
	{
		return NULL;
	}
	Py_INCREF(&s_VariantWrapper_Type);
	PyObject* root = VariantWrapper_new(&s_VariantWrapper_Type, 0, 0);
	pafcore::Variant* var = (pafcore::Variant*)((VariantWrapper*)root)->m_var;
	var->assignReferencePtr(RuntimeTypeOf<pafcore::NameSpace>::RuntimeType::GetSingleton(), pafcore::NameSpace::GetGlobalNameSpace(), false, ::pafcore::Variant::by_ptr);
	PyModule_AddObject(module, "paf", root);
	return module;
}


END_PAFPYTHON

PyMODINIT_FUNC PyInit_PafPython()
{
	return pafpython::PyInit_PafPython_();
}
