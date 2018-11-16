#include "XmlSerializer.h"
#include "XmlSerializer.mh"
#include "XmlSerializer.ic"
#include "XmlSerializer.mc"
#include "../pafcore/Reference.h"
#include "../pafcore/ClassType.h"
#include "../pafcore/Reflection.h"
#include "../pafcore/InstanceField.mh"
#include "../pafcore/Typedef.mh"
#include "../pafcore/String.mh"
#include "../pafcore/Iterator.mh"
#include "../../../../thirdparty/rapidxml-1.13/rapidxml.hpp"
#include "../../../../thirdparty/rapidxml-1.13/rapidxml_print.hpp"
#include "Base64.h"
#include <vector>
#include <iterator>

BEGIN_PAFSTD

static xml_node* VariantToXml(const char* name, pafcore::Variant* variant, rapidxml::xml_document<char>& doc, bool xmlCdata);

static bool IsXmlCdata(pafcore::Metadata* metaData)
{
	const char* str = metaData->_getAttributeContentByName_("xml_cdata");
	if (str)
	{
		int i = atoi(str);
		return i != 0;
	}
	else
	{
		return false;
	}
}

static xml_node* PrimitiveToXml(const char* name, pafcore::Variant* variant, rapidxml::xml_document<char>& doc)
{
	rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
	pafcore::String str = pafcore::Reflection::PrimitiveToString(*variant);
	node->name(doc.allocate_string(name));
	node->value(doc.allocate_string(str.c_str()));
	return node;
}

static xml_node* RawStringToXml(const char* name, pafcore::Variant* variant, rapidxml::xml_document<char>& doc, bool xmlCdata)
{
	const char* str = ((string_t*)variant->m_pointer)->c_str();
	rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
	node->name(doc.allocate_string(name));
	if (xmlCdata)
	{
		rapidxml::xml_node<char>* contentNode = doc.allocate_node(rapidxml::node_cdata);
		contentNode->value(doc.allocate_string(str));
		node->append_node(contentNode);
	}
	else
	{
		node->value(doc.allocate_string(str));
	}
	return node;
}

static xml_node* EnumToXml(const char* name, pafcore::Variant* variant, rapidxml::xml_document<char>& doc)
{
	rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
	pafcore::String str = pafcore::Reflection::EnumToString(*variant);
	node->name(doc.allocate_string(name));
	node->value(doc.allocate_string(str.c_str()));
	return node;
}

static xml_node* StringToXml(const char* name, pafcore::Variant* variant, rapidxml::xml_document<char>& doc, bool xmlCdata)
{
	pafcore::String* str;
	if (!variant->castToValuePtr(RuntimeTypeOf<::pafcore::String>::RuntimeType::GetSingleton(), (void**)&str))
	{
		return 0;
	}
	rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
	node->name(doc.allocate_string(name));
	if (xmlCdata)
	{
		rapidxml::xml_node<char>* contentNode = doc.allocate_node(rapidxml::node_cdata);
		contentNode->value(doc.allocate_string(str->c_str()));
		node->append_node(contentNode);
	}
	else
	{
		node->value(doc.allocate_string(str->c_str()));
	}
	return node;
}

static xml_node* BufferToXml(const char* name, pafcore::Variant* variant, rapidxml::xml_document<char>& doc)
{
	pafcore::Buffer* buffer = (pafcore::Buffer*)variant->m_pointer;
	if (0 == buffer || 0 == buffer->size || 0 == buffer->pointer)
	{
		return 0;
	}
	std::vector<char> code(Base64::EncodeBufferLength(buffer->size));
	size_t base64Len = Base64::Encode(&code[0], buffer->pointer, buffer->size);
	rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
	node->name(doc.allocate_string(name));
	node->value(doc.allocate_string(&code[0], base64Len));
	return node;
}

