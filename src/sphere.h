#pragma once

#include "hittable.h"

class sphere : hittable {
	public:
		sphere(const point3& center = point3(0, 0, 0), const float radius = 0) : center(center), radius(radius) {};
		virtual bool hit(const ray& r, const float t_min, const float t_max, hit_record& rec) const override;

	public:
		const point3 center;
		const float radius;
};

bool sphere::hit(const ray& r, const float t_min, const float t_max, hit_record& rec) const {
	const vec3 oc = r.position() - center;
	const float a = dot(r.direction(), r.direction());
	const float half_b = dot(r.direction(), oc);
	const float c = oc.length_squared() - radius * radius;
	const float discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return false;

	// sqrt is an expensive operation, so we save one calculation by storing the value
	float sqrt_discr = sqrt(discriminant);
	float root = (-half_b - sqrt_discr) / a;
	if (root < t_min || root > t_max) {
		root = (-half_b + sqrt_discr) / a;
		if (root < t_min || root > t_max)
			return false;
	}

	rec.t = root;
	rec.hit = r.at(root);
	rec.normal = (rec.hit - center) / radius;

	return true;
};