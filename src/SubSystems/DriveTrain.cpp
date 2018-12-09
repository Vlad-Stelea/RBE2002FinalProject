/*
 * DriveTrain.cpp
 *
 *  Created on: Dec 8, 2018
 *      Author: vlads
 */

#include "DriveTrain.h"
#include <Arduino.h>

DriveTrain::DriveTrain() {
	// TODO Auto-generated constructor stub

}

void DriveTrain::setup(){
	pinMode(leftDirPin, OUTPUT);
	pinMode(rightDirPin,OUTPUT);
	pinMode(leftEncPinA, INPUT_PULLDOWN);
	pinMode(leftEncPinB, INPUT_PULLDOWN);
	pinMode(rightEncPinA, INPUT_PULLDOWN);
	pinMode(rightEncPinA, INPUT_PULLDOWN);
	leftMotor.attach(leftServPin, leftDirPin,leftEncPinA,leftEncPinB);
	leftMotor.SetTunings(.1,0,0);
	rightMotor.attach(rightServPin, rightDirPin,rightEncPinA, rightEncPinB);
	rightMotor.SetTunings(1,0,0);
}
void DriveTrain::rotateAngle(int angle){
	const int MAX_SPEED = 10;
	//Create the goal angle that the robot should stop turning at
	int headingDiff = gyro.getHeading()-angle;
	while(abs(headingDiff) > turningLeeway){
		if(headingDiff>0){
			rotateRobot(-headingDiff*turningKP);
		}else if(headingDiff<0){
			rotateRobot(headingDiff*turningKP);
		}
		headingDiff = gyro.getHeading()-angle;
	}

}

void DriveTrain::drive(int leftSpeed, int rightSpeed){
	//Set the proper direction for the motors
	/*if(leftSpeed < 0){
		digitalWrite(leftDirPin,LOW);
	}else{
		digitalWrite(leftDirPin, HIGH);
	}
	if(rightSpeed < 0){
		digitalWrite(rightDirPin,LOW);
	}else{
		digitalWrite(rightDirPin, HIGH);
	}

	leftMotor.setSetpoint(abs(leftSpeed));
	rightMotor.setSetpoint(abs(rightSpeed));*/
	leftMotor.setSetpoint(leftSpeed);
	rightMotor.setSetpoint(rightSpeed);
}

void DriveTrain::loop(){
	Serial.printf("(%lld, %lld)\n", leftMotor.getPosition(), rightMotor.getPosition());
	leftMotor.loop();
	rightMotor.loop();
}

void DriveTrain::rotateRobot(int speed){
	int leftSpeed = speed, rightSpeed = speed;
	if(speed < 0){
		leftSpeed = -leftSpeed;
	}else{
		rightSpeed = -rightSpeed;
	}
	drive(leftSpeed,rightSpeed);
}

DriveTrain::~DriveTrain() {
	// TODO Auto-generated destructor stub
}

