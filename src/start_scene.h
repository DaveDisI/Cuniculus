#pragma once

#include "scene.h"
#include "sprite2d_render_system.h"
#include "sprite_2d.h"
#include "transformation_2d.h"

class StartScene : public Scene {
public:
	void initialize() override;
	void update(float deltaTime) override;
	void draw() override;
	void shutdown() override;
private:
	Entity bunny;
	Sprite2D_RenderSystem* spriteRndr;
	void initBunny();
};