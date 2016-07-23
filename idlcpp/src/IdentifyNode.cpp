#include "IdentifyNode.h"


IdentifyNode::IdentifyNode(const char* str, int tokenNo, int lineNo, int columnNo)
	: TokenNode(snt_identify, tokenNo, lineNo, columnNo), m_str(str)
{}


IdentifyNode::IdentifyNode(const char* str, size_t len, int tokenNo, int lineNo, int columnNo)
	: TokenNode(snt_identify, tokenNo, lineNo, columnNo), m_str(str, len)
{}
