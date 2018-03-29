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