static xml_node* InstancePropertyToXml(const char* name, pafcore::Variant* that, pafcore::InstanceProperty* instanceProperty, rapidxml::xml_document<char>& doc, bool xmlCdata)
{
	if (instanceProperty->get_isArray())
	{
		size_t propertySize;
		if (pafcore::s_ok == pafcore::Reflection::GetArrayInstancePropertySize(propertySize, that, instanceProperty))
		{
			char buf[64];
			rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
			node->name(doc.allocate_string(name));
			rapidxml::xml_attribute<char>* attribute = doc.allocate_attribute();
			attribute->name("arraySize");
			sprintf_s(buf, "%u", (uint32_t)propertySize);
			attribute->value(doc.allocate_string(buf));
			node->append_attribute(attribute);

			for (size_t i = 0; i < propertySize; ++i)
			{
				pafcore::Variant subProperty;
				if (pafcore::s_ok == pafcore::Reflection::GetArrayInstanceProperty(subProperty, that, instanceProperty, i))
				{
					sprintf_s(buf, "_%u", (uint32_t)i);
					xml_node* childNode = VariantToXml(buf, &subProperty, doc, xmlCdata);
					if (childNode)
					{
						node->append_node(childNode);
					}
				}
			}
			return node;
		}
	}
	else if (instanceProperty->get_isList())
	{
		char buf[64];
		rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
		node->name(doc.allocate_string(name));

		::pafcore::Variant varIterator;
		if (pafcore::s_ok == pafcore::Reflection::ListInstanceProperty_GetIterator(&varIterator, that, instanceProperty))
		{
			::pafcore::Iterator* iterator;
			varIterator.castToReferencePtr(RuntimeTypeOf<::pafcore::Iterator>::RuntimeType::GetSingleton(), (void**)&iterator);
			uint32_t propertySize = 0;
			while (!iterator->isEnd())
			{
				pafcore::Variant value;
				pafcore::Reflection::ListInstanceProperty_GetValue(value, that, instanceProperty, iterator);
				sprintf_s(buf, "_%u", (uint32_t)propertySize);
				xml_node* valueNode = VariantToXml(buf, &value, doc, xmlCdata);
				if (valueNode)
				{
					node->append_node(valueNode);
				}
				iterator->moveNext();
				++propertySize;
			}
			rapidxml::xml_attribute<char>* attribute = doc.allocate_attribute();
			attribute->name("listSize");
			sprintf_s(buf, "%u", (uint32_t)propertySize);
			attribute->value(doc.allocate_string(buf));
			node->append_attribute(attribute);
			return node;
		}
	}
	else if (instanceProperty->get_isMap())
	{
		char buf[64];
		rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
		node->name(doc.allocate_string(name));

		::pafcore::Variant varIterator;
		if (pafcore::s_ok == pafcore::Reflection::GetMapInstanceIterator(&varIterator, that, instanceProperty))
		{
			::pafcore::Iterator* iterator;
			varIterator.castToReferencePtr(RuntimeTypeOf<::pafcore::Iterator>::RuntimeType::GetSingleton(), (void**)&iterator);
			uint32_t propertySize = 0;
			while (!iterator->isEnd())
			{
				pafcore::Variant key;
				pafcore::Variant value;
				pafcore::Reflection::GetMapInstanceKey(key, that, instanceProperty, iterator);
				pafcore::Reflection::GetMapInstanceValue(value, that, instanceProperty, iterator);
				sprintf_s(buf, "k_%u", (uint32_t)propertySize);
				xml_node* keyNode = VariantToXml(buf, &key, doc, xmlCdata);
				if (keyNode)
				{
					node->append_node(keyNode);
				}
				sprintf_s(buf, "v_%u", (uint32_t)propertySize);
				xml_node* valueNode = VariantToXml(buf, &value, doc, xmlCdata);
				if (valueNode)
				{
					node->append_node(valueNode);
				}
				iterator->moveNext();
				++propertySize;
			}
			rapidxml::xml_attribute<char>* attribute = doc.allocate_attribute();
			attribute->name("mapSize");
			sprintf_s(buf, "%u", (uint32_t)propertySize);
			attribute->value(doc.allocate_string(buf));
			node->append_attribute(attribute);
			return node;
		}
	}
	else
	{
		PAF_ASSERT(instanceProperty->get_isSimple());
		pafcore::Variant propertyValue;
		if (pafcore::s_ok == pafcore::Reflection::GetInstanceProperty(propertyValue, that, instanceProperty))
		{
			return VariantToXml(instanceProperty->get__name_(), &propertyValue, doc, xmlCdata);
		}
	}
	return 0;
}

