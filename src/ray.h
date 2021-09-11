#pragma once

#include <cassert>
#include "vec3.h"


// A class representing a parametric equation of a line P(t) = A + Bt (also called a ray in this context, since t > 0)
class ray {
	public:

		ray(const vec3& position, const vec3& direction) : pos(position), dir(direction) {
			assert(direction.length_squared() != 0);
		};

		const point3& position() const { return pos; };
		const vec3& direction() const { return dir; };


		void set_position(const vec3 &position) { pos = position; }
		void set_direction(const vec3 &direction) {
			assert(direction.length() != 0);
			dir = direction;
		}


		const vec3 at(float t) const {
			return (pos + t * dir);
		}

	private:
		point3 pos;
		vec3 dir;
};