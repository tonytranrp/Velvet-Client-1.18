
#include "Placer.h"

Placer::Placer() : IModule(0, Category::PLAYER, "Changes the block placing delay") {
	registerIntSetting("Delay", &delay, delay, 0, 10);
}

const char* Placer::getModuleName() {
	return ("Placer");
}

void Placer::onTick(C_GameMode* gm) {
	auto player = g_Data.getLocalPlayer();
	
	
	

	if (g_Data.isRightClickDown() && g_Data.canUseMoveKeys()) {
		Odelay++;
		if (Odelay >= delay) {
			g_Data.rightclickCount++;
			
		}
		Odelay = 0;
	}
}