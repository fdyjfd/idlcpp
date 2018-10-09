#import "../pafcore/Typedef.i"
#import "Blob.i"

#{
#include "Utility.h"
#include "String.h"
#include <vector>
#}

namespace pafstd
{
	class(value_object) #PAFSTD_EXPORT BinaryXmlAttribute
	{
		void setName(const char* name);
		const char* getName();
		void setValue(const char* value);
		const char* getValue();
#{
	public:
		String m_name;
		String m_value;
#}
	};

	class(value_object) #PAFSTD_EXPORT BinaryXmlElement
	{
		void setName(const char* name);
		const char* getName();
		size_t getNumAttributes();
		BinaryXmlAttribute* getAttribute(size_t index);
		size_t getNumChildren();
		BinaryXmlElement* getChild(size_t index);
		void insertChild(size_t index, BinaryXmlElement* element);
		void addChild(BinaryXmlElement* element);
		void setAttribute(const char* name, const char* value);
		BinaryXmlAttribute* getAttribute(const char* name);
		void clear();
#{
	public:
		typedef std::vector<BinaryXmlElement*> BinaryXmlElementContainer;
		typedef std::vector<BinaryXmlAttribute*> BinaryXmlAttributeContainer;
	public:
		~BinaryXmlElement();
	public:
		String m_name;
		BinaryXmlAttributeContainer m_attributes;
		BinaryXmlElementContainer m_children;
#}
	};

	class(value_object) #PAFSTD_EXPORT BinaryXml
	{
		static Blob* WriteBml(BinaryXmlElement* root, uint32_t headSpace #{ = 0 #});
		static Blob* WriteBmlToXml(BinaryXmlElement* root);
		//static Blob* WriteBmlToBufferEx(BinaryXmlElement* root, uint32_t headerSize);
#{
		static void WriteBmlToFile(BinaryXmlElement* root, FILE* file);
		//static void WriteBmlToFileEx(BinaryXmlElement* root, const void* header, uint32_t headerSize, FILE* file);
#}
	};

	class(value_object) #PAFSTD_EXPORT FixedBinaryXmlAttribute
	{
		int32_t m_nameOffset;
		int32_t m_valueOffset;
	};

	class(value_object) #PAFSTD_EXPORT FixedBinaryXmlElement
	{
		int32_t m_nameOffset;
		int32_t m_numAttributes;
		int32_t m_attributesOffset;
		int32_t m_numChildren;
		int32_t m_childrenOffset;
	};

	class(value_object) #PAFSTD_EXPORT FixedBinaryXmlParser
	{
		FixedBinaryXmlParser();
		void setBuffer(void* buffer);
		FixedBinaryXmlElement* getRootElement();
		FixedBinaryXmlAttribute* getAttribute(FixedBinaryXmlElement* element, size_t index);
		FixedBinaryXmlElement* getChildElement(FixedBinaryXmlElement* element, size_t index);
		const char* getAttributeName(FixedBinaryXmlAttribute* attribute);
		const char* getAttributeValue(FixedBinaryXmlAttribute* attribute);
		const char* getElementName(FixedBinaryXmlElement* element);
#{
		char* m_buffer;
#}
	};

}

