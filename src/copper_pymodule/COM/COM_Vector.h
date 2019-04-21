#ifndef COM_VECTOR_H
#define COM_VECTOR_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/Util/Vector3.h"

using namespace copper;

class COM_Vector3: public Vector3<double> {
	public:
		COM_Vector3(): Vector3() {}
		COM_Vector3(double x): Vector3(x, x, x) {};
		COM_Vector3(double x, double y, double z): Vector3(x, y, z) {};
		COM_Vector3(boost::python::list& list);

		void setToFromList(boost::python::list& values);
};

#endif