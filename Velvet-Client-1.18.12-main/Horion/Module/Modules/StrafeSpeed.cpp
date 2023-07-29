#include "StrafeSpeed.h"

StrafeSpeed::StrafeSpeed() : IModule(0x0, Category::MOVEMENT, "FastStop Strafe skid cuz im lazy :tony") {
	
}

StrafeSpeed::~StrafeSpeed() {
}

const char* StrafeSpeed::getModuleName() {
	return ("FastStop");
}

void StrafeSpeed::onMove(C_MoveInputHandler* input) {
	auto player = g_Data.getLocalPlayer();
	if (player == nullptr) return;
	if ((player->isInLava() || player->isInWater())) return;


	vec2_t moveVec2d = {input->forwardMovement, -input->sideMovement};
	bool pressed = moveVec2d.magnitude() > 0.01f;
	vec3_t moveVec;
	
	
	if (!pressed) {
		player->velocity.x = 0;
		player->velocity.z = 0;
	}
}
