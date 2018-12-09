/*
 * DriveTrain.h
 *
 *  Created on: Dec 8, 2018
 *      Author: vlads
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_
#include "../Components/HBridgeEncoderPIDMotor.h"

#include "../Components/Gyro.h"
class DriveTrain {
public:
	DriveTrain();
	void setup();
	/**
	 * Rotate the robot to a specified angle
	 * @param degrees the number of degrees to rotate the robot
	 * 		negative parameter means
	 */
	void rotateAngle(int degrees);
	/**
	 * Drive a specified distance
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
	virtual ~DriveTrain();
private:
	HBridgeEncoderPIDMotor leftMotor;
	HBridgeEncoderPIDMotor rightMotor;
	Gyro gyro;
	//TODO make sure they work
	const int leftServPin = 32;
	const int leftEncPinA = 14;
	const int leftEncPinB = 27;
	const int leftDirPin = 26;

	const int rightServPin = 33;
	const int rightEncPinA = 34;
	const int rightEncPinB = 35;
	const int rightDirPin = 25;

	const int turningLeeway = 2;

	const double turningKP = .1;

};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
