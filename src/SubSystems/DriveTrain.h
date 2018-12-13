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
#include <list>

class DriveTrain {
public:
	struct currentLoc{
		int x, y;
	};

	struct encoderHolder{
		long long left, right;
	};

	DriveTrain();
	void setup(Gyro *g);
	/**
	 * Rotate the robot to a specified angle
	 * @param degrees the number of degrees to rotate the robot
	 * 		negative parameter means
	 */
	void rotateAngle(double degrees);
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
	void ETGoHome();

	void setOutputs(int right, int left);

	//Returns whether the robot is ready for another command to be passed in
	bool readyForCommand();

	virtual ~DriveTrain();
private:
	void resetEncs();
	static void rotationCallback(DriveTrain *d);
	HBridgeEncoderPIDMotor leftMotor;
	HBridgeEncoderPIDMotor rightMotor;
	Gyro gyro;
	FireTracker tracker;
	//TODO make sure they work
	const int leftServPin = 19;
	const int leftEncPinA = 17;
	const int leftEncPinB = 16;
	const int leftDirPin = 5;

	const int rightServPin = 33;
	const int rightEncPinA = 26;
	const int rightEncPinB = 27;
	const int rightDirPin = 25;

	const int turningLeeway = 2;

	/**
	 * PID CONSTANTS
	 */

	//Left drive motor constants
	const double leftKP = .48;
	const double leftKI = 0;
	const double leftKD = 0;
	//Right drive motor constants
	const double rightKP = .45;
	const double rightKI = 0;
	const double rightKD = 0;

	const double turningKP = 1000;
	const double turningKI = 700;
	const double turningKD = 40;
	const int minValue = 500;
	/*const double turningKI = .01;
	const double turningKD = .01;*/


	//keeps track of whether a command is still executing
	bool driving = false;
	//Keep track if the robot is performing a turn
	bool turning = false;
	//Keeps track of whether the robot is ready for another command to be passed in
	bool ready;
	double turningGoal;
	double turningThreshold = 3;

	const int circumference = PI*3;

	const double WHEEL_BASE_CIRCUMFERENCE = 9.5*PI;

	long long convertInchesToTicks(double inches);

	/**
	 * Converts a degree value for the robot to turn to how many ticks the wheels need to turn
	 * @param degrees the number of degrees that the robot should turn relative to where it is now
	 */
	long long convertTurnAngleToTicks(double degrees);

	/**
	 * Passed in to gyro to do after the robot stops turning
	 * Compensates if the error is not withing a reasonable threshold
	 * @param currentAngle the angle that the gyro has currently turned
	 */
	static void correctAngle(double currentAngle);

	const static int numEncVals = 100;
	struct encoderHolder prevEncVals[numEncVals];
	bool allItemsSame(struct encoderHolder* encoderVals);
	void addEncHolder(struct encoderHolder *prevVals, struct encoderHolder newValue);
	int currentIdx = 0;

};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
