/*
 * Gyro.h
 *
 *  Created on: Dec 8, 2018
 *      Author: vlads
 */

#ifndef SRC_COMPONENTS_GYRO_H_
#define SRC_COMPONENTS_GYRO_H_
#include <Functional>

class Gyro {
public:
	Gyro();

	void setup();
	/**
	 * Gets the angle of the gyro in euler degrees
	 */
	double getHeading();
	/**
	 * Called each loop to update values
	 */
	void loop();
	/**
	 * Called when the robot should start driving
	 * The callback is called when the robot is not moving anymore
	 * @param noMoveCallback the callback to call when the robot is not moving anymore
	 */
	void startDrive(std::function<void()> noMoveCallback);

	/**
	 * Returns the current velocity of the robot
	 */
	double getSpeed();

	/**
	 * Returns whether the robot has stopped moving
	 */
	bool stoppedRotating();

	/**
	 * Gets the linear acceleration in the forward direction for the robot
	 */
	double getAcceleration();

	//void addStopRotatingHandler(std::function<void> onStop, double goal);

	virtual ~Gyro();

private:
	bool moving;
	//std::function<void()> stoppedMovingCallback;
	//Integrates linear acceleration values to get a speed of the robot
	bool turning;
	double goalAngle;
	std::function<void(double curAngle, double turnGoal)> onStopRotating;

	/**
	 * Returns whether the gyro has stopped turning or not
	 */
	bool stoppedTurning();

};

#endif /* SRC_COMPONENTS_GYRO_H_ */
