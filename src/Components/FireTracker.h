/*
 * FireTracker.h
 *
 *  Created on: Dec 9, 2018
 *      Author: vlads
 */

#ifndef SRC_COMPONENTS_FIRETRACKER_H_
#define SRC_COMPONENTS_FIRETRACKER_H_
#include <DFRobotIRPosition.h>
#include <Functional>

class FireTracker {
public:
	struct FireLoc{
		int x, y;
	};
	FireTracker();
	bool loop();
	FireLoc getFireCoords();
	void init(std::function<void()> callback);
	virtual ~FireTracker();
private:
	DFRobotIRPosition cam;
	std::function<void()> foundFireCallback;
};

#endif /* SRC_COMPONENTS_FIRETRACKER_H_ */
