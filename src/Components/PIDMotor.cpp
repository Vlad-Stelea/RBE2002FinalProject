/*
 * PIDMotor.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: hephaestus
 */

#include "PIDMotor.h"
#include <Arduino.h>
#include <PID_v1.h>
#include "RBEPID.h"
#include <String>

RBEPID rbePid;
PIDMotor::PIDMotor() :
		myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT) {
	rbePid.setpid(Kp,Ki, Kd);
}

PIDMotor::~PIDMotor() {
	// TODO Auto-generated destructor stub
}
void PIDMotor::pidinit() {
	myPID.SetMode(MANUAL);
	myPID.SetMode(AUTOMATIC);
	myPID.SetOutputLimits(-PID_OUTPUT_COMPUTE_RANGE, PID_OUTPUT_COMPUTE_RANGE);
	myPID.SetTunings(Kp, Ki, Kd, P_ON_E);
	myPID.SetSampleTime(5);
}

void PIDMotor::loop() {
	Input = (float) getPosition();
	bool thisErrPositive = Input > 0;
	if (thisErrPositive != lastErrPositive) {
		// strobe mode to trigger zeroing of the Integral buffer
		// In case of passing zero clear the integral sum
		Output = 0;
		myPID.SetMode(MANUAL);
		myPID.SetMode(AUTOMATIC);
	}
	lastErrPositive = thisErrPositive;
	if (myPID.Compute()) {
		int out = map(Output, -PID_OUTPUT_COMPUTE_RANGE,
				PID_OUTPUT_COMPUTE_RANGE, getOutputMin(), getOutputMax());
		setOutput(out);
	}

}
void PIDMotor::overrideCurrentPosition(int64_t val) {
	overrideCurrentPositionHardware(val);
	setSetpoint(val);
	myPID.SetTunings(Kp, Ki, Kd, P_ON_E);
	// strobe mode to trigger zeroing of the Integral buffer
	Output = 0;
	myPID.SetMode(MANUAL);
	myPID.SetMode(AUTOMATIC);
}
void PIDMotor::setSetpoint(int64_t val) {
	Setpoint = (float) val;
}
float PIDMotor::getSetPoint(){
	return Setpoint;
}
void PIDMotor::SetTunings(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	overrideCurrentPosition(getPosition());
}
int prevTime = 0;
void PIDMotor::velocityLoop(){
	int64_t time = esp_timer_get_time()/1000;
	if(time-prevTime >= 10){
		double curVel = calcVel();
		digitalWrite(21,HIGH);
		//Serial.println(curVel);
		float current = .1;
		//table.torque(current, curVel*60);
		//Serial.println(table.torque(current, curVel*60));
		int motorOutput = (int)rbePid.calc(Setpoint, curVel);
		Serial.println(motorOutput);
		this->setOutput(motorOutput);
		prevTime = time;
	}
}

int PIDMotor::calcCur(){
	//output 525mv per Amp
	//0v=0 1024=5v
	unsigned short int reading = analogRead(36);
	double voltage = (reading/1024)*5;
	int amps = .525*voltage;
	return amps*1000;
}
// Returns Vel in degress/second
double PIDMotor::calcVel(){
  //current positions
  double curPos=getPosition();
  //current time
  curTime=millis();
  //time change in ms from last call
  timeInterval=curTime-prevTime;
  //encoder ticks since last call
  movement=curPos-prevPos;
  //encoder ticks to degrees
  movement= movement *ticksToDeg;
  //timeInterval in seconds
  timeInterval=timeInterval/1000;
  //Velocity in degrees per milliseconds
  Vel=movement/timeInterval;
  //sets curent vals to previous
  prevPos=curPos;
  prevTime=curTime;
  return Vel;
}
