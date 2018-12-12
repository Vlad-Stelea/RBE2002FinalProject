/*
 * Gyro.cpp
 *
 *  Created on: Dec 8, 2018
 *      Author: vlads
 */

#include "Gyro.h"
#include <Adafruit_BNO055.h>

Adafruit_BNO055 bno;

Gyro::Gyro() {
}
void Gyro::setup(){
	  moving = false;
	  /* Initialise the sensor */
	  if(!bno.begin())
	  {
	    /* There was a problem detecting the BNO055 ... check your connections */
	    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
	    //while(1);
	  }

	  delay(1000);

	  bno.setExtCrystalUse(true);
}
double Gyro::getHeading(){
	int zAxisIndex = 0;
	double axis = bno.getVector(Adafruit_BNO055::VECTOR_EULER)[zAxisIndex];
	return axis;
}

void Gyro::startDrive(std::function<void()> noMoveCallback){
	moving = true;
	//stoppedMovingCallback = noMoveCallback;
}

double Gyro::getSpeed(){
	return bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE)[2];
}

double Gyro::getAcceleration(){
	double linAccel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL)[1];
	//Serial.println("Lin Acc " + String(linAccel));
	return linAccel;
}

bool Gyro::stoppedRotating(){
	return getSpeed() == 0;
}

void Gyro::loop(){
	/*speedIntegrator.insertIntegration(getAcceleration());
	//Check if Drivetrain stopped and wont move anymore
	if(moving && stoppedMoving()){
		moving = false;
		//Call the function to do whatever after it is no longer moving
		stoppedMovingCallback();
	}*/
	if(turning && this->stoppedRotating()){
		double heading = getHeading();
		onStopRotating(heading, goalAngle);
	}
}

/*void Gyro::addStopRotatingHandler(std::function<void> onStop, double goal){
	this->onStopRotating = onStop;
	goalAngle = goal;
}*/

bool Gyro::stoppedTurning(){
	double angVel = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE)[0];
	return angVel ==0;
}

Gyro::~Gyro() {
	// TODO Auto-generated destructor stub
}

