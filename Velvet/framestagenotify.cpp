#include "velvet.h"

using namespace velvet;

void __fastcall hookmngr::framestagenotify(void* thishook, void*, clientframestage_t stage) {
	// store values for applying novisrecoil
	static Vector oldaimpunch, oldviewpunch, *aimpunch, *viewpunch = nullptr;

	while (stage == FRAME_RENDER_START) {
		if (!engine->isingame())
			break;

		// get localplayer
		centity* local = localplayer();

		if (!local || local->lifestate() != 0)
			break;

		// get punch angle pointers
		aimpunch = local->getaimpunchangle();
		viewpunch = local->getviewpunchangle();

		// store current values
		oldaimpunch = *aimpunch;
		oldviewpunch = *viewpunch;
		
		// replace with zeroes
		*aimpunch = Vector(0, 0, 0);
		*viewpunch = Vector(0, 0, 0);
		
		break;
	}
	
	// call original framestagenotify
	hookmngr::org_framestagenotify(thishook, stage);

	// restore original punch values
	if (aimpunch && viewpunch) {
		*aimpunch = oldaimpunch;
		*viewpunch = oldviewpunch;
	}
}