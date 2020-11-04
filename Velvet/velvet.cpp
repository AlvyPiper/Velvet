/*

Name: Velvet
Author: Alvy Piper <alvycat@protonmail.com>
CSGO adaptation: aixxe <aixxe@skyenet.org>
Copyright: 2015
Usage: More complex than GreenTea and also SDKless. A simple internal cheat with bunnyhop and norecoil, written for CSPromod BETA 1.10b for fun.
Using content created by: Casual_Hacker ( http://www.unknowncheats.me/forum/member239231.html ), NanoCat, and Valve.

Any content creator that wants their work removed can contact me on UnknownCheats for now. ( http://www.unknowncheats.me/forum/members/334125.html )

Feel free to redistribute, modify, and share. Please give credit where it is due, though.

*/

#include "velvet.h"

using namespace velvet;

void inject() //TODO: Change this with init::finalize in DLLMain.
{
	init::finalize();
}

bool __stdcall entry(HINSTANCE inst, DWORD reason, LPVOID reserved)
{
	if (reason == 1)
	{
		DisableThreadLibraryCalls(inst);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE) inject, 0, 0, 0);
	}
	TerminateThread(inject, 0);
	return 1;
}
