#pragma once

#include "game.h"

#include "start_scene.h"

class Cuniculus : public Game {
public:
	Cuniculus(const char * title, int windowX, int windowY, int windowW, int windowH, bool fullscreen, bool desktopMode);
	void initialize() override;
	void update(float deltaTime) override;
	void draw() override;
	void shutdown() override;
private:
	StartScene startScene;
};
