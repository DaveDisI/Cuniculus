#pragma once

#include <vector>

#include "io_manager.h"
#include "renderer_gl.h"

#include "scene.h"

using namespace std;

class Game {
public:
	Game(const char* title, int windowX, int windowY, int windowW, int windowH, bool fullscreen, bool desktopMode) {
		windowID = iomgr->createWindow(title, windowX, windowY, windowW, windowH);
		if (fullscreen) {
			iomgr->setWindowFullScreen(desktopMode);
		}
	}

	bool quit = false;
	virtual void initialize() = 0 {}
	virtual void update(float deltaTime) = 0 {}
	virtual void draw() = 0 {}
	virtual void shutdown() = 0 {}

protected:
	unsigned int windowID;
	vector<Scene> scenes;
	IOManager* iomgr;
	Renderer_GL* rndr;
};