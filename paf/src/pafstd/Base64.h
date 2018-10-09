#pragma once

#include "Utility.h"

BEGIN_PAFSTD

class PAFSTD_EXPORT Base64
{
public:
	static size_t Encode(void* dst, const void* src, size_t srcLen);
	static size_t Decode(void* dst, const void* src, size_t srcLen);
	static size_t EncodeBufferLength(size_t srcLen);
	static size_t DecodeBufferLength(size_t srcLen);
};

//------------------------------------------------------------------------------
inline size_t Base64::EncodeBufferLength(size_t srcLen)
{
	size_t dstLen = (srcLen + 2) / 3 * 4;
	dstLen += dstLen / 76;
	return dstLen;
}

inline size_t Base64::DecodeBufferLength(size_t srcLen)
{
	return srcLen / 4 * 3;
}

END_PAFSTD
