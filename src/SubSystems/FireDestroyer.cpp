/*
 * FireDestroyer.cpp
 *
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#include "FireDestroyer.h"

FireDestroyer::FireDestroyer() {
	// TODO Auto-generated constructor stub

}

void FireDestroyer::setup(int servoPort, int fanPort){
	tilter.attach(servoPort);
	fan.setup(fanPort);
}

void FireDestroyer::tiltToAngle(int degrees){
	tilter.write(degrees);
	tilter.read();
}

void FireDestroyer::turnOnFan(){
	fan.turnOn();
}

FireDestroyer::~FireDestroyer() {
	// TODO Auto-generated destructor stub
}

