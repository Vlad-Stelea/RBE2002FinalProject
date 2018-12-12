/*
 * Fan.cpp
 *
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#include "Fan.h"
#include <Arduino.h>

Fan::Fan() {
	// TODO Auto-generated constructor stub

}

void Fan::setup(int p){
	port = p;
	pinMode(p, OUTPUT);
}

void Fan::turnOn(){
	digitalWrite(port, HIGH);
}

void Fan::turnOff(){
	digitalWrite(port, LOW);
}

Fan::~Fan() {
	// TODO Auto-generated destructor stub
}

