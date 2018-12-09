/*!
 *	@file include/commands/robotGo.hpp
 */

#ifndef _COMMANDS_ROBOTGO_H_
#define _COMMANDS_ROBOTGO_H_

#include "commands/commandTemplate.hpp"

namespace cmd {

	class RobotGo : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			RobotGo(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~RobotGo();

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
