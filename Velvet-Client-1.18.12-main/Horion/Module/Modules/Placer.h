#pragma once
#include "../ModuleManager.h"
#include "Module.h"

class Placer : public IModule {
private:
	int Odelay = 0;
	int delay = 0;

public:
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
	Placer();
};