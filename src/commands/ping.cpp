/*!
 *	@file src/commands/ping.cpp
 */

#include "commands/ping.hpp"

#include <cstdarg>

cmd::Ping::Ping(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {}

cmd::Ping::~Ping() {}

void cmd::Ping::handle(void* data) {

	// Send the response message (a single pong command)
	this->manager->udp.beginPacket( this->manager->udp.remoteIP(),
			this->manager->udp.remotePort());
	const uint8_t reply[] = {0xa1};
	this->manager->udp.write(reply, 1);
	this->manager->udp.endPacket();

}
