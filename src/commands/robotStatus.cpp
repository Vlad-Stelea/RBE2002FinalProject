/*!
 *	@file src/commands/robotStatus.cpp
 */

#include "commands/robotStatus.hpp"

#include <cstdarg>

cmd::RobotStatus::RobotStatus(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {}

cmd::RobotStatus::~RobotStatus() {}

void cmd::RobotStatus::send(int32_t drive_ticks_l, int32_t setpoint_l,
		int32_t drive_ticks_r, int32_t setpoint_r,
		int32_t turret_ticks, int32_t turret_setpoint) {

	// Create the structure
	msg_rstatus msg;
	msg.cmd = this->id;
	msg.drive_ticks_l = drive_ticks_l;
	msg.setpoint_l = setpoint_l;
	msg.drive_ticks_r = drive_ticks_r;
	msg.setpoint_r = setpoint_r;
	msg.turret_ticks = turret_ticks;
	msg.turret_setpoint = turret_setpoint;

	// Send the message across the intertubes
	this->manager->udp.beginPacket( this->manager->udp.remoteIP(),
				this->manager->udp.remotePort());
	this->manager->udp.write((uint8_t*)&msg, sizeof(msg_rstatus));
	this->manager->udp.endPacket();

}

void cmd::RobotStatus::handle(void* data) {

	// Robot status commands are not received by the client

}
