#include "HOU_Point.h"

HOU_Point::HOU_Point(int index, Point * point, Geometry *geo){
	this->index = index;
	this->point = point;
	this->geo = geo;
}

HOU_Vector3 HOU_Point::position(){
	return HOU_Vector3(point->x, point->y, point->z);
}

void HOU_Point::setPosition_from_list(boost::python::list& list) {
	if ( boost::python::len(list) == 3 ) {
		point->x = boost::python::extract<double>(list[0]);
		point->y = boost::python::extract<double>(list[1]);
		point->z = boost::python::extract<double>(list[2]);
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void HOU_Point::setPosition_from_HOU_Vector3(HOU_Vector3 & vec) {
	point->x = vec[0];
	point->y = vec[0];
	point->z = vec[1];
}

boost::shared_ptr<Geometry> HOU_Point::geometry() {
	return boost::shared_ptr<Geometry>(this->geo);
}

std::string HOU_Point::__str__() {
	boost::format formater("<hou.Point #%d of geometry %s>");
	formater % index % geo;
	return formater.str();
}

namespace hou {
	void export_Point() {
		boost::python::class_<HOU_Point, boost::shared_ptr<HOU_Point>, boost::noncopyable>("Point", boost::python::no_init)
			//.def("weight", &Point::weight)
			.def("geometry", &HOU_Point::geometry)
			.def("position", &HOU_Point::position)
			.def("setPosition", &HOU_Point::setPosition_from_HOU_Vector3)
			.def("setPosition", &HOU_Point::setPosition_from_list)
			.def("__str__", &HOU_Point::__str__)
			.def("__repr__", &HOU_Point::__str__)
			;
	}
}