#include "BinaryXml.h"
#include "BinaryXml.mh"
#include "BinaryXml.ic"
#include "BinaryXml.mc"
#include "Blob.h"
#include <map>

BEGIN_PAFSTD

void BinaryXmlAttribute::setName(const char* name)
{
	m_name = name;
}

void BinaryXmlAttribute::setValue(const char* value)
{
	m_value = value;
}

const char* BinaryXmlAttribute::getName()
{
	return m_name.c_str();
}

const char* BinaryXmlAttribute::getValue()
{
	return m_value.c_str();
}

BinaryXmlElement::~BinaryXmlElement()
{
	clear();
}

void BinaryXmlElement::setName(const char* name)
{
	m_name = name;
}

const char* BinaryXmlElement::getName()
{
	return m_name.c_str();
}

size_t BinaryXmlElement::getNumAttributes()
{
	return m_attributes.size();
}

BinaryXmlAttribute* BinaryXmlElement::getAttribute(size_t index)
{
	if(index < m_attributes.size())
	{
		return m_attributes[index];
	}
	return 0;
}

size_t BinaryXmlElement::getNumChildren()
{
	return m_children.size();
}

BinaryXmlElement* BinaryXmlElement::getChild(size_t index)
{
	if(index < m_children.size())
	{
		return m_children[index];
	}
	return 0;
}

void BinaryXmlElement::insertChild(size_t index, BinaryXmlElement* element)
{
	size_t count = m_children.size();
	if(index > count)
	{
		index = count;
	}
	m_children.insert(m_children.begin() + index, element);
}

void BinaryXmlElement::addChild(BinaryXmlElement* element)
{
	m_children.push_back(element);
}

void BinaryXmlElement::setAttribute(const char* name, const char* value)
{
	size_t count = m_attributes.size();
	for(size_t i = 0; i < count; ++i)
	{
		if(m_attributes[i]->m_name == name)
		{
			m_attributes[i]->setValue(value);
			return;
		}
	}
	BinaryXmlAttribute* attribute = paf_new BinaryXmlAttribute;
	attribute->setName(name);
	attribute->setValue(value);
	m_attributes.push_back(attribute);
}

BinaryXmlAttribute* BinaryXmlElement::getAttribute(const char* name)
{
	size_t count = m_attributes.size();
	for(size_t i = 0; i < count; ++i)
	{
		if(m_attributes[i]->m_name == name)
		{
			return m_attributes[i];
		}
	}
	return 0;
}

void BinaryXmlElement::clear()
{
	{
		BinaryXmlAttributeContainer::iterator it = m_attributes.begin();
		BinaryXmlAttributeContainer::iterator end = m_attributes.end();
		for(; it != end; ++it)
		{
			delete (*it);
		}
		m_attributes.clear();
	}
	{
		BinaryXmlElementContainer::iterator it = m_children.begin();
		BinaryXmlElementContainer::iterator end = m_children.end();
		for(; it != end; ++it)
		{
			delete (*it);
		}
		m_children.clear();
	}
}

struct CompareString
{
	bool operator()(const String& s1, const String& s2) const
	{
		return s1.compare(s2) < 0;
	}
};

typedef std::map<String, size_t, CompareString> StringContainer;

const size_t sizeof_fixed_bml_attribute = sizeof(int32_t)*2;
const size_t sizeof_fixed_bml_element = sizeof(int32_t)*5;


static void CollectBmlInfo(size_t& totalNumElements, size_t& totalNumAttributes, StringContainer& allStrings, BinaryXmlElement* bmlElement)
{
	if(0 != bmlElement)
	{
		++totalNumElements;
		allStrings.insert(std::make_pair(bmlElement->m_name, 0));
		size_t numAttributes = bmlElement->getNumAttributes();
		totalNumAttributes += numAttributes;
		for(size_t i = 0; i < numAttributes; ++i)
		{
			BinaryXmlAttribute* bmlAttribute = bmlElement->getAttribute(i);
			allStrings.insert(std::make_pair(bmlAttribute->m_name,0));
			allStrings.insert(std::make_pair(bmlAttribute->m_value,0));
		}
		size_t numChildren = bmlElement->getNumChildren();
		for(size_t i = 0; i < numChildren; ++i)
		{
			CollectBmlInfo(totalNumElements, totalNumAttributes, allStrings, bmlElement->getChild(i));
		}
	}
}

