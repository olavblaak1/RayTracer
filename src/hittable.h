#pragma once

#include "ray.h"

struct hit_record {
	point3 hit;
	float t;
	vec3 normal;
	bool facing_outward = true;

	// We choose that the normal always faces against the direction of the ray
	inline void set_normal_direction(const ray& r, const vec3& outward_normal) {
		facing_outward = dot(r.direction(), outward_normal) < 0;
		normal = facing_outward ? outward_normal : -outward_normal;
	}
};


class hittable {
	public:
		virtual bool hit(const ray& r, const float t_min, const float t_max, hit_record& rec) const = 0;
};