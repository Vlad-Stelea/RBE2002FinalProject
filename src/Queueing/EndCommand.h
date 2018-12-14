/*
 * EndCommand.h
 *
 *  Created on: Dec 14, 2018
 *      Author: vlads
 */

#ifndef SRC_QUEUEING_ENDCOMMAND_H_
#define SRC_QUEUEING_ENDCOMMAND_H_
#include "Command.h"

class EndCommand : public Command{
public:
	EndCommand();
	bool isDone() override;
	void loop() override;
	void setUpCommand() override;
	virtual ~EndCommand();
};

#endif /* SRC_QUEUEING_ENDCOMMAND_H_ */
