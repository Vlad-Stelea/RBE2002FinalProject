/*!
 *	@file src/commands/robotGo.cpp
 */

#include "commands/robotGo.hpp"

#include <cstdarg>

cmd::RobotGo::RobotGo(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {}

cmd::RobotGo::~RobotGo() {}

void cmd::RobotGo::handle(void* data) {

	Serial.printf("EMERGENCY GO!\n");

}
