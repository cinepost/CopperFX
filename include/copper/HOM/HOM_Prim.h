#ifndef __HOU_Prim_h__
#define __HOU_Prim_h__

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "GEO/GEO_Geometry.h"
#include "GEO/Prim.h"
#include "HOM/HOM_Prim.h"
#include "HOM/HOM_Point.h"
#include "HOM/HOM_Vertex.h"

class HOM_Prim: public Prim {
	public:
		HOM_Vertex *addVertex(HOM_Point *pt);

	private:
		GEO_Geometry *_geo;
};

#endif