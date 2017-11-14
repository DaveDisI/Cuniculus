#pragma once

#include "system.h"
#include "sprite_2d.h"

class Sprite2D_RenderSystem : public System {
private:
	static Sprite2D_RenderSystem* instance;
	Sprite2D_RenderSystem();
	void initialize();
	void loadSprite(Sprite2D& sprite, unsigned char* data, int w, int h);

public:
	static Sprite2D_RenderSystem& getInstance();
	void update();
	void shutdown();
	void initBuffer();
};
