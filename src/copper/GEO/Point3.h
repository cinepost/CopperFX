#ifndef POINT_3_H
#define POINT_3_H

#include <stdexcept>
#include <vector>
#include <iostream>

#include "wykobi/wykobi.hpp"

namespace copper {

template<class T>
class Point3: public wykobi::point3d<T> { };

typedef Point3<int> Point3i;
typedef Point3<float> Point3f;
typedef Point3<double> Point3d;

}

#endif // POINT_3_H