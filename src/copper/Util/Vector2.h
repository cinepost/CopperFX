#ifndef VECTOR2_H
#define VECTOR2_H

#include <vector>
#include <stdexcept>
#include <math.h>

#include "wykobi/wykobi.hpp"


namespace copper {

template<class T>
class Vector2: public wykobi::vector2d<T> { 
	public:
		Vector2(): wykobi::vector2d<T>() {};
		Vector2(T x, T y): wykobi::vector2d<double>(x, y) {};
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

}

#endif // VECTOR2_H