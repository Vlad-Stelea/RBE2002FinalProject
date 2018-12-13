/*
 * CommandQueue.h
 *
 *  Created on: Dec 13, 2018
 *      Author: vlads
 */

#ifndef SRC_COMMANDQUEUE_H_
#define SRC_COMMANDQUEUE_H_
#include "Command.h"
#include <list>

class CommandQueue {
public:
	CommandQueue();

	/**
	 * Add a command as a stack
	 */
	void addToFront(Command *command);

	/**
	 * Add a command to the queue
	 */
	void addToEnd(Command *command);

	/**
	 * Remove the front of the list
	 * If the current command is not done return a nullptr
	 */
	Command *pop();
	virtual ~CommandQueue();

private:
	std::list<Command*> commands;
	Command *curCommand;
};

#endif /* SRC_COMMANDQUEUE_H_ */
