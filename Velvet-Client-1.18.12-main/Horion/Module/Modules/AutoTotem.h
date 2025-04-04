#pragma once
#include "../ModuleManager.h"
#include "Module.h"

class AutoTotem : public IModule {
public:
	SettingEnum cc = 0;

	virtual void onDisable();
	virtual void onEnable();
	virtual const char* getModuleName();
	virtual void onTick(C_GameMode* gm);
	AutoTotem();
};