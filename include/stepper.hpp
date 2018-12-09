/*!
 *	@file include/stepper.hpp
 */

#ifndef _STEPPER_H_
#define _STEPPER_H_

class Stepper {

	private:

		/// Direction pin
		unsigned char dir_pin;

		/// Step pin
		unsigned char step_pin;

		/// Current Step
		int current_step = 180;

		/// Target Step
		int target_step = 180;

	public:

		/*!
	 	 *	Construct a Stepper Controller.
	 	 *
	 	 *	@param dir	Direction pin
	 	 *	@param step	Step pin
		 */
		Stepper(unsigned char dir, unsigned char step);

		/*!
		 *	Step.
		 *
		 *	If current_step is not equal to target_step, the direction pin will
		 *	be set appropriately and a pulse will be sent to the stepper.  This
		 *	method only steps one time per loop.
		 */
		void step();

		/*!
		 *	Rotate Relative.
		 *
		 *	Updates the stepper target.  If the target tries to spin more than
		 *	one full rotation, the target will be updated to prevent that.
		 *
		 *	@param steps Number of steps.
		 */
		void go_rel(int steps);

		/*!
		 *	Rotate Absolute.
		 *
		 *	Updates the steppter target.  If the target tries to spin more than
		 *	one full rotation, the target will be updated to prevent that.
		 *
		 *	@param target	New Target.
		 */
		void go_abs(int target);

};

#endif
