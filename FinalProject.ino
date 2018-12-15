#include "Arduino.h"

#include <WiFi.h>

#include "commandManager.hpp"
#include "locomotionController.hpp"
#include "src/Components/ServoEncoderPIDMotor.h"
#include  "src/Components/Gyro.h"
#include "src/SubSystems/DriveTrain.h"
#include "src/Components/FireTracker.h"
#include "src/Components/DistanceSensor.h"
#include "src/SubSystems/FireDestroyer.h"

#include "src/Queueing/Command.h"
#include "src/Queueing/CommandQueue.h"
#include "src/Queueing/DriveCommand.h"
#include "src/Queueing/RotateCommand.h"
#include "src/Queueing/BlowFireCommand.h"
#include "src/Queueing/EndCommand.h"

const char* WIFI_SSID = "esp32";
const char* WIFI_PASS = "robotics_is_fun_rbe2002";

IPAddress WIFI_ADDR(192,168,1,2);
IPAddress WIFI_GATE(0,0,0,0);
IPAddress WIFI_SUBN(255,255,255,0);

IPAddress BROADCAST_ADDR(255,255,255,255);
#define BROADCAST_PORT 2002


CommandManager* cm;
LocomotionController* lm;
//Gyro g;
DriveTrain d;
DistanceSensor dSensor;
FireTracker ft;
FireDestroyer fd;
CommandQueue cq;
DistanceSensor leftSens;
Command *curCommand;

void setup() {
	// Add your initialization code here
	delay(500);
	Serial.begin(115200);
	Serial.println("STARTUP!");
	Gyro g;
	g.setup();
	d.setup(&g);
	WiFi.softAPConfig(WIFI_ADDR, WIFI_GATE, WIFI_SUBN);
	WiFi.softAP(WIFI_SSID, WIFI_PASS, 3, false, 4);
	leftSens.setUp(32);
	lm = new LocomotionController();
	cm = new CommandManager();
	//d.drive(-10000, 10000);
	//d.driveDistance(10);
	//d.rotateAngle(-90);
	//cq.addToEnd(new RotateCommand(-90, &d));
	//cq.addToEnd(new RotateCommand(-90, &d));
	//cq.addToEnd(new DriveCommand(10, &d));
	//cq.addToEnd(new RotateCommand(-60, &d));
	//cq.addToEnd(new DriveCommand(10, &d));
	fd.setup(4, 18);
	/*fd.tiltToAngle(115);
	fd.turnOnFan();
	delay(1000000);*/
	//fd.turnOnFan();
	cq.addToEnd(new DriveCommand(77, &d));
	cq.addToEnd(new RotateCommand(-60, &d));
	cq.addToEnd(new DriveCommand(20, &d));
	cq.addToEnd(new RotateCommand(-60,&d));
	//cq.addToEnd(new DriveCommand(5,&d));
	cq.addToEnd(new BlowFireCommand(&fd, &ft));
	cq.addToEnd(new EndCommand());
	curCommand = cq.pop();
	curCommand->setUpCommand();
	//d.setOutputs(-5000,-5000);
	//while(1);*/
	//fd.turnOnFan();
	//fd.tiltToAngle(40);
	/*d.driveDistance(3);
	d.driveDistance(4);*/
	/*while(1)
		Serial.println(String(g.getSpeed()));*/
	//ft.init(detectFire);
}

void loop() {
	if(curCommand->isDone()){
		//Serial.println("POPPY");
		Command *newCom = cq.pop();
		if(newCom == nullptr){
			return;
		}
		curCommand = newCom;
		curCommand->setUpCommand();
		//delay(1);
	}
	curCommand->loop();
	if(leftSens.getThreshold()){
		//Add search of building to front of queue
		cq.addToFront(new DriveCommand(10,&d));
		cq.addToFront(new RotateCommand(-90,&d));
		cq.addToFront(new BlowFireCommand(fd, ft));
		cq.addToFront(new DriveCommand(10,&d));
		cq.addToFront(new RotateCommand(-90,&d));
		cq.addToFront(new DriveCommand(10,&d));
		cq.addToFront(new BlowFireCommand(fd, ft));
		cq.addToFront(new DriveCommand(10,&d));
		cq.addToFront(new RotateCommand(-90,&d));
		cq.addToFront(new DriveCommand(10,&d));
		cq.addToFront(new BlowFireCommand(fd, ft));
		cq.addToFront(new DriveCommand(10,&d));
		cq.addToFront(new RotateCommand(-90,&d));
		cq.addToFront(new DriveCommand(30,&d));
	}
	//Serial.read();
	//Serial.println("LOOP");
	// Check the mailbox
	//Serial.println(g.getHeading());
	cm->check_mailbox();
	// Update the locomotion controller
	lm->update();
	//dSensor.getThreshold();
	//Serial.println("Speed: " + String(g.getSpeed()));*/
	//d.loop();
	//ft.loop();
	//ft.loop();
	//Serial.println("AHHHHHHH: " + String(g.getHeading()));
}

void detectFire(){
	/*while(1){
		Serial.println("FOUND A FIRE");
	}*/
}
