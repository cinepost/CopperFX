#ifndef HOU_VECTOR_H
#define HOU_VECTOR_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/Util/Vector3.h"

using namespace copper;

namespace hou_module {

class HOU_Vector3: public Vector3d {
	public:
		HOU_Vector3(): Vector3d() {}
		HOU_Vector3(double x): Vector3d(x, x, x) {};
		HOU_Vector3(double x, double y, double z): Vector3d(x, y, z) {};
		HOU_Vector3(boost::python::list& list);

		void setToFromList(boost::python::list& values);
};

}

#endif