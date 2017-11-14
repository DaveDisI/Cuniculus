#pragma once

#include <vector>

#include "component.h"

using namespace std;

class Entity {
public:
	void addComponent(Component c) {}
	void removeComponent(Component c) {}
	void addEntity(Entity e) {}
	void removeEntity(Entity e) {}

	inline void setParent(Entity* p) {
		parent = p;
	}

private:
	Entity* parent;
	vector<Component> components;
	vector<Entity> entities;
};