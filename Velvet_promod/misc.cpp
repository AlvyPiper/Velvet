#include "misc.h"

void cmisc::norecoil(cusercmd *cmd)
{
	if (localplayer()->getactiveweapon() != 0xFFFFFFFF) //do NOT read if the handle is invalid
	{
		Vector oldpunch = localplayer()->getpunchangle(); //read & backup punch

		gamemovement->decaypunchangle(); //decaypunchangle

		Vector newpunch = localplayer()->getpunchangle(); //read new punch

		if (cmd->buttons &IN_ATTACK)
		{
			cmd->viewangles -= newpunch * 2.0f; //2.0f is magnitude https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/mp/src/game/shared/gamemovement.cpp#L1229 this game runs on 2007, but same concept.
		}
		newpunch = oldpunch; //restore punch
	}
}

void cmisc::bunnyhop(cusercmd *cmd) //TODO: Clean up and use proper bitwise.
{
	if (cmd->buttons &IN_JUMP && (!(localplayer()->flags() &FL_ONGROUND))) //checks if player is not on the ground and in jump
	{
		cmd->buttons &= ~IN_JUMP; //sets them to not be jumping.
	}
}