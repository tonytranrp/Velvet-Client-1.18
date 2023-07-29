#pragma once

#include "../ModuleManager.h"
#include "Module.h"

class HoleFiller : public IModule {
private:
	bool obsidian = true;
	bool bedrock = true;
	bool onclick = false;
	SettingEnum mode = this;

public:
	int range = 5;

	bool tryHoleFiller(vec3_ti blkPlacement);
	bool canpla(vec3_ti blockPos);

	HoleFiller();
	~HoleFiller();
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
};