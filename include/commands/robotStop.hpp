/*!
 *	@file include/commands/robotStop.hpp
 */

#ifndef _COMMANDS_ROBOTSTOP_H_
#define _COMMANDS_ROBOTSTOP_H_

#include "commands/commandTemplate.hpp"

namespace cmd {

	class RobotStop : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			RobotStop(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~RobotStop();

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
