#ifndef HOU_POINT_H
#define HOU_POINT_H

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "copper/OpData/GeometryOpData.h"
#include "copper/Prims/Point3.h"

#include "copper_pymodules/HOU/HOU_Geometry.h"
#include "copper_pymodules/HOU/HOU_Vector.h"


using namespace copper;
namespace hou_module {

class HOU_Geometry;

class HOU_Point {
	public:
		HOU_Point(int index, Point3d *point, HOU_Geometry *HOU_geo);

		HOU_Vector3 position();
		void setPosition_from_list(boost::python::list& list);
		void setPosition_from_HOU_Vector3(HOU_Vector3 &vec);
		HOU_Geometry *geometry();

		std::string __str__();

	private:
		int _index;
		Point3d *_point;
		HOU_Geometry *_HOU_geo;

};

void export_Point();

}

#endif