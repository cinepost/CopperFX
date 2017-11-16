#ifndef __Vector3_h__
#define __Vector3_h__

#include <vector>
#include <stdexcept>
#include <math.h>

#include "wykobi/wykobi.hpp"

class Vector3: public wykobi::vector3d<double> { 
	public:
		Vector3(): wykobi::vector3d<double>() {};
		Vector3(double x, double y, double z): wykobi::vector3d<double>(x, y, z) {};
};

#endif