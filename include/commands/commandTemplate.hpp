/*!
 *	@file include/commands/commandTemplate.hpp
 */

#ifndef _COMMAND_TEMPLATE_H_
#define _COMMAND_TEMPLATE_H_

#include "commandManager.hpp"
#include <cstdint>


// Forward declaration
class CommandManager;

namespace cmd {

	class CommandTemplate {

		protected:

			/*!
			 *	Send data across the neetwark.
			 *
			 *	This command serves as a wrapper for whatever packet transfer
			 *	system the application is using.
			 *
			 *	@param data		Pointer to data transmission buffer.
			 *	@param length	Length of data transmission buffer.
			 */
			void send_data(uint8_t* data, unsigned int length);

		public:

			/*!
			 *	Command ID.
			 *
			 *	This unique byte is used to identify the packet when it is
			 *	transmitted across the network.
			 */
			const uint8_t id;

			/*!
			 *	Pointer to the parent command manager.
			 */
			const CommandManager* manager;

			/*!
			 *	Command Constructor.
			 *
			 *	@param manager	Pointer to parent manager object.
			 *	@param id		Unique command identifier
			 */
			CommandTemplate(CommandManager* manager, uint8_t id);

			/*!
			 *	Virtual destructificator.
			 */
			virtual ~CommandTemplate();

			/*!
			 *	Handle an incoming message.
			 *
			 *	This function instructs the command template to deal with the
			 *	incoming data.
			 *
			 *	@param data	Pointer to the data buffer
			 */
			virtual void handle(void* data) = 0;

	};

}

#endif
