/*!
 *	@file include/commands/ping.hpp
 */

#ifndef _COMMANDS_PING_H_
#define _COMMANDS_PING_H_

#include "commands/commandTemplate.hpp"

namespace cmd {

	class Ping : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			Ping(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~Ping();

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
