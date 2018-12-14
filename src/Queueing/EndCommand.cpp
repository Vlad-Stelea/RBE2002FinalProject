/*
 * EndCommand.cpp
 *
 *  Created on: Dec 14, 2018
 *      Author: vlads
 */

#include "EndCommand.h"
#include <Arduino.h>

EndCommand::EndCommand() {
	// TODO Auto-generated constructor stub

}

bool EndCommand::isDone(){
	return false;
}

void EndCommand::setUpCommand(){
	//DO nothing
}

void EndCommand::loop(){
	Serial.println("FIN");
	while(1);
}

EndCommand::~EndCommand() {
	// TODO Auto-generated destructor stub
}

