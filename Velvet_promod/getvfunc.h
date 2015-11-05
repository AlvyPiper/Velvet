#pragma once

#include "sdk.h"

template<typename I>
inline I createinterface(const char *dll, const char *name) //nanocats
{
	return (I) (((void *(*)(const char *, void *))GetProcAddress(GetModuleHandleA(dll), "CreateInterface"))(name, 0));
}

template<typename Ex>
inline Ex getexport(const char *dll, const char *name)
{
	return (Ex) ((void *(*)(const char *, const char *))GetProcAddress(GetModuleHandleA(dll), name));
}

template<typename T> //nanocats
inline T readptr(const void *base, int o)
{
	return *(T *) ((const char *) base + o);
}

template<typename T> //nanocats
inline void writeptr(void *base, int o, T v)
{
	*(T *) ((char *) base + o) = v;
}

template<typename T> //nanocats
inline T *makeptr(void *base, int o)
{
	return (T *) ((char *) base + o);
}

template<typename Fn>
inline Fn getvfunc(const void *v, int i)
{
	return (Fn) *(*(const void ***) v + i);
}