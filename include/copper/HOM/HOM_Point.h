#ifndef __export_Point_h__
#define __export_Point_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "GEO/Geometry.h"
#include "GEO/Point.h"

#include "HOM_Vector3.h"

class HOM_Point {
	public:
		HOM_Point(int index, Point * pt, Geometry *geo);

		HOM_Vector3 position();
		void setPosition_from_list(boost::python::list& list);
		void setPosition_from_HOM_Vector3(HOM_Vector3 &vec);
		boost::shared_ptr<Geometry> geometry();

		std::string __str__();

	private:
		int index;
		Point *point;
		Geometry *geo;
};

#endif