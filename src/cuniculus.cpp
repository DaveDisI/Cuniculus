#include "cuniculus.h"

#include <iostream>

Cuniculus::Cuniculus(const char * title, int windowX, int windowY, int windowW, int windowH, bool fullscreen, bool desktopMode)
	:Game(title, windowX, windowY, windowW, windowH, fullscreen, desktopMode){

}

void Cuniculus::initialize(){
	iomgr = &IOManager::getInstance();
	rndr = &Renderer_GL::getInstance();
	rndr->setClearColor(0, 1, 0, 1);

	startScene.initialize();
}

void Cuniculus::update(float deltaTime){
	if (iomgr->keys[IOManager::ESC_KEY]) {
		quit = true;
	}

	startScene.update(deltaTime);
}

void Cuniculus::draw(){
	rndr->clear(GL_COLOR_BUFFER_BIT);

	startScene.draw();
}

void Cuniculus::shutdown(){
	rndr->shutdown();
	iomgr->shutdown();
}

