#include "HOM_Point.h"

HOM_Point::HOM_Point(int index, Point * point, Geometry *geo){
	this->index = index;
	this->point = point;
	this->geo = geo;
}

HOM_Vector3 HOM_Point::position(){
	return HOM_Vector3(point->x, point->y, point->z);
}

void HOM_Point::setPosition_from_list(boost::python::list& list) {
	if ( boost::python::len(list) == 3 ) {
		point->x = boost::python::extract<double>(list[0]);
		point->y = boost::python::extract<double>(list[1]);
		point->z = boost::python::extract<double>(list[2]);
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void HOM_Point::setPosition_from_HOM_Vector3(HOM_Vector3 & vec) {
	point->x = vec[0];
	point->y = vec[0];
	point->z = vec[1];
}

boost::shared_ptr<Geometry> HOM_Point::geometry() {
	return boost::shared_ptr<Geometry>(this->geo);
}

std::string HOM_Point::__str__() {
	boost::format formater("<HOM.Point #%d of geometry %s>");
	formater % index % geo;
	return formater.str();
}

namespace HOM {
	void export_Point() {
		boost::python::class_<HOM_Point, boost::shared_ptr<HOM_Point>, boost::noncopyable>("Point", boost::python::no_init)
			//.def("weight", &Point::weight)
			.def("geometry", &HOM_Point::geometry)
			.def("position", &HOM_Point::position)
			.def("setPosition", &HOM_Point::setPosition_from_HOM_Vector3)
			.def("setPosition", &HOM_Point::setPosition_from_list)
			.def("__str__", &HOM_Point::__str__)
			.def("__repr__", &HOM_Point::__str__)
			;
	}
}