/*
 * FireTracker.cpp
 *
 *  Created on: Dec 9, 2018
 *      Author: vlads
 */

#include "FireTracker.h"

FireTracker::FireTracker() {
	// TODO Auto-generated constructor stub

}

void FireTracker::init(std::function<void()> callback){
	cam.begin();
	foundFireCallback = callback;
}

bool FireTracker::loop(){
	cam.requestPosition();
	//get the x and y values read from the camera
	if (cam.available()) {
		int x = cam.readX(0);
		int y = cam.readY(0);
		Serial.printf("(%d,%d)\n", x, y);
		if(x < 1023 && y < 1023){
			//Serial.printf("(%d,%d)\n", x, y);
			//foundFireCallback();
			return true;
		}
	}else{
		Serial.println("IR camera not working");
	}
	return false;
}
FireTracker::~FireTracker() {
	// TODO Auto-generated destructor stub
}

