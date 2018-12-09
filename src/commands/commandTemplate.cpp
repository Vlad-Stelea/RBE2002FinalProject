/*!
 *	@file src/commands/commandTemplate.cpp
 */

#include "commands/commandTemplate.hpp"

cmd::CommandTemplate::CommandTemplate(CommandManager* manager, uint8_t id) :
	id(id), manager(manager){

}

cmd::CommandTemplate::~CommandTemplate() {}
