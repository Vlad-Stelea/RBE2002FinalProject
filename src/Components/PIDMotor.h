/*
 * PIDMotor.h
 *
 *  Created on: Oct 16, 2018
 *      Author: hephaestus
 */

#ifndef SRC_PIDMOTOR_H_
#define SRC_PIDMOTOR_H_
#include <PID_v1.h>
#include <stdint.h>
#define PID_OUTPUT_COMPUTE_RANGE 900
#define ticksToDeg 0.2206
class PIDMotor {
protected:

	float Kp=2, Ki=1.5, Kd=0.1;
	double Setpoint= 90, Input=0, Output=0;
	bool lastErrPositive=false;
	double curTime=0;
	double prevTime=0;
	double timeInterval=0;
	double movement=0;
	double prevPos;
	double Vel;
public:
	PID myPID;
	PIDMotor();
	virtual ~PIDMotor();
	void loop();
	void overrideCurrentPosition(int64_t val);
	void setSetpoint(int64_t val);
	void SetTunings(double Kp, double Ki, double Kd);
	void pidinit();
	float getSetPoint();
	double calcVel();
	int calcCur();
	virtual int64_t getPosition()=0;
	virtual int64_t getOutputMin()=0;
	virtual int64_t getOutputMax()=0;
	virtual void setOutput(int64_t out)=0;
	virtual void overrideCurrentPositionHardware(int64_t val)=0;
	void velocityLoop();

};

#endif /* SRC_PIDMOTOR_H_ */
