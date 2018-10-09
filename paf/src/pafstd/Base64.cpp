#include "Base64.h"

BEGIN_PAFSTD

static char s_base64EncodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const char s_base64DecodeTable[] =
{
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -2, -2, -1, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62, -2, -2, -2, 63,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2, -2, -2, -2, -2,
	-2,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2, -2, -2, -2, -2,
	-2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
};

size_t Base64::Encode(void* dst, const void* src, size_t srcLen)
{
	const byte_t* curSrc = (const byte_t*)src;
	char* curDst = (char*)dst;

	size_t len = srcLen;
	while (len >= 3)
	{
		curDst[0] = s_base64EncodeTable[curSrc[0] >> 2];
		curDst[1] = s_base64EncodeTable[((curSrc[0] & 0x03) << 4) + (curSrc[1] >> 4)];
		curDst[2] = s_base64EncodeTable[((curSrc[1] & 0x0f) << 2) + (curSrc[2] >> 6)];
		curDst[3] = s_base64EncodeTable[curSrc[2] & 0x3f];
		
		curSrc += 3;
		curDst += 4;
		len -= 3;
		if (0 == (curSrc - (const byte_t*)src) % 57)
		{
			*curDst++ = '\n';
		}
	}
	switch (len)
	{
	case 1:
		curDst[0] = s_base64EncodeTable[curSrc[0] >> 2];
		curDst[1] = s_base64EncodeTable[(curSrc[0] & 0x03) << 4];
		curDst[2] = '=';
		curDst[3] = '=';
		curDst += 4;
		break;
	case 2:
		curDst[0] = s_base64EncodeTable[curSrc[0] >> 2];
		curDst[1] = s_base64EncodeTable[((curSrc[0] & 0x03) << 4) + (curSrc[1] >> 4)];
		curDst[2] = s_base64EncodeTable[(curSrc[1] & 0x0f) << 2];
		curDst[3] = '=';
		curDst += 4;
		break;
	}
	return (curDst - (char*)dst);
}

size_t Base64::Decode(void* dst, const void* src, size_t srcLen)
{
	byte_t* curDst = (byte_t*)dst;

	char chs[4];
	size_t current = 0;
	for(size_t i = 0; i < srcLen; ++i)
	{
		char ch = ((const char*)src)[i];
		if ('=' == ch)
		{
			break;
		}
		ch = s_base64DecodeTable[byte_t(ch)];
		if (ch < 0)//char == -1
		{
			continue;
		}
		chs[current++] = ch;
		if (4 == current)
		{
			curDst[0] = (chs[0] << 2) | (chs[1] >> 4);
			curDst[1] = (chs[1] << 4) | (chs[2] >> 2);
			curDst[2] = (chs[2] << 6) | (chs[3]);
			curDst += 3;
			current = 0;
		}
	}
	switch (current)
	{
	case 2:
		curDst[0] = (chs[0] << 2) | (chs[1] >> 4);
		curDst += 1;
		break;
	case 3:
		curDst[0] = (chs[0] << 2) | (chs[1] >> 4);
		curDst[1] = (chs[1] << 4) | (chs[2] >> 2);
		curDst += 2;
		break;
	}
	return (curDst - (byte_t*)dst);
}

END_PAFSTD