static xml_node* InstanceFieldToXml(pafcore::Variant* that, pafcore::InstanceField* instanceField, rapidxml::xml_document<char>& doc)
{
	pafcore::Variant fieldValue;
	if (pafcore::s_ok == pafcore::Reflection::GetInstanceFieldRef(fieldValue, that, instanceField))
	{
		bool xmlCdata = IsXmlCdata(instanceField);	
		if (instanceField->isArray())
		{
			char buf[64];
			rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
			node->name(doc.allocate_string(instanceField->get__name_()));
			rapidxml::xml_attribute<char>* attribute = doc.allocate_attribute();
			attribute->name("arraySize");
			sprintf_s(buf, "%u", (uint32_t)fieldValue.m_arraySize);
			attribute->value(doc.allocate_string(buf));
			node->append_attribute(attribute);
			for (size_t i = 0; i < fieldValue.m_arraySize; ++i)
			{
				pafcore::Variant subField;
				if (fieldValue.subscript(subField, i))
				{
					sprintf_s(buf, "_%u", (uint32_t)i);
					xml_node* childNode = VariantToXml(buf, &subField, doc, xmlCdata);
					if (childNode)
					{
						node->append_node(childNode);
					}
				}
			}
			return node;

		}
		else
		{
			return VariantToXml(instanceField->get__name_(), &fieldValue, doc, xmlCdata);
		}
	}
	return 0;
}

static xml_node* ClassToXml(const char* name, pafcore::Variant* that, rapidxml::xml_document<char>& doc)
{
	if (0 == that->m_pointer)
	{
		return 0;
	}
	rapidxml::xml_node<char>* node = doc.allocate_node(rapidxml::node_element);
	node->name(doc.allocate_string(name));
	pafcore::ClassType* classType = static_cast<pafcore::ClassType*>(that->m_type);
	if (classType->isReference())
	{
		pafcore::Reference* reference = (pafcore::Reference*)that->m_pointer;
		pafcore::ClassType* finalClassType = reference->getType();
		pafcore::String className = pafcore::Reflection::GetTypeFullName(finalClassType);
		rapidxml::xml_attribute<char>* attribute = doc.allocate_attribute();
		attribute->name("type");
		attribute->value(doc.allocate_string(className.c_str()));
		node->append_attribute(attribute);
	}
	size_t fieldCount = classType->_getInstanceFieldCount_(true);
	for (size_t i = 0; i < fieldCount; ++i)
	{
		pafcore::InstanceField* instanceField = classType->_getInstanceField_(i, true);
		xml_node* childNode = InstanceFieldToXml(that, instanceField, doc);
		if (childNode)
		{
			node->append_node(childNode);
		}
	}

	size_t propertyCount = classType->_getInstancePropertyCount_(true);
	for (size_t i = 0; i < propertyCount; ++i)
	{
		pafcore::InstanceProperty* instanceProperty = classType->_getInstanceProperty_(i, true);
		bool xmlCdata = IsXmlCdata(instanceProperty);
		xml_node* childNode = InstancePropertyToXml(instanceProperty->get__name_(), that, instanceProperty, doc, xmlCdata);
		if (childNode)
		{
			node->append_node(childNode);
		}
	}

	pafcore::InstanceMethod* dynamicInstanceField = classType->findInstanceMethod("dynamicInstanceField", false);
	pafcore::InstanceMethod* dynamicInstanceFieldCount = classType->findInstanceMethod("dynamicInstanceFieldCount", false);
	if (dynamicInstanceField && dynamicInstanceFieldCount)
	{
		pafcore::Variant countVar;
		if (pafcore::s_ok == pafcore::Reflection::CallInstanceMethod(countVar, that, dynamicInstanceFieldCount, 0, 0))
		{
			uint32_t count;
			countVar.castToPrimitive(RuntimeTypeOf<uint32_t>::RuntimeType::GetSingleton(), &count);
			for (uint32_t i = 0; i < count; ++i)
			{
				pafcore::Variant instanceFieldVar;
				pafcore::Variant indexVar;
				indexVar.assignPrimitive(RuntimeTypeOf<uint32_t>::RuntimeType::GetSingleton(), &i);
				if (pafcore::s_ok == pafcore::Reflection::CallInstanceMethod(instanceFieldVar, that, dynamicInstanceField, &indexVar, 1) 
					&& RuntimeTypeOf<::pafcore::InstanceField>::RuntimeType::GetSingleton() == instanceFieldVar.m_type)
				{
					pafcore::InstanceField* instanceField = reinterpret_cast<pafcore::InstanceField*>(instanceFieldVar.m_pointer);
					xml_node* childNode = InstanceFieldToXml(that, instanceField, doc);
					if (childNode)
					{
						node->append_node(childNode);
					}
				}
			}
		}
	}

	if (classType->isReference())
	{
		pafcore::Reference* reference = (pafcore::Reference*)that->m_pointer;
		uint32_t count = reference->dynamicInstancePropertyCount();
		for (uint32_t i = 0; i < count; ++i)
		{
			pafcore::InstanceProperty* instanceProperty = reference->dynamicInstanceProperty(i);
			bool xmlCdata = IsXmlCdata(instanceProperty);
			xml_node* childNode = InstancePropertyToXml(instanceProperty->get__name_(), that, instanceProperty, doc, xmlCdata);
			if (childNode)
			{
				node->append_node(childNode);
			}
		}
	}

	return node;
}

