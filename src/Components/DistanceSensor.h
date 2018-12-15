/*
 * DistanceSensor.h
 *
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#ifndef SRC_COMPONENTS_DISTANCESENSOR_H_
#define SRC_COMPONENTS_DISTANCESENSOR_H_

class DistanceSensor {
public:
	DistanceSensor();
	/**
	 * Set up the distance sensor object
	 * @param p the port that the sensor is reading from
	 */
	void setUp(int p);
	bool getThreshold();
	virtual ~DistanceSensor();
private:

	//The port that the sensor is plugged into
	int port;
	//The value that the sensor reads if there is an object nearby for
	const int distanceThreshold = 500;
};

#endif /* SRC_COMPONENTS_DISTANCESENSOR_H_ */
