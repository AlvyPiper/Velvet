#include "sdk.h"

class cdebugoverlay
{
public:
	inline int screenposition(Vector& origin, Vector& screen)
	{
		return getvfunc<int(__thiscall *)(void*, Vector&, Vector&)>(this, 13)(this, origin, screen);
	}
};
extern cdebugoverlay *debugoverlay;
