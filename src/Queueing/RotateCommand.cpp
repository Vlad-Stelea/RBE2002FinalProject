/*
 * RotateCommand.cpp
 *
 *  Created on: Dec 13, 2018
 *      Author: vlads
 */

#include "RotateCommand.h"
#include <Arduino.h>

RotateCommand::RotateCommand(double a, DriveTrain *dt) {
	// TODO Auto-generated constructor stub
	dTrain = dt;
	angle = a;
}

bool RotateCommand::isDone(){
	return dTrain->readyForCommand();
}

void RotateCommand::setUpCommand(){
	dTrain->rotateAngle(angle);
}

void RotateCommand::loop(){
	dTrain->loop();
}

RotateCommand::~RotateCommand() {
	// TODO Auto-generated destructor stub
}

