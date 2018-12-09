#include "Arduino.h"

#include <WiFi.h>

#include "commandManager.hpp"
#include "locomotionController.hpp"
#include "src/Components/ServoEncoderPIDMotor.h"
#include  "src/Components/Gyro.h"
#include "src/SubSystems/DriveTrain.h"

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
void setup() {
	// Add your initialization code here
	Serial.begin(115200);
	Serial.println("STARTUP!");
	//g.setup();
	WiFi.softAPConfig(WIFI_ADDR, WIFI_GATE, WIFI_SUBN);
	WiFi.softAP(WIFI_SSID, WIFI_PASS, 3, false, 4);

	lm = new LocomotionController();
	cm = new CommandManager();
	d.setup();
	d.drive(-10000, 10000);
}

void loop() {
	//Serial.println("LOOP");
	// Check the mailbox
	cm->check_mailbox();
	// Update the locomotion controller
	lm->update();
	d.loop();
}
