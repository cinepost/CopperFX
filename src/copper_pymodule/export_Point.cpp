#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "Geometry/Point.h"

void Point_setPosition_from_list(Point& pt, boost::python::list& values) {
	if ( boost::python::len(values) == 3 ) {
		pt.setPosition(boost::python::extract<double>(values[0]), boost::python::extract<double>(values[1]), boost::python::extract<double>(values[2]));
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void (Point::*Point_setPosition_from_Vector3)(Vector3 &) = &Point::setPosition;

namespace hou {
	void export_Point() {
		boost::python::class_<Point>("Point", boost::python::no_init)
			.def("weight", &Point::weight)
			.def("geometry", &Point::geometry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("position", &Point::position)
			.def("setPosition", Point_setPosition_from_Vector3)
			.def("setPosition", Point_setPosition_from_list)
			;

		// wrap vector of Points
		//boost::python::class_<std::vector<Point>>("PointsList")
		//	.def(boost::python::vector_indexing_suite<std::vector<Point>>());
	}
}