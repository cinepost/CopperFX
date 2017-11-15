#ifndef __export_Point_h__
#define __export_Point_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "Geometry/Geometry.h"
#include "Geometry/Point.h"

class HOU_Point {
	public:
		HOU_Point(Point * pt, Geometry *geo);

		Vector3 position();
		void setPosition_from_list(boost::python::list& values);
		void setPosition_from_Vector3(Vector3 & vec);
		boost::shared_ptr<Geometry> geometry();

	private:
		Point *point;
		Geometry *geo;
};

#endif