/*
 * RotateCommand.h
 *
 *  Created on: Dec 13, 2018
 *      Author: vlads
 */

#ifndef SRC_QUEUEING_ROTATECOMMAND_H_
#define SRC_QUEUEING_ROTATECOMMAND_H_

#include "Command.h"
#include "../SubSystems/DriveTrain.h"
class RotateCommand: public Command {
public:
	RotateCommand(double angle, DriveTrain * dt);
	bool isDone() override;
	void loop() override;
	void setUpCommand() override;
	virtual ~RotateCommand();
private:
	DriveTrain * dTrain;
	double angle;
};

#endif /* SRC_QUEUEING_ROTATECOMMAND_H_ */
