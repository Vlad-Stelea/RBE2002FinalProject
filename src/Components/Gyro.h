/*
 * Gyro.h
 *
 *  Created on: Dec 8, 2018
 *      Author: vlads
 */

#ifndef SRC_COMPONENTS_GYRO_H_
#define SRC_COMPONENTS_GYRO_H_

class Gyro {
public:
	Gyro();
	/**
	 * Gets the angle of the gyro in euler degrees
	 */
	double getHeading();
	void setup();
	virtual ~Gyro();
};

#endif /* SRC_COMPONENTS_GYRO_H_ */
