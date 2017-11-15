#include "HOU_Point.h"

HOU_Point::HOU_Point(Point * point, Geometry *geo){
	this->point = point;
	this->geo = geo;
}

Vector3 HOU_Point::position(){
	return point->position();
}

void HOU_Point::setPosition_from_list(boost::python::list& values) {
	if ( boost::python::len(values) == 3 ) {
		point->setPosition(boost::python::extract<double>(values[0]), boost::python::extract<double>(values[1]), boost::python::extract<double>(values[2]));
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void HOU_Point::setPosition_from_Vector3(Vector3 & vec) {
	point->setPosition(vec);
}

boost::shared_ptr<Geometry> HOU_Point::geometry() {
	return boost::shared_ptr<Geometry>(this->geo);
}

namespace hou {
	void export_Point() {
		boost::python::class_<HOU_Point, boost::shared_ptr<HOU_Point>, boost::noncopyable>("Point", boost::python::no_init)
			//.def("weight", &Point::weight)
			.def("geometry", &HOU_Point::geometry)
			.def("position", &HOU_Point::position)
			.def("setPosition", &HOU_Point::setPosition_from_Vector3)
			.def("setPosition", &HOU_Point::setPosition_from_list)
			;
	}
}