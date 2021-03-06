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
	return 1000*(arcLength/circumference);
}

void DriveTrain::rotateAngle(double angle){
	resetEncs();
	leftMotor.SetTunings(turningKP,turningKI,turningKD);
	rightMotor.SetTunings(turningKP, turningKI, turningKD);
	turning = true;
	ready = false;
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
}

void DriveTrain::drive(int leftSpeed, int rightSpeed){
	ready = false;
	//Serial.printf("(%d,%d)",leftSpeed, rightSpeed);
	leftMotor.setSetpoint(leftSpeed);
	rightMotor.setSetpoint(rightSpeed);
}

void DriveTrain::loop(){
	if(driving){
		Serial.println();
		int leftDiff = abs(leftMotor.getPosition() - leftMotor.getSetPoint());
		int rightDiff = abs(rightMotor.getPosition() - rightMotor.getSetPoint());
		if(leftDiff < drivingThreshold && rightDiff < drivingThreshold){
			driving = false;
			ready = true;
			leftMotor.setOutput(0);
			rightMotor.setOutput(0);
			return;
		}
		Serial.printf("(%lld, %lld), Wanted(%lf,%lf)\n", leftMotor.getPosition(), rightMotor.getPosition(), leftMotor.getSetPoint(), rightMotor.getSetPoint());
		leftMotor.loop();
		rightMotor.loop();
		//The motors have not been moving
		/*if(allItemsSame(prevEncVals)){
			leftMotor.setOutput(0);
			rightMotor.setOutput(0);
			driving = false;
			//ready = true;
			return;
		}*/
	}else if(turning){
		Serial.printf("Goal: %lf, current: %lf\n", turningGoal, gyro.getHeading());
		if(abs(gyro.getHeading()-turningGoal) < turningThreshold){
			//Stop the motors
			leftMotor.setOutput(0);
			rightMotor.setOutput(0);
			//Set turning to false
			turning = false;
			ready = true;
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
	resetEncs();
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

bool DriveTrain::allItemsSame(struct encoderHolder *prevVals){
	for(int i = 1; i < numEncVals; i++){
		struct encoderHolder prev = prevVals[i-1];
		struct encoderHolder cur = prevVals[i];
		if(prev.left != cur.left || prev.right != cur.right){
			return false;
		}
	}
	return true;
}

void DriveTrain::addEncHolder(struct encoderHolder *prevVals, struct encoderHolder newVal){
	currentIdx +=1;
	if(currentIdx > numEncVals){
		currentIdx = 0;
	}
	prevVals[currentIdx] = newVal;

}

void DriveTrain::resetEncs(){
	leftMotor.overrideCurrentPosition(0);
	rightMotor.overrideCurrentPosition(0);
}

bool DriveTrain::readyForCommand(){
	return ready;
}

DriveTrain::~DriveTrain() {
	// TODO Auto-generated destructor stub
}

