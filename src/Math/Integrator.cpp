/*
 * Integrator.cpp
 *
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#include "../Math/Integrator.h"

#include <Arduino.h>

Integrator::Integrator() {
	// TODO Auto-generated constructor stub
	previousX = 0;
	previousTime = -1;
}

double Integrator::insertIntegration(double x){
	long long curTime = esp_timer_get_time();
	//Check for first time
	if(previousTime == -1){
		previousTime = curTime;
		previousX = x;
		return 0;
	}else{
		double xDiff = x - previousX;
		long long timeDiff = curTime - previousTime;
		double constant = xDiff/timeDiff;
		return previousX + x*constant;
	}
}

double Integrator::getIntegratedValue(){
	return previousX;
}

Integrator::~Integrator() {
	// TODO Auto-generated destructor stub
}

