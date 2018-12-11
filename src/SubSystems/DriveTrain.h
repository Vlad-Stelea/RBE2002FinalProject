/*
 * DriveTrain.h
 *
 *  Created on: Dec 8, 2018
 *      Author: vlads
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_
#include "../Components/HBridgeEncoderPIDMotor.h"
#include "../Components/FireTracker.h"

#include "../Components/Gyro.h"
class DriveTrain {
public:
	struct currentLoc{
		int x, y;
	};

	DriveTrain();
	void setup();
	/**
	 * Rotate the robot to a specified angle
	 * @param degrees the number of degrees to rotate the robot
	 * 		negative parameter means
	 */
	void rotateAngle(int degrees);
	/**
	 * Sets a goal to drive a specified distance
	 * 	Keep calling loop to run it farther
	 * @param inches the number of inches to drive
	 */
	void driveDistance(double inches);
	/**
	 * Drive both drivetrain motors at the given speeds
	 * @param leftSpeed the speed to drive the left motor
	 * @param rightSpeed the speed to drive the right motor
	 */
	void drive(int leftSpeed, int rightSpeed);
	/**
	 * rotates our drivetrain
	 * @param speed the speed to turn the robot
	 */
	void rotateRobot(int speed);
	/**
	 * Called to run the drive train at the current setPoints
	 */
	void loop();

	/**
	 * Line up to the fire after already being found
	 */
	void lineUpFire();

	/**
	 * Sends the robot back to home base
	 */
	void goETGoHome();

	virtual ~DriveTrain();
private:
	HBridgeEncoderPIDMotor leftMotor;
	HBridgeEncoderPIDMotor rightMotor;
	Gyro gyro;
	FireTracker tracker;
	//TODO make sure they work
	const int leftServPin = 32;
	const int leftEncPinA = 17;
	const int leftEncPinB = 16;
	const int leftDirPin = 5;

	const int rightServPin = 33;
	const int rightEncPinA = 34;
	const int rightEncPinB = 35;
	const int rightDirPin = 25;

	const int turningLeeway = 2;

	/**
	 * PID CONSTANTS
	 */
	const double turningKP = .1;

	//Left drive motor constants
	const double leftKP = .1;
	const double leftKI = 0;
	const double leftKD = 0;
	//Right drive motor constants
	const double rightKP = .1;
	const double rightKI = 0;
	const double rightKD = 0;

	//keeps track of whether a command is still executing
	bool driving;

};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
