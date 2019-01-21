#ifndef COM_VECTOR_H
#define COM_VECTOR_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "UT/UT_Vector3.h"

class COM_Vector3: public UT_Vector3 {
	public:
		COM_Vector3(): UT_Vector3() {}
		COM_Vector3(double x): UT_Vector3(x, x, x) {};
		COM_Vector3(double x, double y, double z): UT_Vector3(x, y, z) {};
		COM_Vector3(boost::python::list& list);

		void setToFromList(boost::python::list& values);
};

#endif