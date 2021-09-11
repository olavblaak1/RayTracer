#pragma once

#include "vec3.h"
#include <ostream>


void write_pixel(std::ostream &out, color pixel_color, int samples_per_pixel) {
	float r = pixel_color.x();
	float g = pixel_color.y();
	float b = pixel_color.z();

	// Gamma = 2.0 (that is why we take the square root)
	float div = 1.0f / samples_per_pixel;
	r = sqrt(r * div);
	g = sqrt(g * div);
	b = sqrt(b * div);

	out << static_cast<int>(clamp(r, 0, 0.999)*256) << ' '
		<< static_cast<int>(clamp(g, 0, 0.999)*256) << ' '
		<< static_cast<int>(clamp(b, 0, 0.999)*256) << '\n';
}