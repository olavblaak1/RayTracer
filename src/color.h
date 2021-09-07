#pragma once

#include "vec3.h"
#include <ostream>


void write_pixel(std::ostream &out, const vec3 &v) {
	out << static_cast<int>(v.x()*255.999) << ' '
		<< static_cast<int>(v.y()*255.999) << ' '
		<< static_cast<int>(v.z()*255.999) << '\n';
}