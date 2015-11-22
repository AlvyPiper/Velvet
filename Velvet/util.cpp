#include "velvet.h"

using namespace velvet;

unsigned long util::findpattern(unsigned long address, unsigned long size, const char* pattern)
{
	for (unsigned long i = 0; i < size; ++i, ++address)
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