static xml_node* VariantToXml(const char* name, pafcore::Variant* variant, rapidxml::xml_document<char>& doc, bool xmlCdata)
{
	if (variant->m_type->isPrimitive())
	{
		pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
		if (primitiveType->isString())
		{
			return RawStringToXml(name, variant, doc, xmlCdata);
		}
		else
		{
			return PrimitiveToXml(name, variant, doc);
		}
	}
	else if (variant->m_type->isEnum())
	{
		return EnumToXml(name, variant, doc);
	}
	else if (variant->m_type->isClass())
	{
		if (RuntimeTypeOf<::pafcore::Buffer>::RuntimeType::GetSingleton() == variant->m_type)
		{
			return BufferToXml(name, variant, doc);
		}
		else if (RuntimeTypeOf<::pafcore::String>::RuntimeType::GetSingleton() == variant->m_type)
		{
			return StringToXml(name, variant, doc, xmlCdata);
		}
		else
		{
			return ClassToXml(name, variant, doc);
		}
	}
	return 0;
}

static void XmlToVariant(pafcore::Variant& variant, xml_node* node, bool xmlCdata);

static void XmlToPrimitive(pafcore::Variant& variant, xml_node* node)
{
	pafcore::Type* type = variant.m_type;
	PAF_ASSERT(type->isPrimitive());
	pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(type);
	pafcore::Variant tmp;
	pafcore::Reflection::StringToPrimitive(tmp, primitiveType, node->value());
	tmp.castToPrimitive(primitiveType, variant.m_pointer);
}

static void XmlToRawString(pafcore::Variant& variant, xml_node* node, bool xmlCdata)
{
	if (xmlCdata)
	{
		node = node->first_node();
		if (0 == node)
		{
			return;
		}
	}
	XmlToPrimitive(variant, node);
}

static void XmlToEnum(pafcore::Variant& variant, xml_node* node)
{
	pafcore::Type* type = variant.m_type;
	PAF_ASSERT(type->isEnum());
	pafcore::EnumType* enumType = static_cast<pafcore::EnumType*>(type);
	pafcore::Variant tmp;
	pafcore::Reflection::StringToEnum(tmp, enumType, node->value());
	tmp.castToEnum(enumType, variant.m_pointer);
}

static void XmlToString(pafcore::Variant& variant, xml_node* node, bool xmlCdata)
{
	if (xmlCdata)
	{
		node = node->first_node();
		if (0 == node)
		{
			return;
		}
	}
	pafcore::String* str;
	if (variant.castToValuePtr(RuntimeTypeOf<::pafcore::String>::RuntimeType::GetSingleton(), (void**)&str))
	{
		str->assign(node->value());
	}
}

