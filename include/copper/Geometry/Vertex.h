#ifndef __Vertex_h__
#define __Vertex_h__

#include <vector>
#include <stdexcept>
#include <math.h>

#include "copper/Geometry/Point.h"
//#include "wykobi/wykobi.hpp"

class Vertex: { 
	public:
		Vertex(Point *pt);

	private:
		Point *_pt;
};

#endif