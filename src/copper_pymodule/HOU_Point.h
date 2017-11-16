#ifndef __export_Point_h__
#define __export_Point_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "copper/Geometry/Geometry.h"
#include "copper/Geometry/Point.h"

#include "HOU_Vector3.h"

class HOU_Point {
	public:
		HOU_Point(int index, Point * pt, Geometry *geo);

		HOU_Vector3 position();
		void setPosition_from_list(boost::python::list& list);
		void setPosition_from_HOU_Vector3(HOU_Vector3 &vec);
		boost::shared_ptr<Geometry> geometry();

		std::string __str__();

	private:
		int index;
		Point *point;
		Geometry *geo;
};

#endif