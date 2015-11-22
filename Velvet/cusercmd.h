#include "sdk.h"

class cusercmd
{
private:
	char	pad00[4];
public:
	int		command_number;
	int		tick_count;
	Vector	viewangles;
	Vector	aimdirection;
	Vector	move;
	int		buttons;
	char	impulse;
	int		weaponselect;
	int		weaponsubtype;
	int		random_seed;
	short	mousedx;
	short	mousedy;
	bool	hasbeenpredicted;
private:
	char	pad01[24];
};