#pragma once
#include "Module.h"
class AnvilAura : public IModule {
private:
	int obsiheight = 3;
	int fallblockheight = 3;
	bool Bypass = true;
	SettingEnum BlockID = 0;
	bool tryAnvilAura(vec3_t AnvilAura);

public:
	AnvilAura();
	~AnvilAura();

	int range = 10;
	bool multiplace = false;
	bool onClick = false;
	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
};
