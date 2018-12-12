/*
 * Fan.h
 *
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#ifndef SRC_COMPONENTS_FAN_H_
#define SRC_COMPONENTS_FAN_H_

class Fan {
public:
	Fan();
	void setup(int p);
	void turnOn();
	void turnOff();
	virtual ~Fan();

private:
	int port;
};

#endif /* SRC_COMPONENTS_FAN_H_ */
