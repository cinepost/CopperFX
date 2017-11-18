#ifndef __UT_Vector2_h__
#define __UT_Vector2_h__

#include <vector>
#include <stdexcept>
#include <math.h>

#include "wykobi/wykobi.hpp"

class UT_Vector2: public wykobi::vector2d<double> { 
	public:
		UT_Vector2(): wykobi::vector2d<double>() {};
		UT_Vector2(double x, double y): wykobi::vector2d<double>(x, y) {};
};

#endif