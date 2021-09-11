#pragma once

#include <cmath>
#include <limits>
#include <memory>

// Usings

using std::make_shared;
using std::shared_ptr;
using std::sqrt;

// Constants

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.141592f;

// Utility

inline float degrees_to_radians(const float degrees) {
	return degrees * (pi / 180.0f);
}

inline float random_float() {
	return rand() / (RAND_MAX + 1.0f);
}

inline float random_float(float min, float max) {
	return min + (max - min) * random_float();
}

inline float clamp(float num, float min, float max) {
	if (num < min) return min;
	if (max < num) return max;
	return num;
}


// Includes

#include "ray.h"
#include "vec3.h"