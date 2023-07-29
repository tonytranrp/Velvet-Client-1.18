
#include "AutoSneak.h"
#include <Windows.h>
#include "../../../Utils/Logger.h"
#include "../../../Utils/Utils.h"

AutoSneak::AutoSneak() : IModule(0, Category::MOVEMENT, "Automatically AutoSneaks") {
	registerBoolSetting("Silent", &silentlol, silentlol);
}

const char* AutoSneak::getRawModuleName() {
	return "AutoSneak";
}

const char* AutoSneak::getModuleName() {
	if (!silentlol) {
		name = std::string("AutoSneak ") + std::string(BLUE) + std::string("[") + std::string(RED) + std::string("Normal") + std::string(BLUE) + std::string("]");
	} else {
		name = std::string("AutoSneak ") + std::string(BLUE) + std::string("[") + std::string(RED) + std::string("Silent") + std::string(BLUE) + std::string("]");
	}
	return name.c_str();
}

void AutoSneak::onTick(C_GameMode* gm) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;
	g_Data.getClientInstance()->getMoveTurnInput()->isSneakDown = true;
}

void AutoSneak::onEnable() {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;
}
uint8_t* AutoSneakopcode = 0;
void AutoSneak::onPlayerTick(C_Player* plr) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;
	if (silentlol) {
		if (AutoSneakopcode == 0) {
			AutoSneakopcode = reinterpret_cast<uint8_t*>(FindSignature("80 7B 48 00 74 2E 48 8B 07 48 8B CF"));
		}
		DWORD oldProtect = 0;
		if (!VirtualProtect(AutoSneakopcode, 5, PAGE_EXECUTE_READWRITE, &oldProtect)) {
		} else {
			AutoSneakopcode[0] = 0x90;
			AutoSneakopcode[1] = 0x90;
			AutoSneakopcode[2] = 0x90;
			AutoSneakopcode[3] = 0x90;
			VirtualProtect(AutoSneakopcode, 5, oldProtect, &oldProtect);
		}
	}
}
void AutoSneak::onSendPacket(C_Packet* packet) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;
}

void AutoSneak::onDisable() {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;
	g_Data.getClientInstance()->getMoveTurnInput()->isSneakDown = false;
	DWORD oldProtect = 0;
	if (VirtualProtect(AutoSneakopcode, 5, PAGE_EXECUTE_READWRITE, &oldProtect)) {
		AutoSneakopcode[0] = 0x80;
		AutoSneakopcode[1] = 0x7B;
		AutoSneakopcode[2] = 0x48;
		AutoSneakopcode[3] = 0x00;
		VirtualProtect(AutoSneakopcode, 5, oldProtect, &oldProtect);
	}
}