static void XmlToInstanceField(pafcore::Variant& that, pafcore::InstanceField* instanceField, xml_node* node)
{
	xml_node* childNode = node->first_node(instanceField->get__name_());
	if (childNode)
	{
		pafcore::Variant fieldValue;
		if (pafcore::s_ok == pafcore::Reflection::GetInstanceFieldRef(fieldValue, &that, instanceField))
		{
			bool xmlCdata = IsXmlCdata(instanceField);
			if (instanceField->isArray())
			{
				for (size_t i = 0; i < fieldValue.m_arraySize; ++i)
				{
					char buf[64];
					sprintf_s(buf, "_%u", (uint32_t)i);
					xml_node* subFieldNode = childNode->first_node(buf);
					if (subFieldNode)
					{
						pafcore::Variant subField;
						if (fieldValue.subscript(subField, i))
						{
							XmlToVariant(subField, subFieldNode, xmlCdata);
						}
					}
				}
			}
			else
			{
				XmlToVariant(fieldValue, childNode, xmlCdata);
			}
		}
	}
}

static void XmlToInstanceProperty(pafcore::Variant& that, pafcore::InstanceProperty* instanceProperty, xml_node* node)
{
	xml_node* childNode = node->first_node(instanceProperty->get__name_());
	if (childNode)
	{
		bool xmlCdata = IsXmlCdata(instanceProperty);
		if (instanceProperty->get_isArray())
		{
			xml_attribute* arraySizeAttr = childNode->first_attribute("arraySize");
			if (0 == arraySizeAttr)
			{
				return;
			}
			size_t propertySize = strtoul(arraySizeAttr->value(), 0, 0);
			pafcore::Reflection::ResizeArrayInstanceProperty(&that, instanceProperty, propertySize);
			if (instanceProperty->get_hasSetter())
			{
				for (size_t i = 0; i < propertySize; ++i)
				{
					char buf[64];
					sprintf_s(buf, "_%u", (uint32_t)i);
					xml_node* itemNode = childNode->first_node(buf);
					if (itemNode)
					{
						pafcore::Variant propertyValue;
						pafcore::Type* type = instanceProperty->get_setterType();
						if (type->isReference())
						{
							xml_attribute* typeAttr = itemNode->first_attribute("type");
							if (typeAttr)
							{
								type = pafcore::Reflection::GetTypeFromFullName(typeAttr->value());
							}
						}
						pafcore::Reflection::NewObject(propertyValue, type);
						XmlToVariant(propertyValue, itemNode, xmlCdata);
						pafcore::Reflection::SetArrayInstanceProperty(&that, instanceProperty, i, propertyValue);
						//if (!propertyValue.m_type->isReference())
						//{
						//	propertyValue.unhold();
						//}
					}
				}
			}
		}
		else if (instanceProperty->get_isList())
		{
			xml_attribute* listSizeAttr = childNode->first_attribute("listSize");
			if (0 == listSizeAttr)
			{
				return;
			}
			size_t propertySize = strtoul(listSizeAttr->value(), 0, 0);
			for (xml_node* valueNode = childNode->first_node(); valueNode != 0; valueNode = valueNode->next_sibling())
			{
				char* nodeName = valueNode->name();
				if ('_' != nodeName[0])
				{
					continue;
				}
				pafcore::Variant propertyValue;
				pafcore::Type* valueType = instanceProperty->get_setterType();
				if (valueType->isReference())
				{
					xml_attribute* typeAttr = valueNode->first_attribute("type");
					if (typeAttr)
					{
						valueType = pafcore::Reflection::GetTypeFromFullName(typeAttr->value());
					}
				}
				pafcore::Reflection::NewObject(propertyValue, valueType);
				XmlToVariant(propertyValue, valueNode, xmlCdata);
				pafcore::Reflection::ListInstanceProperty_PushBack(&that, instanceProperty, propertyValue);
				//if (!propertyValue.m_type->isReference())
				//{
				//	propertyValue.unhold();
				//}
			}
		}
		else if (instanceProperty->get_isMap())
		{
			xml_attribute* mapSizeAttr = childNode->first_attribute("mapSize");
			if (0 == mapSizeAttr)
			{
				return;
			}
			size_t propertySize = strtoul(mapSizeAttr->value(), 0, 0);
			if (instanceProperty->get_hasSetter())
			{
				for (size_t i = 0; i < propertySize; ++i)
				{
					char buf[64];
					sprintf_s(buf, "k_%u", (uint32_t)i);
					xml_node* keyNode = childNode->first_node(buf);
					sprintf_s(buf, "v_%u", (uint32_t)i);
					xml_node* valueNode = childNode->first_node(buf);
					if (keyNode && valueNode)
					{
						pafcore::Variant propertyKey;
						pafcore::Variant propertyValue;
			
						pafcore::Type* keyType = instanceProperty->get_keyType();
						if (keyType->isReference())
						{
							xml_attribute* typeAttr = keyNode->first_attribute("type");
							if (typeAttr)
							{
								keyType = pafcore::Reflection::GetTypeFromFullName(typeAttr->value());
							}
						}
						pafcore::Reflection::NewObject(propertyKey, keyType);
						XmlToVariant(propertyKey, keyNode, xmlCdata);

						pafcore::Type* valueType = instanceProperty->get_setterType();
						if (valueType->isReference())
						{
							xml_attribute* typeAttr = valueNode->first_attribute("type");
							if (typeAttr)
							{
								valueType = pafcore::Reflection::GetTypeFromFullName(typeAttr->value());
							}
						}
						pafcore::Reflection::NewObject(propertyValue, valueType);
						XmlToVariant(propertyValue, valueNode, xmlCdata);
						pafcore::Reflection::SetMapInstanceProperty(&that, instanceProperty, &propertyKey, propertyValue);

						//if (!propertyKey.m_type->isReference())
						//{
						//	propertyKey.unhold();
						//}
						//if (!propertyValue.m_type->isReference())
						//{
						//	propertyValue.unhold();
						//}
					}
				}
			}
		}
		else
		{
			pafcore::Variant propertyValue;
			pafcore::Type* type = instanceProperty->get_setterType();
			if (type)
			{
				if (type->isReference())
				{
					xml_attribute* typeAttr = childNode->first_attribute("type");
					if (typeAttr)
					{
						type = pafcore::Reflection::GetTypeFromFullName(typeAttr->value());
					}
				}
				pafcore::Reflection::NewObject(propertyValue, instanceProperty->get_setterType());
				XmlToVariant(propertyValue, childNode, xmlCdata);
				pafcore::Reflection::SetInstanceProperty(&that, instanceProperty, propertyValue);
				//if (!propertyValue.m_type->isReference())
				//{
				//	propertyValue.unhold();
				//}
			}
		}
	}
}

