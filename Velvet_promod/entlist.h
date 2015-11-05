#pragma once

#include "sdk.h"

class celist
{
public:
	inline centity *getcliententity(int i)
	{
		return getvfunc<centity *(__thiscall *)(void *, int)>(this, 3)(this, i);
	}
	inline centity *entfromhandle(unsigned long i)
	{
		return getvfunc<centity *(__thiscall *)(void *, int)>(this, 6)(this, i);
	}
};
extern celist *elist;