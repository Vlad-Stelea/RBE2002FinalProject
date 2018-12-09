/*!
 *	@file include/commands/updateDisplay.hpp
 */

#ifndef _COMMANDS_UPDATEDISPLAY_H_
#define _COMMANDS_UPDATEDISPLAY_H_

#include "commands/commandTemplate.hpp"

namespace cmd {

	struct __attribute__((__packed__)) msg_disptext {
		uint8_t cmd;
		char line1[16];
		char line2[16];
	};

	class UpdateDisplay : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			UpdateDisplay(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~UpdateDisplay();

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
