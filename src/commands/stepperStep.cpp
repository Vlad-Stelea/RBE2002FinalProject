/*!
 *	@file src/commands/stepperStep.cpp
 */

#include "commands/stepperStep.hpp"

#include "locomotionController.hpp"

#include <cstdarg>

cmd::StepperStep::StepperStep(CommandManager* manager, uint8_t id) : CommandTemplate(manager, id) {}

cmd::StepperStep::~StepperStep() {}

void cmd::StepperStep::handle(void* data) {

	// Get the stepper steps
	msg_stepperstep* msg = (msg_stepperstep*)data;

	// TODO: Tell the stepper to step to the step of the steppity step help I can't sleep
	Serial.printf("Stepping the stepper %i steps!\n", msg->steps);

	default_lc->turret->go_rel(msg->steps);

}
