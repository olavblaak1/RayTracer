#pragma once

#include "hittable.h"

#include <memory>
#include <vector>


using std::shared_ptr;
using std::make_shared;

class hittables : public hittable {
	public:
		hittables() {};
		hittables(shared_ptr<hittable> object) { add(object); };

		void add(shared_ptr<hittable> object) { objects.push_back(object); };
		void clear() { objects.clear(); };

		virtual bool hit(const ray& r, const float t_min, const float t_max, hit_record& rec) const override;
	public:
		std::vector<shared_ptr<hittable>> objects;
};

bool hittables::hit(const ray& r, const float t_min, const float t_max, hit_record& rec) const {
	hit_record temp;
	bool hit = false;

	// Logically, we only want to calculate the color of the object that is the closest to the origin (the object that gets hit "first")
	float closest = t_max;

	for (const shared_ptr<hittable>& object : objects) {
		if (object->hit(r, t_min, closest, temp)) {
			hit = true;
			closest = temp.t;

			rec = temp;
		}
	}

	return hit;
}