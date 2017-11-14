#pragma once

#include <vector>

#include "io_manager.h"

#include "entity.h"

class Scene {
public:
	virtual void initialize() = 0 {}
	virtual void update(float deltaTime) = 0 {}
	virtual void draw() = 0 {}
	virtual void shutdown() = 0 {}

private:
	IOManager iomgr = IOManager::getInstance();

	vector<Entity> entities;
};