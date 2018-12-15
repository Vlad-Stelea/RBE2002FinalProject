/*
 * FireDestroyer.h
 * The fire destroyer is the entire system that the fan is on including the pan and tilt mechanism
 * Responsible for detecting where the fire is relative to the robot and tilting the tilter to match that
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#ifndef SRC_SUBSYSTEMS_FIREDESTROYER_H_
#define SRC_SUBSYSTEMS_FIREDESTROYER_H_
#include "../Components/Fan.h"
#include <ESP32Servo.h>
#include "stepper.hpp"

class FireDestroyer {
public:
	FireDestroyer();
	void setup(int servoPort, int fanPort);
	void tiltToAngle(int angle);
	void turnOnFan();
	virtual ~FireDestroyer();

public:
	Fan fan;
	Servo tilter;
	Stepper stepper;

};

#endif /* SRC_SUBSYSTEMS_FIREDESTROYER_H_ */
