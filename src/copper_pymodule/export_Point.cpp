#include <boost/python.hpp>

#include "Geometry/Point.h"

void setPointPositionFromList(Point& pt, boost::python::list& values) {
	if ( boost::python::len(values) == 3 ) {
		pt.setPosition(boost::python::extract<double>(values[0]), boost::python::extract<double>(values[1]), boost::python::extract<double>(values[2]));
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void (Point::*setPointPositionFromVector3)(Vector3 &) = &Point::setPosition;

namespace hou {
	void export_Point() {
		boost::python::class_<Point>("Point", boost::python::no_init)
			.def("weight", &Point::weight)
			.def("geometry", &Point::geometry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("position", &Point::position)
			.def("setPosition", setPointPositionFromVector3)
			.def("setPosition", setPointPositionFromList)
			;
	}
}