#include "system.h"

System* System::instance = nullptr;

System::System() {
	initialize();
}

void System::initialize(){

}

System & System::getInstance(){
	if (!instance) {
		instance = new System();
	}
	return *instance;
}

void System::update(){

}

void System::shutdown(){
	if (instance) {
		delete instance;
		instance = nullptr;
	}
}