static void XmlToClass(pafcore::Variant& that, xml_node* node)
{
	pafcore::Type* type = that.m_type;
	PAF_ASSERT(type->isValue() || type->isReference());
	pafcore::ClassType* classType = static_cast<pafcore::ClassType*>(type);

	size_t fieldCount = classType->_getInstanceFieldCount_(true);
	for (size_t i = 0; i < fieldCount; ++i)
	{
		pafcore::InstanceField* instanceField = classType->_getInstanceField_(i, true);
		XmlToInstanceField(that, instanceField, node);
	}

	size_t propertyCount = classType->_getInstancePropertyCount_(true);
	for (size_t i = 0; i < propertyCount; ++i)
	{
		pafcore::InstanceProperty* instanceProperty = classType->_getInstanceProperty_(i, true);
		XmlToInstanceProperty(that, instanceProperty, node);
	}

	pafcore::InstanceMethod* dynamicInstanceField = classType->findInstanceMethod("dynamicInstanceField", false);
	pafcore::InstanceMethod* dynamicInstanceFieldCount = classType->findInstanceMethod("dynamicInstanceFieldCount", false);
	if (dynamicInstanceField && dynamicInstanceFieldCount)
	{
		pafcore::Variant countVar;
		if (pafcore::s_ok == pafcore::Reflection::CallInstanceMethod(countVar, &that, dynamicInstanceFieldCount, 0, 0))
		{
			uint32_t count;
			countVar.castToPrimitive(RuntimeTypeOf<uint32_t>::RuntimeType::GetSingleton(), &count);
			for (uint32_t i = 0; i < count; ++i)
			{
				pafcore::Variant instanceFieldVar;
				pafcore::Variant indexVar;
				indexVar.assignPrimitive(RuntimeTypeOf<uint32_t>::RuntimeType::GetSingleton(), &i);
				if (pafcore::s_ok == pafcore::Reflection::CallInstanceMethod(instanceFieldVar, &that, dynamicInstanceField, &indexVar, 1)
					&& RuntimeTypeOf<::pafcore::InstanceField>::RuntimeType::GetSingleton() == instanceFieldVar.m_type)
				{
					pafcore::InstanceField* instanceField = reinterpret_cast<pafcore::InstanceField*>(instanceFieldVar.m_pointer);
					XmlToInstanceField(that, instanceField, node);
				}
			}
		}
	}

	if (classType->isReference())
	{
		pafcore::Reference* reference = (pafcore::Reference*)that.m_pointer;
		uint32_t count = reference->dynamicInstancePropertyCount();
		for (uint32_t i = 0; i < count; ++i)
		{
			pafcore::InstanceProperty* instanceProperty = reference->dynamicInstanceProperty(i);
			XmlToInstanceProperty(that, instanceProperty, node);
		}
	}
}

