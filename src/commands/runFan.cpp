/*!
 *	@file src/commands/runFan.cpp
 */

#include "commands/runFan.hpp"

#include <cstdarg>

#include "locomotionController.hpp"

#define PIN 18

cmd::RunFan::RunFan(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {
	pinMode(18, OUTPUT);
}

cmd::RunFan::~RunFan() {}

void cmd::RunFan::handle(void* data) {

	// Get the fan run duration
	msg_runfan* msg = (msg_runfan*)data;

	// TODO: Start some sort of timer thing that'll run the fan for the time
	Serial.printf("Running fan for %ums\n", msg->duration);

	default_lc->fan1_stop_time = millis() + msg->duration;

}
