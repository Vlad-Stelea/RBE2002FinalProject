/*!
 *	@file include/commands/robotStatus.hpp
 */

#ifndef _COMMANDS_ROBOTSTATUS_H_
#define _COMMANDS_ROBOTSTATUS_H_

#include "commands/commandTemplate.hpp"

namespace cmd {

	/*!
	 *	Robot status message structure.
	 *
	 *	This structure contains all of the attributes that are needed to
	 *	create and send a complete robot status update command.
	 */
	struct __attribute__((__packed__)) msg_rstatus {
		uint8_t cmd;
		int32_t drive_ticks_l;
		int32_t setpoint_l;
		int32_t drive_ticks_r;
		int32_t setpoint_r;
		int32_t turret_ticks;
		int32_t turret_setpoint;
	};

	class RobotStatus : public cmd::CommandTemplate {

		public:

			/*!
			 *	@see CommandTemplate::CommandTemplate()
			 */
			RobotStatus(CommandManager* manager, uint8_t id);

			/*!
			 *	@see CommandTemplate::~CommandTemplate()
			 */
			~RobotStatus();

			/*!
			 * 	@see CommandTemplate::send()
			 */
			void send(int32_t drive_ticks_l, int32_t setpoint_l,
					int32_t drive_ticks_r, int32_t setpoint_r,
					int32_t turret_ticks, int32_t turret_setpoint);

			/*!
			 *	@see CommandTemplate::handle()
			 */
			void handle(void* data);

	};

}

#endif
