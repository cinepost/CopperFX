#ifndef __HOM_Geometry_h__
#define __HOM_Geometry_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>

//#include "copper_pymodule.h"
#include "GEO/Point.h"
#include "GEO/GEO_Geometry.h"

#include "HOM_Point.h"

class HOM_Point;

class HOM_Geometry {
	public:
		HOM_Geometry();
		HOM_Geometry(GEO_Geometry *geo);

		PyObject* points();
		HOM_Point *createPoint();

	private:
		GEO_Geometry *_geo;
};

#endif