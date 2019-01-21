#ifndef COM_PRIM_H
#define COM_PRIM_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "GEO/GEO_Geometry.h"
#include "GEO/Prim.h"
#include "COM/COM_Prim.h"
#include "COM/COM_Point.h"
#include "COM/COM_Vertex.h"

class COM_Prim: public Prim {
	public:
		COM_Vertex *addVertex(COM_Point *pt);

	private:
		GEO_Geometry *_geo;
};

#endif