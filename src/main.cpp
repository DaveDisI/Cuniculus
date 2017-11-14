#include <iostream>

#include "cuniculus.h"

int main(int argc, char** argv) {
	IOManager iomgr = IOManager::getInstance();

	Cuniculus cuniculus("Cuniculus", 100, 100, 800, 500, false, false);
	cuniculus.initialize();

	long startTime = 0;
	long endTime = 0;
	float deltaTime = 0;
	while (!cuniculus.quit) {
		startTime = iomgr.getTime();
		iomgr.processEvents();
		
		cuniculus.update(deltaTime);
		cuniculus.draw();

		iomgr.swapWindowBuffer();
		endTime = iomgr.getTime();
		deltaTime = ((float)endTime - (float)startTime) / 1000.0f;
	}

	cuniculus.shutdown();

	return 0;
}