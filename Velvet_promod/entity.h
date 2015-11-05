#pragma once

#include "sdk.h"

class centity
{
public:
	inline int flags()
	{
		return readptr<int>(this, 0x2DC); //m_fFlags
	}
	inline Vector getpunchangle()
	{
		return readptr<Vector>(this, (0xCA0 + 0x6C)); //m_Local + m_vecPunchAngle
	}
	inline int gettickbase()
	{
		return readptr<int>(this, 0xFB8); //m_nTickBase
	}
	inline unsigned long getactiveweapon()
	{
		return readptr<unsigned long>(this, 0xC4C); //m_hActiveWeapon
	}
	inline bool isdormant()
	{
		return getvfunc<bool(__thiscall *)(void *)>((this + 0x8), 8)((this + 0x8));
	}
	inline void *getmodel()
	{
		return getvfunc<void *(__thiscall *)(void *)>((this + 0x4), 9)((this + 0x4));
	}
	inline Vector& getabsorigin()
	{
		return getvfunc<Vector&(__thiscall *)(void *)>(this, 10)(this);
	}
	inline Vector getvecviewoffset()
	{
		return readptr<Vector>(this, 0xDC); //m_vecViewOffset[0]
	}
	inline Vector geteyepos()
	{
		return getabsorigin() + getvecviewoffset();
	}
};
extern centity *ent;