static size_t CalcStringBufferSize(StringContainer& allStrings)
{
	size_t res = 0;
	StringContainer::iterator it = allStrings.begin();
	StringContainer::iterator end = allStrings.end();
	for(; it != end; ++it)
	{
		it->second = res;
		res += it->first.length() + 1;
	}
	return res;
}

static void WriteBmlInfo(BinaryXmlElement* bmlElement, char* buffer, size_t elementOffset, size_t& childrenOffset, size_t& attributesOffset, size_t stringOffset, StringContainer& allStrings)
{
	if(0 != bmlElement)
	{
		size_t numAttributes = bmlElement->getNumAttributes();
		size_t numChildren = bmlElement->getNumChildren();
		*(int32_t*)(buffer + elementOffset) = int32_t(allStrings.find(bmlElement->m_name)->second + stringOffset);
		*(int32_t*)(buffer + elementOffset + sizeof(int32_t)) = int32_t(numAttributes);
		*(int32_t*)(buffer + elementOffset + sizeof(int32_t)*2) = int32_t(attributesOffset);
		*(int32_t*)(buffer + elementOffset + sizeof(int32_t)*3) = int32_t(numChildren);
		*(int32_t*)(buffer + elementOffset + sizeof(int32_t)*4) = int32_t(childrenOffset);

		for(size_t i = 0; i < numAttributes; ++i)
		{
			BinaryXmlAttribute* bmlAttribute = bmlElement->getAttribute(i);
			*(int32_t*)(buffer + attributesOffset) = int32_t(allStrings.find(bmlAttribute->m_name)->second + stringOffset);
			*(int32_t*)(buffer + attributesOffset + sizeof(int32_t)) = int32_t(allStrings.find(bmlAttribute->m_value)->second + stringOffset);
			attributesOffset += sizeof_fixed_bml_attribute;
		}
		elementOffset = childrenOffset;
		childrenOffset += numChildren * sizeof_fixed_bml_element;
		for(size_t i = 0; i < numChildren; ++i)
		{
			WriteBmlInfo(bmlElement->getChild(i), buffer, elementOffset, childrenOffset, attributesOffset, stringOffset, allStrings);
			elementOffset += sizeof_fixed_bml_element;
		}
	}
}

static void WriteStringBuffer(char* buffer, StringContainer& allStrings)
{
	StringContainer::iterator it = allStrings.begin();
	StringContainer::iterator end = allStrings.end();
	for(; it != end; ++it)
	{
		char* pos = buffer + it->second;
		memcpy(pos, it->first.c_str(), it->first.length() + 1);
	}
}

Blob* BinaryXml::WriteBml(BinaryXmlElement* root, uint32_t headSpace)
{
	size_t totalNumElements = 0;
	size_t totalNumAttributes = 0;
	StringContainer allStrings;
	CollectBmlInfo(totalNumElements, totalNumAttributes, allStrings, root);
	size_t stringBufferSize = CalcStringBufferSize(allStrings);	
	size_t elementOffset = 0;
	size_t childrenOffset = sizeof_fixed_bml_element;
	size_t attributesOffset = totalNumElements * sizeof_fixed_bml_element;
	size_t stringOffset = attributesOffset + totalNumAttributes * sizeof_fixed_bml_attribute;
	size_t bufferSize = stringOffset + stringBufferSize + headSpace;
	if(0 < bufferSize)
	{
		Blob* blob = Blob::New((uint32_t)bufferSize);
		char* buffer = (char*)blob->getData() + headSpace;
		WriteBmlInfo(root, buffer, elementOffset, childrenOffset, attributesOffset, stringOffset, allStrings);
		WriteStringBuffer(buffer + stringOffset, allStrings);
		return blob;
	}
	return 0;
}

static void BmlToXml(std::string& str, BinaryXmlElement* element, uint32_t  indent)
{
	for (uint32_t  i = 0; i < indent; ++i)
	{
		str += '\t';
	}
	str += '<';
	str += element->getName();
	size_t attrCount = element->getNumAttributes();
	for (size_t i = 0; i < attrCount; ++i)
	{
		BinaryXmlAttribute* attr = element->getAttribute(i);
		str += ' ';
		str += attr->getName();
		str += "=\"";
		str += attr->getValue();
		str += '\"';
	}
	size_t childCount = element->getNumChildren();
	if (0 == childCount)
	{
		str += "/>\n";
	}
	else
	{
		str += ">\n";
		for (size_t i = 0; i < childCount; ++i)
		{
			BinaryXmlElement* childElement = element->getChild(i);
			BmlToXml(str, childElement, indent + 1);
		}
		str += "</";
		str += element->getName();
		str += ">\n";
	}
}

