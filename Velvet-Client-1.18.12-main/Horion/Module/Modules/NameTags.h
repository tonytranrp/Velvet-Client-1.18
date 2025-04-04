



#pragma once
#include "../../../Utils/Target.h"
#include "../ModuleManager.h"
#include "../../DrawUtils.h"
#include "Module.h"
#include <set>

class NameTags : public IModule {
public:
	std::set<std::string> nameTags;
	bool displayArmor = true;
	bool underline = true;
	float scalen = 0.6f;
	int opacity = 150;

	bool* ingameNametagSetting = nullptr;
	bool gotPrevSetting = false;
	bool lastSetting = true;

	virtual void onPreRender(C_MinecraftUIRenderContext* renderCtx);
	virtual const char* getModuleName();
	virtual void onDisable();
	NameTags();
};
