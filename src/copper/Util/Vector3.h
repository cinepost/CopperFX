#ifndef VECTOR3_H
#define VECTOR3_H

#include <vector>
#include <stdexcept>
#include <math.h>

#include "wykobi/wykobi.hpp"


namespace copper {

template<class T>
class Vector3: public wykobi::vector3d<T> { 
	public:
		Vector3(): wykobi::vector3d<T>() {};
		Vector3(T x, T y, T z): wykobi::vector3d<T>(x, y, z) {};
};

typedef Vector3<int> Vector3i;
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

}

#endif // VECTOR3_H