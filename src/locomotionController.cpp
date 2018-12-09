/*!
 *	@file include/locomotionController.cpp
 */

#include "locomotionController.hpp"

#include "Arduino.h"
#include "stepper.hpp"

// Default controller
LocomotionController* default_lc;

LocomotionController::LocomotionController() {
	// Create the stepper
	this->turret = new Stepper(STEPPER_STEP_PIN, STEPPER_DIR_PIN);

	// Configure the fans
	pinMode(FAN1_CTL_PIN, OUTPUT);
	//pinMode(FAN2_CTL_PIN, OUTPUT);

	// Save this as the default controller
	if(default_lc == nullptr) {
		default_lc = this;
	}
}

LocomotionController::~LocomotionController() {
	// Destroy the stepper
	delete this->turret;
}

void LocomotionController::update() {
	// Update the turret
	this->turret->step();

	// Get current time
	unsigned long current_time = millis();
	// Update the fans
	if(this->fan1_stop_time < current_time) {
		digitalWrite(FAN1_CTL_PIN, LOW);
	} else {
		digitalWrite(FAN1_CTL_PIN, HIGH);
	}
	if(this->fan2_stop_time < current_time) {
		//digitalWrite(FAN2_CTL_PIN, LOW);
	} else {
		//digitalWrite(FAN2_CTL_PIN, HIGH);
	}
}