static void XmlToVariant(pafcore::Variant& variant, xml_node* node, bool xmlCdata)
{
	if (0 == node)
	{
		return;
	}
	pafcore::Type* type = variant.m_type;
	if (type->isPrimitive())
	{
		pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(type);
		if (primitiveType->isString())
		{
			XmlToRawString(variant, node, xmlCdata);
		}
		else
		{
			XmlToPrimitive(variant, node);
		}
	}
	else if (type->isEnum())
	{
		XmlToEnum(variant, node);
	}
	else if (type->isClass())
	{
		if (RuntimeTypeOf<::pafcore::String>::RuntimeType::GetSingleton() == type)
		{
			return XmlToString(variant, node, xmlCdata);
		}
		else
		{
			XmlToClass(variant, node);
		}
	}
}


xml_node* XmlSerializer::Serialize(void* object, pafcore::Type* type, const char* name, xml_document& doc)
{
	if (0 == object || 0 == type)
	{
		return 0;
	}
	pafcore::Variant variant;
	variant.assignPtr(type, object, false, pafcore::Variant::by_ptr);
	return VariantToXml(name, &variant, doc, false);
}

xml_node* XmlSerializer::Serialize(pafcore::Reference* reference, const char* name, xml_document& doc)
{
	if (0 == reference)
	{
		return 0;
	}
	pafcore::ClassType* type = reference->getType();
	size_t address = reference->getAddress();
	return Serialize((void*)address, type, name, doc);
}

void XmlSerializer::Unserialize(void* object, pafcore::Type* type, xml_node* node)
{
	if (0 != object && 0 != type && 0 != node)
	{
		pafcore::Variant variant;
		variant.assignPtr(type, object, false, pafcore::Variant::by_ptr);
		XmlToVariant(variant, node, false);
	}
}

void XmlSerializer::Unserialize(pafcore::Reference* reference, xml_node* node)
{
	if (0 != reference && 0 != node)
	{
		pafcore::ClassType* type = reference->getType();
		size_t address = reference->getAddress();
		Unserialize((void*)address, type, node);
	}
}

void XmlSerializer::Unserialize(pafcore::Variant& object, xml_node* node, pafcore::Type* type)
{
	object.clear();
	if (0 == type || type->isReference())
	{
		xml_attribute* typeAttr = node->first_attribute("type");
		if (typeAttr)
		{
			type = pafcore::Reflection::GetTypeFromFullName(typeAttr->value());
		}
	}
	if (0 == type)
	{
		return;
	}
	pafcore::Reflection::NewObject(object, type);
	//object.unhold();
	Unserialize(object.m_pointer, type, node);
}

END_PAFSTD
