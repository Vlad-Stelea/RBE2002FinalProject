/*!
 *	@file include/locomotionController.hpp
 */

#ifndef _LOCOMOTIONCONTROLLER_H_
#define _LOCOMOTIONCONTROLLER_H_

#define STEPPER_STEP_PIN 12
#define STEPPER_DIR_PIN 4
#define FAN1_CTL_PIN 18

// Forward declarations
class Stepper;

class LocomotionController {

	public:
		/// Turret stepper
		Stepper* turret = nullptr;

		/// Fan1 stop time
		unsigned long fan1_stop_time = 0;
		/// Fan2 stop time
		unsigned long fan2_stop_time = 0;

		// Drive Motors
		// todo

		// Construct the controller
		LocomotionController();

		// Destroy the controller
		~LocomotionController();

		/*!
		 *	Update the controller.
		 *
		 *	This method updates the state of the stepper motor, drive motors,
		 *	and any other things that make stuff on the motor move.
		 */
		void update();




};

// Default locomotion controller
extern LocomotionController* default_lc;

#endif
