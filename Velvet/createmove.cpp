#include "velvet.h"

using namespace velvet;

cmisc *misc;

bool __fastcall hookmngr::createmove(void* thishook, void*, float frametime, cusercmd* cmd)
{
	if (cmd->command_number == 0) //if command_number is 0 then ExtraMouseSample is being called
		return 0;

	// get localplayer
	centity* local = localplayer();

	if (!local)
		return 0;

	misc->norecoil(local, cmd);
	misc->bunnyhop(local, cmd);

	return 0; //return 1 if you want to call engine->SetViewAngles
}