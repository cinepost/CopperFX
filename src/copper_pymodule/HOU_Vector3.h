#ifndef __HOU_Vector3_h__
#define __HOU_Vector3_h__

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/Math/Vector3.h"

class HOU_Vector3: public Vector3 {
	public:
		HOU_Vector3(): Vector3() {}
		HOU_Vector3(double x): Vector3(x, x, x) {};
		HOU_Vector3(double x, double y, double z): Vector3(x, y, z) {};
		HOU_Vector3(boost::python::list& list);

		void setToFromList(boost::python::list& values);
};

#endif