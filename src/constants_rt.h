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

// Includes

#include "ray.h"
#include "vec3.h"