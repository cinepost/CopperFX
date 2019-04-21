#ifndef COM_PRIM_H
#define COM_PRIM_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/GEO/GEO_Geometry.h"
#include "copper/GEO/Prim.h"
#include "copper_pymodule/COM/COM_Prim.h"
#include "copper_pymodule/COM/COM_Point.h"
#include "copper_pymodule/COM/COM_Vertex.h"

class COM_Prim: public Prim {
	public:
		COM_Vertex *addVertex(COM_Point *pt);

	private:
		GEO_Geometry *_geo;
};

#endif