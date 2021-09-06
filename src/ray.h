#pragma once

#include <cassert>
#include "vec3.h"


// A class representing a parametric equation of a line P(t) = A + Bt (also called a ray in this context, since t > 0)
class ray {
	public:

		ray(const Vec3& position, const Vec3& direction) : pos(position), dir(direction) {
			assert(direction.length_squared() != 0);
		};

		const Point3& position() const { return pos; };
		const Vec3& direction() const { return dir; };


		void set_position(const Vec3 &position) { pos = position; }
		void set_direction(const Vec3 &direction) {
			assert(direction.length() != 0);
			dir = direction;
		}


		const Vec3& at(float t) const {
			assert(t > 0);
			return (pos + t * dir);
		}

	private:
		Point3 pos;
		Vec3 dir
};