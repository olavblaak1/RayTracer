#pragma once

#include <math.h>
#include <ostream>

// A class representing a 3D vector (3 x 1 matrix) with operators overwritten.



class vec3 {
	public:
		float elements[3];

	public:
		vec3(float x = 0, float y = 0, float z = 0) : elements{ x, y, z } {};

		inline float x() const { return elements[0]; };
		inline float y() const { return elements[1]; };
		inline float z() const { return elements[2]; };

		inline vec3 operator-() const { return vec3(-elements[0], -elements[1], -elements[2]); };
		inline float operator[](int i) const { return elements[i]; };
		inline float& operator[](int i) { return elements[i]; };


		inline vec3& operator+=(const vec3& vec) {
			elements[0] += vec.x();
			elements[1] += vec.y();
			elements[2] += vec.z();
			return *this;
		}

		// 'this' is a pointer to the current object (i think)
		// Vec3& creates a reference of return value (in this case the Vec3-object)
		inline vec3& operator*=(const float scalar) {
			elements[0] *= scalar;
			elements[1] *= scalar;
			elements[2] *= scalar;
			return *this;
		}

		inline vec3 operator/=(const float scalar) {
			return *this *= 1/scalar;
		}

		inline float length() const {
			return sqrt(length_squared());
		}

		inline float length_squared() const {
			return(elements[0] * elements[0] + elements[1] * elements[1] + elements[2] * elements[2]);
		}

		inline bool normalized() const {
			return (length() == 1.0f);
		}

		inline static vec3 random_point() {
			return vec3(random_float(), random_float(), random_float());
		}


		inline static vec3 random_point(float min, float max) {
			return vec3(random_float(min, max), random_float(min, max), random_float(min, max));
		}
};

// Type aliases
using point3 = vec3;
using color = vec3;


// Utility Functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.elements[0] << ' ' << v.elements[1] << ' ' << v.elements[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator*(const vec3& u, float t) {
	return vec3(u.x() * t, u.y() * t, u.z() * t);
}

inline vec3 operator*(float t, const vec3& v) {
	return v * t;
}

inline vec3 operator/(const vec3& v, float t) {
	return v * (1 / t);
}

inline float dot(const vec3& u, const vec3& v) {
	return(u.x() * v.x()
		+  u.y() * v.y()
		+  u.z() * v.z());
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(
		u.y() * v.z() - v.y() * u.z(),
		v.x() * u.z() - u.x() * v.z(),
		u.x() * v.y() - v.x() * u.y()
	);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

inline point3 point_in_unit_sphere() {
	point3 point;
	do {
		point = vec3::random_point();
	} while (point.length_squared() >= 1);
	return point;
}