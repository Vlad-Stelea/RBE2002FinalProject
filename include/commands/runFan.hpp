/*!
 *	@file include/commands/runFan.hpp
 */

#ifndef _COMMANDS_RUNFAN_H_
#define _COMMANDS_RUNFAN_H_

#include "commands/commandTemplate.hpp"

namespace cmd {

	struct __attribute__((__packed__)) msg_runfan {
		uint8_t cmd;
		uint16_t duration;
	};

	class RunFan : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			RunFan(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~RunFan();

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
