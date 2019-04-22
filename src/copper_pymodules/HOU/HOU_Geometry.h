#ifndef __HOU_Geometry_h__
#define __HOU_Geometry_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>

#include "copper/Prims/Point3.h"
#include "copper/OpData/GeometryOpData.h"

#include "copper_pymodules/HOU/HOU_Point.h"


using namespace copper;
namespace hou_module {

class HOU_Point;

class HOU_Geometry {
	public:
		HOU_Geometry();
		HOU_Geometry(GeometryOpData *geo);

		PyObject* points();
		HOU_Point *createPoint();

	private:
		GeometryOpData *_geo;
};

void export_Geometry();

}

#endif