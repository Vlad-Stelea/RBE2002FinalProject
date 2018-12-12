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

void DriveTrain::setup(Gyro *g){
	gyro = *g;
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

long long DriveTrain::convertTurnAngleToTicks(double degrees){
	double arcDegree = degrees/360;
	double arcLength = arcDegree*WHEEL_BASE_CIRCUMFERENCE;
	return 4000*(arcLength/circumference);
}

void DriveTrain::rotateAngle(double angle){
	leftMotor.SetTunings(turningKP,turningKI,turningKD);
	rightMotor.SetTunings(turningKP, turningKI, turningKD);
	/*const int MAX_SPEED = 10;
	//Create the goal angle that the robot should stop turning at
	int headingDiff = gyro.getHeading()-angle;
	while(abs(headingDiff) > turningLeeway){
		if(headingDiff>0){
			rotateRobot(-headingDiff*turningKP);
		}else if(headingDiff<0){
			rotateRobot(headingDiff*turningKP);
		}
		headingDiff = gyro.getHeading()-angle;
	}*/
	turning = true;
		turningGoal = angle+gyro.getHeading();
		if(turningGoal > 360){
			turningGoal = 360-angle;
		}else if(turningGoal < 0){
			turningGoal = 360+turningGoal;
		}
	long long numRotations = convertTurnAngleToTicks(angle);
	long long leftRot, rightRot;
	if(angle < 0){
		leftRot = numRotations;
		rightRot = numRotations;
	}else{
		leftRot = -numRotations;
		rightRot = -numRotations;
	}
	drive(leftRot, rightRot);
	//gyro.addStopRotatingHandler(DriveTrain::rotationCallback, turningGoal);
	//gyro.addStopRotatingHandler(()->{}, turningGoal);
	/*Serial.println("GYRO: " + String(gyro.getHeading()));
	turning = true;
	turningGoal = angle+gyro.getHeading();
	if(turningGoal > 360){
		turningGoal = 360-angle;
	}else if(turningGoal < 0){
		turningGoal = 360+turningGoal;
	}
	Serial.println("GYRO: " + String(turningGoal));
	//while(1);*/
}

void DriveTrain::drive(int leftSpeed, int rightSpeed){
	driving = true;
	//Serial.printf("(%d,%d)",leftSpeed, rightSpeed);
	leftMotor.setSetpoint(leftSpeed);
	rightMotor.setSetpoint(rightSpeed);
}

void DriveTrain::loop(){

	if(driving){
		//Serial.printf("(%lld, %lld)\n", leftMotor.getPosition(), rightMotor.getPosition());
		leftMotor.loop();
		rightMotor.loop();
	}else if(turning){
		if(gyro.stoppedRotating()){
			rotationCallback(this);
			return;
		}

		double diff = gyro.getHeading() - turningGoal;
		if(abs(diff) < turningThreshold){
			setOutputs(0,0);
			turning = false;
			return;
		}
		int output = turningKP*diff;
		if(abs(output) < minValue){
			output = minValue;
		}
		//Determine which way to spin
		if(diff< 0){
			output = -output;
		}
		setOutputs(output,output);
	}
	//tracker.loop();
}

void DriveTrain::setOutputs(int left, int right){
	leftMotor.setOutput(left);
	rightMotor.setOutput(right);
}


void DriveTrain::rotateRobot(int speed){
	int leftSpeed = speed, rightSpeed = speed;
	if(speed > 0){
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
	long long goal = fullTicks*(inches/circumference);
	return goal;
}


void DriveTrain::driveDistance(double inches){
	leftMotor.SetTunings(leftKP,leftKI, leftKD);
	rightMotor.SetTunings(rightKP, rightKI, rightKD);
	driving = true;
	long long numTicks = convertInchesToTicks(inches);
	long long leftGoal = leftMotor.getPosition() + numTicks;
	long long rightGoal = rightMotor.getPosition() + numTicks;
	drive(-leftGoal, rightGoal);
}

void DriveTrain::rotationCallback(DriveTrain * dTrain){
	//Stop the motors
	dTrain->leftMotor.setOutput(0);
	dTrain->rightMotor.setOutput(0);
	//Set turning to false
	dTrain->turning = false;

}

DriveTrain::~DriveTrain() {
	// TODO Auto-generated destructor stub
}

