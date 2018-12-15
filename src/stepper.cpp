/*!
 *	@file src/stepper.cpp
 */

#include "stepper.hpp"

#include "Arduino.h"

Stepper::Stepper(unsigned char dir, unsigned char step) {
	// Save pin assignments
	this->dir_pin = dir;
	this->step_pin = step;
	// Set pin mode
	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
}

void Stepper::step() {
	// Check
	if(this->current_step != this->target_step) {
		// Set Direction
		if(this->current_step > this->target_step) {
			digitalWrite(this->dir_pin, LOW);
			this->current_step--;
		} else {
			digitalWrite(this->dir_pin, HIGH);
			this->current_step++;
		}
		// Step
		digitalWrite(this->step_pin, HIGH);
		delay(8);
		digitalWrite(this->step_pin, LOW);
		delay(8);
		// Beep boop
		//Serial.printf("Current: %i Target: %i\n", this->current_step, this->target_step);
	}
}

void Stepper::go_rel(int steps) {
	// Update target
	this->target_step += steps;
	// Check
	while(this->target_step > 600) {
		this->target_step -= 600;
	}
	while(this->target_step < 0) {
		this->target_step += 600;
	}
}

void Stepper::go_abs(int target) {
	// Update target
	this->target_step = target;
	// Check
	while(this->target_step > 600) {
		this->target_step -= 600;
	}
	while(this->target_step < 0) {
		this->target_step += 600;
	}
}
