#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <vector>
#include <stdexcept>
#include <math.h>

#include "wykobi/wykobi.hpp"


namespace copper {

template<class T>
class Vector2: public wykobi::vector2d<T> { 
	public:
		Vector2(): wykobi::vector2d<T>() {};
		Vector2(T x, T y): wykobi::vector2d<T>(x, y) {};
		Vector2(const wykobi::vector2d<T>& v): wykobi::vector2d<T>(v.x, v.y) {};

	inline T length() {
	  return std::sqrt((this->x * this->x) + (this->y * this->y));
	}

	inline void normalize() {
		T c = T(1.0) / length();
		this->x *= c; this->y *= c;
	}
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;


template<class T>
class Vector3: public wykobi::vector3d<T> { 
	public:
		Vector3(): wykobi::vector3d<T>() {};
		Vector3(T x, T y, T z): wykobi::vector3d<T>(x, y, z) {};
		Vector3(const wykobi::vector3d<T>& v): wykobi::vector3d<T>(v.x, v.y, v.z) {};

		inline T length() {
			return std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
		}

		inline void normalize() {
			T c = T(1.0) / length();
			this->x *= c; this->y *= c; this->z *= c;
		}

		inline Vector3<T> normalized() {
			T c = T(1.0) / length();
			return Vector3<T>(this->x * c, this->y * c, this->z * c);
		}

};

typedef Vector3<int> Vector3i;
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

// Overloaded operators
template <typename T>
inline Vector3<T> operator^(const Vector3<T>& v1, const Vector3<T>& v2){
  Vector3<T> v(
  	v1.x * v2.z - v1.z * v1.y,
  	-v1.x * v2.z + v1.z * v2.x,
  	v1.x * v2.y - v1.y * v2.x
  );
  return v;
}

template <typename T>
inline Vector3<T> operator-(const Vector3<T>& v){
  return Vector3<T>(-v.x, -v.y, -v.z );
}

}

#endif // VECTOR3_H