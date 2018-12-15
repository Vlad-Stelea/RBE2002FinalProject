/*
 * BlowFireCommand.cpp
 *
 *  Created on: Dec 14, 2018
 *      Author: vlads
 */

#include "BlowFireCommand.h"

BlowFireCommand::BlowFireCommand(FireDestroyer * fd, FireTracker* ft) {
	// TODO Auto-generated constructor stub
	fD = fd;
	this->ft = ft;
}

bool BlowFireCommand::isDone(){
	return false;
}

void BlowFireCommand::setUpCommand(){
	Serial.println("BEGINNIG EXTINGUGSHIMT NOW");
	delay(1000);
	bool foundfire = false;
	fD->tiltToAngle(120);
	// Check for fire
	for(int i = 0; i < 0; i++) {
		Serial.println(i);
		// Get fire
		delay(250);
		FireTracker::FireLoc fl = this->ft->getFireCoords();
		// Check
		if(fl.x < 1023 && fl.y < 1023) {
			// Found fire
			foundfire = true;
			//break;
		} else {
			this->fD->stepper.go_rel(20);
			for(int asdf = 0; asdf < 400; asdf++) {
				this->fD->stepper.step();
			}
		}
	}
	if(!foundfire) {
		// Didn't find the fire at this location
		//return;
	}
	Serial.println("========== FOUND THE FIRE ==========");
	// Rotate 180 degrees
	this->fD->stepper.go_rel(300);
	for(int asdf = 0; asdf < 305; asdf++) {
		this->fD->stepper.step();
	}
	fD->tiltToAngle(90);
	fD->turnOnFan();
	delay(100000);

}

void BlowFireCommand::loop(){

}

BlowFireCommand::~BlowFireCommand() {
	// TODO Auto-generated destructor stub
}

