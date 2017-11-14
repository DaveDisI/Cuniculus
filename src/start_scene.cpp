#include "start_scene.h"

void StartScene::initialize(){
	initBunny();
}

void StartScene::update(float deltaTime){

}

void StartScene::draw(){

}

void StartScene::shutdown(){

}

void StartScene::initBunny(){
	spriteRndr = &Sprite2D_RenderSystem::getInstance();
	Sprite2D bunnySprite;
	Transformation2D bunnyTransform;
	bunny.addComponent(bunnySprite);
	bunny.addComponent(bunnyTransform);
}
