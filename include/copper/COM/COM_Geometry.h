#ifndef __COM_Geometry_h__
#define __COM_Geometry_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>

#include "GEO/Point.h"
#include "GEO/GEO_Geometry.h"

#include "COM_Point.h"

class COM_Point;

class COM_Geometry {
	public:
		COM_Geometry();
		COM_Geometry(GEO_Geometry *geo);

		PyObject* points();
		COM_Point *createPoint();

	private:
		GEO_Geometry *_geo;
};

#endif