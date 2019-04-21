#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <stdexcept>
#include <math.h>

#include "copper/GEO/Vertex.h"


namespace copper {

class Prim { 
	public:
		std::vector<Vertex*> *vertices();

		Vertex *addVertex(Point3d *pt);

	private:
		std::vector<Vertex*> _vertices;
};

}

#endif // PRIM_H