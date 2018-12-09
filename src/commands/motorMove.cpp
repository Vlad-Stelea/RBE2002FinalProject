/*!
 *	@file src/commands/motorMove.cpp
 */

#include "commands/motorMove.hpp"

#include <cstdarg>

cmd::MotorMove::MotorMove(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {}

cmd::MotorMove::~MotorMove() {}


void cmd::MotorMove::handle(void* data) {

	// Get the strings
	msg_motormove* msg = (msg_motormove*)data;

	// Get the speed and ticks 'n stuff

	// TODO: Actually do literally anything with this info
	Serial.printf("Moving Left: [%i@%i] Right: [%i@%i]\n",
			msg->ticks_l, msg->speed_l, msg->ticks_r, msg->speed_r);

}
