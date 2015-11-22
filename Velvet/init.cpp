#include "velvet.h"

using namespace velvet;
using namespace toolkit;

MsgFn				msg;
WarningFn			warning;

cclient				*client;
celist				*elist;
cengine				*engine;
clientmodeshared	*clientmode;
cglobalvars			*globals;
cgamemovement		*gamemovement;

void init::dosigscan()
{
	DWORD* clienttable = (DWORD*) *(DWORD*) client;
	clientmode = **(clientmodeshared***) (util::findpattern(clienttable[10], 0x100, "\x8B\x0D????\x8B") + 0x02); //http://www.unknowncheats.me/forum/source-engine/159253-finding-pointer-clientmode-any-game.html
	globals = **(cglobalvars***) (util::findpattern(clienttable[0], 0x100, "\xA3") + 0x01); //http://www.unknowncheats.me/forum/source-engine/160691-finding-globalvars-internally-without-having-have-any-kinda-reversing-knowledge.html
}

void init::dointerface()
{
	client = createinterface<cclient*>("client.dll", "VClient017"); //pointer to client
	engine = createinterface<cengine*>("engine.dll", "VEngineClient013"); //pointer to engineclient
	elist = createinterface<celist*>("client.dll", "VClientEntityList003"); //pointer to entitylist
	gamemovement = createinterface<cgamemovement*>("client.dll", "GameMovement001"); //pointer to gamemovement

	dosigscan(); //scans for clientmode and globals

	msg("client is at 0x%x\n", client); //allows us to check if pointer is valid
	msg("engine is at 0x%x\n", engine);
	msg("entitylist is at 0x%x\n", elist);
	msg("clientmode is at 0x%x\n", clientmode);
	msg("gamemovement is at 0x%x\n", gamemovement);
	msg("globals is at 0x%x\n", globals);
}

void init::dohook()
{
	dointerface(); //grabs pointers

	VMTBaseManager* clientModeHook = new VMTBaseManager(); //i found Casual_Hacker's vmthook & code for its use from Gir489's DarkStorm 2015 base ( https://bitbucket.org/gir489/darkstorm-2015-base/src/38d58d20a7268ce8aa84ea79fd86dfd6ef7c9143/DLLMain.cpp )
	clientModeHook->Init(clientmode); //sets up clientmode's vtable for replacement
	clientModeHook->HookMethod(&hookmngr::createmove, 24); //replaces the pointer to CreateMove with our own
	clientModeHook->Rehook(); //for some reason you have to rehook.

	msg("hooked createmove at 0x%x\n", hookmngr::createmove);
}

void init::finalize()
{
	msg = getexport<MsgFn>("tier0.dll", "Msg"); //get the export for Msg so we can print stuff in console
	warning = getexport<WarningFn>("tier0.dll", "Warning"); //Warning is red, in case you want to use that

	dohook(); //handles hooking

	msg("hello\n"); //we initialized correctly, phew!
}
