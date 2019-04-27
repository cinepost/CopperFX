#ifndef POINT_H
#define POINT_H

#include <stdexcept>
#include <vector>
#include <iostream>

#include "wykobi/wykobi.hpp"

namespace copper {

template<class T>
class Vector2;

template<class T>
class Vector3;

template<class T>
class Point3: public wykobi::point3d<T> { 
	public:
		Point3(T x=0.0, T y=0.0, T z=0.0) { this->x =x; this->y=y; this->z=z; };
		Point3(const wykobi::point3d<T>& p): Point3<T>(p.x, p.y, p.z) {};
};

typedef Point3<int> Point3i;
typedef Point3<float> Point3f;
typedef Point3<double> Point3d;


template<class T>
class Point2: public wykobi::point2d<T> {
  public:
		Point2(T x=0.0, T y=0.0) { this->x=x; this->y=y; };
		Point2(const wykobi::point2d<T>& p): Point2<T>(p.x, p.y, p.z) {};
};

typedef Point2<int> Point2i;
typedef Point2<float> Point2f;
typedef Point2<double> Point2d;

// Operators overloading
template <typename T>
inline Vector2<T> operator-(const Point2<T>& p1, const Point2<T>& p2){
  Vector2<T> v;
  v.x = p1.x - p2.x;
  v.y = p1.y - p2.y;
  return v;
}

template <typename T>
inline Vector3<T> operator-(const Point3<T>& p1, const Point3<T>& p2){
  Vector3<T> v;
  v.x = p1.x - p2.x;
  v.y = p1.y - p2.y;
  v.z = p1.z - p2.z;
  return v;
}

template <typename T>
inline Point3<T> operator-(const Point3<T>& p){
  return Point3<T>(-p.x, -p.y, -p.z );
}

}

#endif // POINT_H