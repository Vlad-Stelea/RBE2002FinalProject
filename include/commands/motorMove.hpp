/*!
 *	@file include/commands/motorMove.hpp
 */

#ifndef _COMMANDS_MOTORMOVE_H_
#define _COMMANDS_MOTORMOVE_H_

#include "commands/commandTemplate.hpp"

namespace cmd {

	struct __attribute__((__packed__)) msg_motormove {
		uint8_t cmd;
		uint8_t speed_l;
		int16_t ticks_l;
		uint8_t speed_r;
		int16_t ticks_r;
	};

	class MotorMove : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			MotorMove(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~MotorMove();

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
