/*
 * CommandQueue.cpp
 *
 *  Created on: Dec 13, 2018
 *      Author: vlads
 */

#include "CommandQueue.h"
#include <Arduino.h>

CommandQueue::CommandQueue() {
	// TODO Auto-generated constructor stub

}

void CommandQueue::addToEnd(Command *command){
	commands.push_back(command);
}

void CommandQueue::addToFront(Command *command){
	commands.push_front(command);
}

Command *CommandQueue::pop(){
	Serial.println("POP");
	//Deal with the front
	if(curCommand == nullptr){
		Command *newCommand = commands.front();
		commands.pop_front();
		return newCommand;
	}
	if(curCommand->isDone()){
		curCommand = commands.front();
		commands.pop_front();
		return curCommand;
	}
	return nullptr;
}

CommandQueue::~CommandQueue() {
	// TODO Auto-generated destructor stub
}

