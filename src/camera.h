#pragma once

#include "vec3.h"
#include "ray.h"

class camera {
	public:
		camera() {
			const float aspect_ratio = 16.0f / 9.0f;
			const float viewport_height = 2.0f;
			const float viewport_width = viewport_height * aspect_ratio;
			const float focal_length = 1.0f;

			origin = point3(0, 0, 0);
			horizontal = vec3(viewport_width, 0, 0);
			vertical = vec3(0, viewport_height, 0);
			top_left_corner = origin + vertical / 2 - horizontal / 2 - vec3(0, 0, focal_length);
		}

		ray get_ray(float u, float v) {
			return ray(origin, top_left_corner + v * horizontal - u * vertical - origin);
		}

	private:
		point3 origin;
		point3 top_left_corner;
		vec3 horizontal;
		vec3 vertical;
};