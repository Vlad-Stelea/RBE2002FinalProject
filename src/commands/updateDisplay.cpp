/*!
 *	@file src/commands/updateDisplay.cpp
 */

#include "commands/updateDisplay.hpp"

#include <cstdarg>

cmd::UpdateDisplay::UpdateDisplay(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {}

cmd::UpdateDisplay::~UpdateDisplay() {}


void cmd::UpdateDisplay::handle(void* data) {

	// Get the strings
	msg_disptext* msg = (msg_disptext*)data;

	// Add the null terminators
	char tline1[17];
	char tline2[17];
	tline1[16] = '\0';
	tline2[16] = '\0';
	memcpy(tline1, msg->line1, 16);
	memcpy(tline2, msg->line2, 16);
	// Remove any extra null terminators
	for(int i = 0; i < 16; i ++) {
		if(tline1[i] == '\0') {
			tline1[i] = ' ';
		}
		if(tline2[i] == '\0') {
			tline2[i] = ' ';
		}
	}

	// DEBUG - Print the message
	Serial.printf("Updated display:\n[%s]\n[%s]\n", tline1, tline2);

}
