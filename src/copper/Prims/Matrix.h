#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <vector>
#include <stdexcept>
#include <math.h>

#include "wykobi/wykobi.hpp"
#include "wykobi/wykobi_matrix.hpp"

#include "Point.h"
#include "Vector.h"


namespace copper {

template<class T>
class Matrix4: public wykobi::matrix<T,4,4> { 
	public:
		//Matrix4(): wykobi::matrix<T,4,4> {};
		//Vector2(T x, T y): wykobi::vector2d<T>(x, y) {};
		//Vector2(const wykobi::vector2d<T>& v): wykobi::vector2d<T>(v.x, v.y) {};

		inline static Matrix4<T> lookAt(Point3<T> eye, Point3<T> target, Vector3<T> up, bool inverted=false) {
			Vector3<T> z = (eye - target).normalized();
			Vector3<T> y = up;
			Vector3<T> x = (y ^ z).normalized();
			y = (z ^ x).normalized();

			Matrix4<T> m;
			m.identity();

			//m(0,0) = x;
			//m(1,1) = y;
			//m(2,2) = z;
			//, y ,z]

			if(inverted) {
			    return m * Matrix4<T>::translationMatrix( eye );
			} else {
			    wykobi::transpose(m);
			    return m * Matrix4<T>::translationMatrix( -eye );
			}
		}


		inline static Matrix4<T> translationMatrix(const Point3<T> p) {
			Matrix4<T> m;
			m.identity();
			m(0,3) = p.x;
			m(1,3) = p.y;
			m(2,3) = p.z;
			return m;
		}

		inline static Matrix4<T> translationMatrix(const Vector3<T> v) {
			Matrix4<T> m;
			m.identity();
			m(0,3) = v.x;
			m(1,3) = v.y;
			m(2,3) = v.z;
			return m;
		}

		// build rotation matrix in radians around axis at origin
	  inline static Matrix4<T> rotationMatrix(T angle, Vector3<T> axis, Point3<T> origin=0) {
			Matrix4<T> m;

			T cos0 = cos(angle);
			T sin0 = sin(angle);

			T u=axis.x; T v=axis.y; T w=axis.z;
			T l = (u*u + v * v + w * w);
			T ll = sqrt(l);
			T u2 = u * u;
    	T v2 = v * v;
    	T w2 = w * w;

			m[0] = (u2 + (v2 + w2) * cos0) / l;
			m[1] = (u * v * (1 - cos0) - w * ll * sin0) / l;
			m[2] = (u * w * (1 - cos0) + v * ll * sin0) / l;
			m[3] = 0.0; 

			m[4] = (u * v * (1 - cos0) + w * ll * sin0) / l;
			m[5] = (v2 + (u2 + w2) * cos0) / l;
			m[6] = (v * w * (1 - cos0) - u * ll * sin0) / l;
			m[7] = 0.0; 

			m[8] = (u * w * (1 - cos0) - v * ll * sin0) / l;
			m[9] = (v * w * (1 - cos0) + u * ll * sin0) / l;
			m[10] = (w2 + (u2 + v2) * cos0) / l;
			m[11] = 0.0; 

			m[12] = 0.0;
			m[13] = 0.0;
			m[14] = 0.0;
			m[15] = 1.0;

	    return m;
	  }
};

typedef Matrix4<int> Matrix4i;
typedef Matrix4<float> Matrix4f;
typedef Matrix4<double> Matrix4d;


// Overloaded operators
template <typename T>
inline Matrix4<T> operator*(const Matrix4<T>& m1, const Matrix4<T>& m2){
  Matrix4<T> mm;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mm(i,j) = m1(i,0) * m2(0,j) + m1(i,1) * m2(1,j) + m1(i,2) * m2(2,j) + m1(i,3) * m2(3,j);
    }
  }
  return mm;
}

template <typename T>
inline Vector3<T> operator*(const Matrix4<T>& m, const Vector3<T>& v){
  Vector3<T> vv;
  vv.x = m[0] * v.x + m[1] * v.y + m[2] * v.z;
  vv.y = m[4] * v.x + m[5] * v.y + m[6] * v.z;
  vv.z = m[8] * v.x + m[9] * v.z + m[10] * v.z;
  return vv;
}

}

#endif // MATRIX_H