/*

Name: Velvet
Author: Alvy Piper (no contact email currently)
Copyright: 2015
Usage: More complex than GreenTea and also SDKless. A simple internal cheat with bunnyhop and norecoil, written for CSPromod BETA 1.10b for fun.
Using content created by: Oubliette, NanoCat, and Valve.

Any content creator that wants their work removed can contact me at my contact email.

Feel free to redistribute, modify, and share. Please give credit where it is due, though.

*/

#pragma once

#include "sdk.h"

namespace velvet
{
	namespace hookmngr
	{
		extern bool __fastcall createmove(void*, void*, float, cusercmd*);
		extern void __fastcall painttraverse(void*, void*, unsigned int, bool, bool);
		extern void(__thiscall *org_painttraverse)(void*, unsigned int, bool, bool);
	}

	namespace init
	{
		void dosigscan();
		void dointerface();
		void dohook();
		void finalize();
	}

	namespace util
	{
		extern bool datacompare(const char*, const char*);
		extern unsigned long findpattern(unsigned long, unsigned long, const char*);
	}
}