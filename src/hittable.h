#pragma once

#include "ray.h"

struct hit_record {
	point3 hit;
	float t;
	vec3 normal;
};


class hittable {
	public:
		virtual bool hit(const ray& r, const float t_min, const float t_max, hit_record& rec) const = 0;
};