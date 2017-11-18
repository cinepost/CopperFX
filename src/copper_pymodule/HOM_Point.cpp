#include "HOM/HOM_Geometry.h"
#include "HOM/HOM_Point.h"


HOM_Point::HOM_Point(int index, Point *point, HOM_Geometry *hom_geo){
	_index = index;
	_point = point;
	_hom_geo = hom_geo;
}

HOM_Vector3 HOM_Point::position(){
	return HOM_Vector3(_point->x, _point->y, _point->z);
}

void HOM_Point::setPosition_from_list(boost::python::list& list) {
	if ( boost::python::len(list) == 3 ) {
		_point->x = boost::python::extract<double>(list[0]);
		_point->y = boost::python::extract<double>(list[1]);
		_point->z = boost::python::extract<double>(list[2]);
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void HOM_Point::setPosition_from_HOM_Vector3(HOM_Vector3 & vec) {
	_point->x = vec[0];
	_point->y = vec[0];
	_point->z = vec[1];
}

HOM_Geometry *HOM_Point::geometry() {
	return this->_hom_geo;
}

std::string HOM_Point::__str__() {
	boost::format formater("<hou.Point #%d of geometry %s>");
	formater % _index % _hom_geo;
	return formater.str();
}

namespace hou {
	void export_Point() {
		boost::python::class_<HOM_Point, boost::shared_ptr<HOM_Point>, boost::noncopyable>("Point", boost::python::no_init)
			//.def("weight", &Point::weight)
			.def("geometry", &HOM_Point::geometry, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("position", &HOM_Point::position)
			.def("setPosition", &HOM_Point::setPosition_from_HOM_Vector3)
			.def("setPosition", &HOM_Point::setPosition_from_list)
			.def("__str__", &HOM_Point::__str__)
			.def("__repr__", &HOM_Point::__str__)
			;
	}
}