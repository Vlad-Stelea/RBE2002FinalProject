/*!
 *	@file include/commandListener.hpp
 */

#include "commandManager.hpp"
#include "commands/ping.hpp"
#include "commands/updateDisplay.hpp"
#include "commands/robotStop.hpp"
#include "commands/robotGo.hpp"
#include "commands/stepperStep.hpp"
#include "commands/runFan.hpp"
#include "commands/motorMove.hpp"

WiFiUDP CommandManager::udp;

CommandManager::CommandManager() {

	// Initialize the UDP socket
	this->udp.begin(UDP_PORT);

	// Initialize the listeners
	this->handlers[0] = new cmd::Ping(this, (uint8_t) 0xa0);
	this->handlers[1] = new cmd::UpdateDisplay(this, (uint8_t) 0xa8);
	this->handlers[2] = new cmd::RobotStop(this, (uint8_t) 0xa7);
	this->handlers[3] = new cmd::RobotGo(this, (uint8_t) 0xa6);
	this->handlers[4] = new cmd::StepperStep(this, (uint8_t) 0xa9);
	this->handlers[5] = new cmd::RunFan(this, (uint8_t) 0xac);
	this->handlers[6] = new cmd::MotorMove(this, (uint8_t) 0xab);

}

void CommandManager::check_mailbox() {

	// Read count
	int read_count = 0;

	// Check if udp data is available
	int packetsize = this->udp.parsePacket();
	if(packetsize > 0) {
		// Read into the buffer
		read_count = this->udp.read(this->buffer, UDP_BUFFER_SIZE);
		Serial.printf("Got command [%02x]\n", this->buffer[0]);
		// Determine the sgnabonbiwiboinqpoiuwbrvoub
		for(int i = 0; i < NUMBER_OF_HANDLERS; i++) {
			// Check the command buffer
			if(this->handlers[i]->id == this->buffer[0]) {
				// Found the handler!  Invoke 'em!
				this->handlers[i]->handle((void*)&this->buffer[0]);
				// We're done here
				return;
			}
		}
		// If we're here, then we couldn't find a command handler.  Drat.
		Serial.printf("Invalid command [code: %02x len: %i]\n", this->buffer[0], read_count);
	}

}
