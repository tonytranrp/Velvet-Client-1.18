#pragma once
#include "../ModuleManager.h"
#include "Module.h"

class AutoSneak : public IModule {
public:
	bool silentlol = true;
	std::string name = "AutoSneak";
	virtual void onSendPacket(C_Packet* packet);
	virtual void onPlayerTick(C_Player* plr);
	virtual const char* getModuleName();
	virtual const char* getRawModuleName();
	virtual void onTick(C_GameMode* gm);
	virtual void onDisable();
	virtual void onEnable();
	AutoSneak();
};