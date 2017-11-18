#ifndef __HOU_Vector3_h__
#define __HOU_Vector3_h__

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "UT/UT_Vector3.h"

class HOM_Vector3: public UT_Vector3 {
	public:
		HOM_Vector3(): UT_Vector3() {}
		HOM_Vector3(double x): UT_Vector3(x, x, x) {};
		HOM_Vector3(double x, double y, double z): UT_Vector3(x, y, z) {};
		HOM_Vector3(boost::python::list& list);

		void setToFromList(boost::python::list& values);
};

#endif