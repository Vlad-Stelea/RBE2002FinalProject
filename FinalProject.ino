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
//FireTracker ft;
FireDestroyer fd;
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
	dSensor.setUp(32);
	lm = new LocomotionController();
	cm = new CommandManager();
	//d.drive(-10000, 10000);
	d.driveDistance(20);
	//d.rotateAngle(90);
	//d.setOutputs(-5000,-5000);
	//while(1);
	//fd.setup(19, 18);
	//fd.tiltToAngle(30);
	/*d.driveDistance(3);
	d.driveDistance(4);*/
	/*while(1)
		Serial.println(String(g.getSpeed()));*/
	//ft.init(detectFire);
}

void loop() {
	//Serial.read();
	//Serial.println("LOOP");
	// Check the mailbox
	//Serial.println(g.getHeading());
	cm->check_mailbox();
	// Update the locomotion controller
	lm->update();
	//dSensor.getThreshold();
	//Serial.println("Speed: " + String(g.getSpeed()));*/
	d.loop();
	//ft.loop();
	//Serial.println("AHHHHHHH: " + String(g.getHeading()));
}

void detectFire(){
	/*while(1){
		Serial.println("FOUND A FIRE");
	}*/
}
