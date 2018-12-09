/*
 * Messages.h
 *
 *  Created on: 10/1/16
 *      Author: joest
 */
#include "Arduino.h"
#include "RBEPID.h"
#include "String.h"
//Class constructor
RBEPID::RBEPID() {
	kp = .2;
	ki = .1;
	kd = .2;
}

//Function to set PID gain values
void RBEPID::setpid(float P, float I, float D) {
	kp = P;
	ki = I;
	kd = D;
}


double prevError = 0;
double runningAverage = 0;
int numIntegrals = 0;
/**
 * @param setVel the velocity that we want
 * @param curVel the current velocity of the motor
 */
float RBEPID::calc(double setVel, double curVel) {
	double t = 1;
	// calculate error
	double err = setVel - curVel;
	double P = kp*err;
	// calculate derivative of error
	double D = kd*(prevError-err)/t;
	// calculate integral error. Running average is best but hard to implement
	//runningAverage = (runningAverage*numIntegrals)+err;
	if(numIntegrals == 0){
		runningAverage = err;
		numIntegrals++;
	}else{
		runningAverage = ((runningAverage*numIntegrals)+err);
		numIntegrals++;
		runningAverage = runningAverage/(numIntegrals);
	}
	double I = ki*(runningAverage);
	// sum up the error value to send to the motor based off gain values.
	float controlValue = (P + I + D);
	Serial.println("P " + String(P) + " I " + String(I) + " D " + String(D));
	// limit control value to 0-254
	float controlSignal = controlValue;
	if(controlSignal < 0)
		controlSignal = 0;
	else if(controlSignal > 254)
		controlSignal = 254;
	//return the control signal
	return controlSignal;
}
