#pragma once

#include "Utility.h"

template<typename T>
struct AutoRegisterType
{
};

#define AUTO_REGISTER_TYPE(T)						\
template<>											\
struct AutoRegisterType<T>							\
{													\
	AutoRegisterType()								\
	{												\
		T::GetSingleton();							\
	}												\
	static AutoRegisterType<T> s_instance;			\
};													\
AutoRegisterType<T> AutoRegisterType<T>::s_instance;


template<typename T>
struct AutoRegisterTypeAlias
{
public:
	AutoRegisterTypeAlias()
	{
		T::GetSingleton();
	}
};

#define AUTO_REGISTER_TYPEALIAS(T) AutoRegisterTypeAlias<T> g_auto_register_##T;

#define BEGIN_AUTO_RUN(T)		\
struct AutoRun_##T				\
{								\
	AutoRun_##T()				\
	{

#define END_AUTO_RUN(T)			\
	}							\
};								\
static AutoRun_##T s_autoRun_##T;