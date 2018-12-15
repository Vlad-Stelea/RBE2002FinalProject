/*
 * BlowFireCommand.h
 *
 *  Created on: Dec 14, 2018
 *      Author: vlads
 */

#ifndef SRC_QUEUEING_BLOWFIRECOMMAND_H_
#define SRC_QUEUEING_BLOWFIRECOMMAND_H_

#include "Command.h"
#include "../SubSystems/FireDestroyer.h"
#include "../Components/FireTracker.h"
class BlowFireCommand: public Command {
public:
	BlowFireCommand(FireDestroyer * fd, FireTracker* ft);
	bool isDone() override;
	void loop() override;
	void setUpCommand() override;
	virtual ~BlowFireCommand();
private:
	FireDestroyer * fD;
	FireTracker* ft;
};

#endif /* SRC_QUEUEING_BLOWFIRECOMMAND_H_ */
