#pragma once

#include "Utility.h"
#include "Metadata.h"

BEGIN_PAFCORE

class Result;
class Argument;
class Variant;

struct PAFCORE_EXPORT Overload
{
	Result* m_result;
	Argument* m_args;
	uint16_t m_argCount;
	bool m_isStatic;
	bool m_isConstant;
public:
	Overload(Result* result, Argument* args, size_t argCount, bool isStatic, bool isConstant);
	bool matchArguments(char* matches, Variant** variants);
	static size_t Resolution(Overload* overloads, Variant** variants, size_t argCount, size_t overloadCount, size_t* candidates, char* argMatches);
};


typedef ErrorCode(*FunctionInvoker)(Variant* result, Variant** args, int_t numArgs);

END_PAFCORE