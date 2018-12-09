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
	  /* Initialise the sensor */
	  if(!bno.begin())
	  {
	    /* There was a problem detecting the BNO055 ... check your connections */
	    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
	    while(1);
	  }

	  delay(1000);

	  bno.setExtCrystalUse(true);
}
double Gyro::getHeading(){
	int zAxisIndex = 0;
	double axis = bno.getVector(Adafruit_BNO055::VECTOR_EULER)[zAxisIndex];
	return axis;
}

Gyro::~Gyro() {
	// TODO Auto-generated destructor stub
}

