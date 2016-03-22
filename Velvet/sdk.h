#pragma once

#include <Windows.h>
#include "vector.h"
#include "matrix3x4.h"
#include "vmt.h"
#include "getvfunc.h"
#include "cusercmd.h"
#include "enums.h"
#include "globalvars.h"
#include "entity.h"
#include "baseclient.h"
#include "clientframestage.h"
#include "clientmodeshared.h"
#include "engineclient.h"
#include "debugoverlay.h"
#include "entlist.h"
#include "gamemovement.h"
#include "misc.h"

#define localplayer() (elist->getcliententity(engine->getlocalplayer()))

typedef void(__cdecl *MsgFn)(const char *, ...);
typedef void(__cdecl *WarningFn)(const char *, ...);

extern MsgFn msg;
extern WarningFn warning;