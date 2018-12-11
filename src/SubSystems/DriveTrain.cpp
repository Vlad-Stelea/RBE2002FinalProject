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
	leftMotor.SetTunings(leftKP,leftKI,leftKD);
	rightMotor.attach(rightServPin, rightDirPin,rightEncPinA, rightEncPinB);
	rightMotor.SetTunings(rightKP,rightKI,rightKD);
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
	driving = true;
	leftMotor.setSetpoint(leftSpeed);
	rightMotor.setSetpoint(rightSpeed);
}

void DriveTrain::loop(){
	if(driving){
		//Serial.printf("(%lld, %lld)\n", leftMotor.getPosition(), rightMotor.getPosition());
		leftMotor.loop();
		rightMotor.loop();
	}
	//tracker.loop();
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

void DriveTrain::lineUpFire(){

}


/**
 * Convert inches to travel to the proper number of encoder ticks
 * @param inches the number of inches to drive
 */
long long DriveTrain::convertInchesToTicks(double inches){
	//3200 ticks per full rotation
	int fullTicks = 4200;
	//wheel diameter 3 in
	Serial.println("TEST: " + String(circumference));
	long long goal = fullTicks*(inches/circumference);
	return goal;
}


void DriveTrain::driveDistance(double inches){
	driving = true;
	long long numTicks = convertInchesToTicks(inches);
	Serial.printf("Fuck: %lf, %lld \n", inches, numTicks);
	long long leftGoal = leftMotor.getPosition() + numTicks;
	long long rightGoal = rightMotor.getPosition() + numTicks;
	Serial.printf("(%lld,%lld)\n", leftGoal, rightGoal);
	drive(-leftGoal, rightGoal);
}



DriveTrain::~DriveTrain() {
	// TODO Auto-generated destructor stub
}