Blob* BinaryXml::WriteBmlToXml(BinaryXmlElement* root)
{
	std::string str = "<?xml version=\"1.0\" encoding=\"gbk\"?>\n";
	BmlToXml(str, root, 0);
	size_t length = str.length() + 1;
	Blob* blob = Blob::New((uint32_t)length);
	memcpy(blob->getData(), str.c_str(), length);
	return blob;
}

//Blob* BinaryXml::WriteBmlToBufferEx(BinaryXmlElement* root, uint32_t headerSize)
//{
//	size_t totalNumElements = 0;
//	size_t totalNumAttributes = 0;
//	StringContainer allStrings;
//	CollectBmlInfo(totalNumElements, totalNumAttributes, allStrings, root);
//	size_t stringBufferSize = CalcStringBufferSize(allStrings);	
//	size_t elementOffset = 0;
//	size_t childrenOffset = sizeof_fixed_bml_element;
//	size_t attributesOffset = totalNumElements * sizeof_fixed_bml_element;
//	size_t stringOffset = attributesOffset + totalNumAttributes * sizeof_fixed_bml_attribute;
//	size_t bufferSize = stringOffset + stringBufferSize;
//	if(0 < bufferSize)
//	{
//		bufferSize += headerSize;
//		Blob* blob = Blob::New(bufferSize);
//		char* buffer = (char*)blob->getData();
//		buffer += headerSize;
//		WriteBmlInfo(root, buffer, elementOffset, childrenOffset, attributesOffset, stringOffset, allStrings);
//		WriteStringBuffer(buffer + stringOffset, allStrings);
//		return blob;
//	}
//	return 0;
//}

void BinaryXml::WriteBmlToFile(BinaryXmlElement* root, FILE* file)
{
	Blob* blob = WriteBml(root);
	if(blob)
	{
		fwrite(blob->getData(), blob->getLength(), 1, file);
		blob->release();
	}
}

//void BinaryXml::WriteBmlToFileEx(BinaryXmlElement* root, const void* header, uint32_t headerSize, FILE* file)
//{
//	Blob* blob = WriteBmlToBufferEx(root, headerSize);
//	if (blob)
//	{
//		void* data = blob->getData();
//		memcpy(data, header, headerSize);
//		fwrite(data, blob->getLength(), 1, file);
//		blob->release();
//	}
//
//}

FixedBinaryXmlParser::FixedBinaryXmlParser()
{
	m_buffer = 0;
}

void FixedBinaryXmlParser::setBuffer(void* buffer)
{
	m_buffer = (char*)buffer;
}

FixedBinaryXmlElement* FixedBinaryXmlParser::getRootElement()
{
	return reinterpret_cast<FixedBinaryXmlElement*>(m_buffer);
}

FixedBinaryXmlAttribute* FixedBinaryXmlParser::getAttribute(FixedBinaryXmlElement* element, size_t index)
{
	if(index < element->m_numAttributes)
	{
		FixedBinaryXmlAttribute* attribute = reinterpret_cast<FixedBinaryXmlAttribute*>(m_buffer + element->m_attributesOffset);
		return &attribute[index];
	}
	return 0;
}

FixedBinaryXmlElement* FixedBinaryXmlParser::getChildElement(FixedBinaryXmlElement* element, size_t index)
{
	if(index < element->m_numChildren)
	{
		FixedBinaryXmlElement* children = reinterpret_cast<FixedBinaryXmlElement*>(m_buffer + element->m_childrenOffset);
		return &children[index];
	}
	return 0;
}

const char* FixedBinaryXmlParser::getAttributeName(FixedBinaryXmlAttribute* attribute)
{
	return m_buffer + attribute->m_nameOffset;
}

const char* FixedBinaryXmlParser::getAttributeValue(FixedBinaryXmlAttribute* attribute)
{
	return m_buffer + attribute->m_valueOffset;
}

const char* FixedBinaryXmlParser::getElementName(FixedBinaryXmlElement* element)
{
	return m_buffer + element->m_nameOffset;
}

END_PAFSTD

