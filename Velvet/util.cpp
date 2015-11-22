#include "velvet.h"

using namespace velvet;

DWORD util::findpattern(DWORD address, size_t size, const char* pattern)
{
	for (size_t i = 0; i < size; ++i, ++address)
	if (util::datacompare((const char*) address, pattern))
		return address;

	return 0;
}

bool util::datacompare(const char* base, const char* pattern)
{
	for (; *pattern; ++base, ++pattern)
	if (*pattern != '?' && *base != *pattern)
		return 0;

	return *pattern == 0;
}