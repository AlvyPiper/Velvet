#pragma once

#include "sdk.h"

class cgamemovement
{
public:
	inline void decaypunchangle()
	{
		return getvfunc<void(__thiscall *)(void *)>(this, 19)(this);
	}
};
extern cgamemovement *gamemovement;