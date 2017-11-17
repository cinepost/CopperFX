#ifndef __HOU_Prim_h__
#define __HOU_Prim_h__

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/Geometry/Geometry.h"
#include "copper/Geometry/Prim.h"

class HOM_Prim: public Prim {
	public:
		HOM_Vertex *addVertex(HOM_Point *pt);

	private:
		Geometry *geo;
};

#endif