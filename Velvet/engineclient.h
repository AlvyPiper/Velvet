#include "sdk.h"

class cengine
{
public:
	inline int getlocalplayer()
	{
		return getvfunc<int(__thiscall *)(void *)>(this, 12)(this);
	}
	inline void getviewangles(Vector &ang)
	{
		return getvfunc<void(__thiscall *)(void *, Vector&)>(this, 18)(this, ang);
	}
	inline void setviewangles(Vector &ang)
	{
		return getvfunc<void(__thiscall *)(void *, Vector&)>(this, 19)(this, ang);
	}
	inline int getmaxclients()
	{
		return getvfunc<int(__thiscall *)(void *)>(this, 20)(this);
	}
};
extern cengine *engine;