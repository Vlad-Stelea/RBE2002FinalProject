/*!
 *	@file include/commandListener.hpp
 */

class CommandListener;

#ifndef _COMMANDMANAGER_H_
#define _COMMANDMANAGER_H_

#include <WiFi.h>
#include <WiFiUdp.h>

#define NUMBER_OF_HANDLERS 7
#define UDP_PORT 1234
#define UDP_BUFFER_SIZE 512

// Forward declaration of command template
namespace cmd {
	class CommandTemplate;
}

/*!
 *	Command Manager Class.
 *
 *	This class manages everything related to UDP and commands.  Amazing.
 */
class CommandManager {

private:

		/*!
		 *	UDP buffer
		 */
		uint8_t buffer[UDP_BUFFER_SIZE];

	public:

		/*!
		 *	WiFi UDP control management object (of doom)
		 */
		static WiFiUDP udp;

		/*!
		 *	Command template array.
		 *
		 *	This array contains all of the command handlers used by the
		 *	application.
		 */
		cmd::CommandTemplate* handlers[NUMBER_OF_HANDLERS];

		/*!
		 *	Create the command manager.
		 */
		CommandManager();

		/*!
		 *	Check for and handle commands.
		 *
		 *	This function will check the udp mailbox for commands, and if any
		 *	are found, pass those commands to the appropriate command handler.
		 */
		void check_mailbox();

};


#endif
