#pragma once

#include "component.h"
#include "math_util.h"


class Transformation2D : public Component {
	vec2 position = vec2(0, 0);
	vec2 orientation = vec2(0, 0);
	vec2 scale = vec2(1, 1);
};