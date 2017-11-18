#ifndef __export_Point_h__
#define __export_Point_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "GEO/GEO_Geometry.h"
#include "GEO/Point.h"

#include "HOM/HOM_Geometry.h"
#include "HOM_Vector3.h"

class HOM_Geometry;

class HOM_Point {
	public:
		HOM_Point(int index, Point * point, HOM_Geometry *hom_geo);

		HOM_Vector3 position();
		void setPosition_from_list(boost::python::list& list);
		void setPosition_from_HOM_Vector3(HOM_Vector3 &vec);
		HOM_Geometry *geometry();

		std::string __str__();

	private:
		int _index;
		Point *_point;
		HOM_Geometry *_hom_geo;
};

#endif