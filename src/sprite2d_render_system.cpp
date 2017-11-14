#include "sprite2d_render_system.h"

Sprite2D_RenderSystem* Sprite2D_RenderSystem::instance = nullptr;

Renderer_GL::VAO_GL vao;
unsigned int shader;

const char* stuff = " ";

Sprite2D_RenderSystem::Sprite2D_RenderSystem() {
	initialize();
}

void Sprite2D_RenderSystem::initialize() {
	iomgr = &IOManager::getInstance();
	rndr = &Renderer_GL::getInstance();
	initBuffer();
}

void Sprite2D_RenderSystem::loadSprite(Sprite2D& sprite, unsigned char * data, int w, int h) {

}

Sprite2D_RenderSystem& Sprite2D_RenderSystem::getInstance() {
	if (!instance) {
		instance = new Sprite2D_RenderSystem();
	}
	return *instance;
}

void Sprite2D_RenderSystem::update() {

}

void Sprite2D_RenderSystem::shutdown() {
	rndr->deleteVAO(vao);
	if (instance) {
		delete instance;
		instance = nullptr;
	}
}

void Sprite2D_RenderSystem::initBuffer() {
	float verts[] = {
		-0.5, -0.5,
		-0.5,  0.5,
		0.5,  0.5,
		0.5, -0.5,
	};

	unsigned char elms[] = {
		0, 1, 2, 2, 3, 0
	};
	vao = rndr->createVAO(Renderer_GL::VAO_GL::V2_V2, GL_UNSIGNED_BYTE);
	rndr->updateVAO(vao, 4, 6, verts, elms);
}
