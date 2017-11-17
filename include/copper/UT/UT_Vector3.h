#ifndef __UT_Vector3_h__
#define __UT_Vector3_h__

#include <vector>
#include <stdexcept>
#include <math.h>

#include "wykobi/wykobi.hpp"

class UT_Vector3: public wykobi::vector3d<double> { 
	public:
		UT_Vector3(): wykobi::vector3d<double>() {};
		UT_Vector3(double x, double y, double z): wykobi::vector3d<double>(x, y, z) {};
};

#endif