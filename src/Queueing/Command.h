/*
 * Command.h
 *
 *  Created on: Dec 13, 2018
 *      Author: vlads
 */

#ifndef SRC_QUEUEING_COMMAND_H_
#define SRC_QUEUEING_COMMAND_H_

class Command {
public:
	Command();
	virtual bool isDone() = 0;
	virtual void loop() = 0;
	virtual void setUpCommand() = 0;
	virtual ~Command();
};

#endif /* SRC_QUEUEING_COMMAND_H_ */
