#pragma once

#include <math.h>
#include <ostream>

class Vec3 {
	public:
		float elements[3];

	public:
		Vec3(float x = 0, float y = 0, float z = 0) : elements{ x, y, z } {};

		inline float x() const { return elements[0]; };
		inline float y() const { return elements[1]; };
		inline float z() const { return elements[2]; };

		inline Vec3 operator-() const { return Vec3(-elements[0], -elements[1], -elements[2]); };
		inline float operator[](int i) const { return elements[i]; };
		inline float& operator[](int i) { return elements[i]; };


		inline Vec3& operator+=(const Vec3& vec) {
			elements[0] += vec.x();
			elements[1] += vec.y();
			elements[2] += vec.z();
			return *this;
		}

		// 'this' is a pointer to the current object (i think)
		// Vec3& creates a reference of return value (in this case the Vec3-object)
		inline Vec3& operator*=(const float scalar) {
			elements[0] *= scalar;
			elements[1] *= scalar;
			elements[2] *= scalar;
			return *this;
		}

		inline Vec3 operator/=(const float scalar) {
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
};

// Type aliases
using Point3 = Vec3;
using Pixel = Vec3;


// Utility Functions
inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
	return out << v.elements[0] << ' ' << v.elements[1] << ' ' << v.elements[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
	return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline Vec3 operator-(const Vec3& u, const Vec3& v) {
	return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
	return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline Vec3 operator*(const Vec3& u, float t) {
	return Vec3(u.x() * t, u.y() * t, u.z() * t);
}

inline Vec3 operator*(float t, const Vec3& v) {
	return v * t;
}

inline Vec3 operator/(const Vec3& v, float t) {
	return v * (1 / t);
}

inline float dot(const Vec3& u, const Vec3& v) {
	return(u.x() * v.x() + u.y() * v.y() + u.z() * v.z());
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
	return Vec3(
		u.y() * v.z() - v.y() * u.z(),
		v.x() * u.z() - u.x() * v.z(),
		u.x() * v.y() - v.x() * u.y()
	);
}

inline Vec3 unit_vector(Vec3 v) {
	return v / v.length();
}