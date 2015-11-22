#pragma once

#include "sdk.h"

class centity
{
public:
	inline int flags()
	{
		return readptr<int>(this, 0x100); //m_fFlags
	}
	inline Vector getpunchangle()
	{
		return readptr<Vector>(this, (0x2FF8)); //m_Local + m_vecPunchAngle (0x2F88 + 0x64)
	}
	inline int gettickbase()
	{
		return readptr<int>(this, 0x33EC); //m_nTickBase
	}
	inline DWORD getactiveweapon()
	{
		return readptr<DWORD>(this, 0x2EC8); //m_hActiveWeapon
	}
	inline bool isdormant()
	{
		return getvfunc<bool(__thiscall *)(void *)>((this + 0x8), 9)((this + 0x8));
	}
	inline void *getmodel()
	{
		return getvfunc<void *(__thiscall *)(void *)>((this + 0x4), 8)((this + 0x4));
	}
	inline Vector& getabsorigin()
	{
		return getvfunc<Vector&(__thiscall *)(void *)>(this, 10)(this);
	}
	inline Vector getvecviewoffset()
	{
		return readptr<Vector>(this, 0x104); //m_vecViewOffset[0]
	}
	inline Vector geteyepos()
	{
		return getabsorigin() + getvecviewoffset();
	}
};
extern centity *ent;