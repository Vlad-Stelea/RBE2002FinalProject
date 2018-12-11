/*
 * DistanceSensor.cpp
 *
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#include "DistanceSensor.h"
#include <Arduino.h>

DistanceSensor::DistanceSensor() {
	// TODO Auto-generated constructor stub
}

void DistanceSensor::setUp(int p){
	port = p;
}
//TODO
bool DistanceSensor::getThreshold(){
	int readValue = analogRead(port);
	return readValue < distanceThreshold;
}

DistanceSensor::~DistanceSensor() {
	// TODO Auto-generated destructor stub
}

