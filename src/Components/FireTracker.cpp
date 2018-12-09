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
	return true;
}
FireTracker::~FireTracker() {
	// TODO Auto-generated destructor stub
}

