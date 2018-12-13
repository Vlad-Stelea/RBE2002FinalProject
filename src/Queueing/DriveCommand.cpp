/*
 * DriveCommand.cpp
 *
 *  Created on: Dec 13, 2018
 *      Author: vlads
 */

#include "DriveCommand.h"

DriveCommand::DriveCommand(double inches, DriveTrain* driveTrain) {
	// TODO Auto-generated constructor stub
	numInches = inches;
	dTrain = driveTrain;
}

bool DriveCommand::isDone(){
	return false;
}

void DriveCommand::loop(){
	dTrain->loop();
}

void DriveCommand::setUpCommand(){
	Serial.println("Driving: " + String(numInches));
	dTrain->driveDistance(numInches);
}

DriveCommand::~DriveCommand() {
	// TODO Auto-generated destructor stub
}

