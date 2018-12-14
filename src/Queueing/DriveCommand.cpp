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
	bool done = dTrain->readyForCommand();
	if(done){
		delay(2000);
	}
	return dTrain->readyForCommand();
}

void DriveCommand::loop(){
	dTrain->loop();
}

void DriveCommand::setUpCommand(){
	dTrain->driveDistance(numInches);
}

DriveCommand::~DriveCommand() {
	// TODO Auto-generated destructor stub
}

