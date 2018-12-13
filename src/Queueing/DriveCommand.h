/*
 * DriveCommand.h
 *
 *  Created on: Dec 13, 2018
 *      Author: vlads
 */

#ifndef SRC_QUEUEING_DRIVECOMMAND_H_
#define SRC_QUEUEING_DRIVECOMMAND_H_
#include "Command.h"
#include "../SubSystems/DriveTrain.h"
class DriveCommand: public Command{
public:
	DriveCommand(double inches, DriveTrain * driveTrain);
	bool isDone() override;
	void loop() override;
	void setUpCommand() override;
	virtual ~DriveCommand();
private:
	double numInches;
	DriveTrain *dTrain;
};

#endif /* SRC_QUEUEING_DRIVECOMMAND_H_ */
