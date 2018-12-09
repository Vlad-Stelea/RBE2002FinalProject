/*!
 *	@file include/commands/stepperStep.hpp
 */

#ifndef _COMMANDS_STEPPERSTEP_H_
#define _COMMANDS_STEPPERSTEP_H_

#include "commands/commandTemplate.hpp"

#include "stepper.hpp"

namespace cmd {

	struct __attribute__((__packed__)) msg_stepperstep {
		uint8_t cmd;
		uint32_t steps;
	};

	class StepperStep : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			StepperStep(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~StepperStep();

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
