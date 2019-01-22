#include "copper_pymodule/COM/COM_Geometry.h"
#include "copper_pymodule/COM/COM_Point.h"


COM_Point::COM_Point(int index, Point *point, COM_Geometry *com_geo){
	_index = index;
	_point = point;
	_com_geo = com_geo;
}

COM_Vector3 COM_Point::position(){
	return COM_Vector3(_point->x, _point->y, _point->z);
}

void COM_Point::setPosition_from_list(boost::python::list& list) {
	if ( boost::python::len(list) == 3 ) {
		_point->x = boost::python::extract<double>(list[0]);
		_point->y = boost::python::extract<double>(list[1]);
		_point->z = boost::python::extract<double>(list[2]);
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void COM_Point::setPosition_from_COM_Vector3(COM_Vector3 & vec) {
	_point->x = vec[0];
	_point->y = vec[0];
	_point->z = vec[1];
}

COM_Geometry *COM_Point::geometry() {
	return this->_com_geo;
}

std::string COM_Point::__str__() {
	boost::format formater("<hou.Point #%d of geometry %s>");
	formater % _index % _com_geo;
	return formater.str();
}

namespace copper_pymodule {

	void export_Point() {
		boost::python::class_<COM_Point, boost::shared_ptr<COM_Point>, boost::noncopyable>("Point", boost::python::no_init)
			//.def("weight", &Point::weight)
			.def("geometry", &COM_Point::geometry, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("position", &COM_Point::position)
			.def("setPosition", &COM_Point::setPosition_from_COM_Vector3)
			.def("setPosition", &COM_Point::setPosition_from_list)
			.def("__str__", &COM_Point::__str__)
			.def("__repr__", &COM_Point::__str__)
			;
	}

}