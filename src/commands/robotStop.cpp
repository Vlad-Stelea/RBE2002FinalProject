/*!
 *	@file src/commands/robotStop.cpp
 */

#include "commands/robotStop.hpp"

#include <cstdarg>

cmd::RobotStop::RobotStop(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {}

cmd::RobotStop::~RobotStop() {}

void cmd::RobotStop::handle(void* data) {

	// Stop! You have violated the Law!
	// Pay the court a fine or serve your sentence.
	// Your stolen goods are now forfeit

	Serial.printf("EMERGENCY STOP!\n");

}
