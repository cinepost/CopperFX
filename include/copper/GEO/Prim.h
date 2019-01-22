#ifndef __Prim_h__
#define __Prim_h__

#include <vector>
#include <stdexcept>
#include <math.h>

//#include "wykobi/wykobi.hpp"

#include "copper/GEO/Vertex.h"

class Prim { 
	public:
		std::vector<Vertex*> *vertices();

		Vertex *addVertex(Point *pt);

	private:
		std::vector<Vertex*> _vertices;
};

#endif