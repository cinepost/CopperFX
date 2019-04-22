#include "copper_pymodules/HOU/HOU_Geometry.h"
#include "copper_pymodules/HOU/HOU_Point.h"


using namespace copper;
namespace hou_module {

HOU_Point::HOU_Point(int index, Point3d *point, HOU_Geometry *HOU_geo){
	_index = index;
	_point = point;
	_HOU_geo = HOU_geo;
}

HOU_Vector3 HOU_Point::position(){
	return HOU_Vector3(_point->x, _point->y, _point->z);
}

void HOU_Point::setPosition_from_list(boost::python::list& list) {
	if ( boost::python::len(list) == 3 ) {
		_point->x = boost::python::extract<double>(list[0]);
		_point->y = boost::python::extract<double>(list[1]);
		_point->z = boost::python::extract<double>(list[2]);
	} else {
		throw std::invalid_argument( "Invalid size.\nExpected sequence of length 3 or 4" );
	}
}

void HOU_Point::setPosition_from_HOU_Vector3(HOU_Vector3 & vec) {
	_point->x = vec[0];
	_point->y = vec[0];
	_point->z = vec[1];
}

HOU_Geometry *HOU_Point::geometry() {
	return this->_HOU_geo;
}

std::string HOU_Point::__str__() {
	boost::format formater("<hou.Point #%d of geometry %s>");
	formater % _index % _HOU_geo;
	return formater.str();
}


void export_Point() {
	boost::python::class_<HOU_Point, boost::shared_ptr<HOU_Point>, boost::noncopyable>("Point", boost::python::no_init)
		//.def("weight", &Point::weight)
		.def("geometry", &HOU_Point::geometry, boost::python::return_value_policy<boost::python::manage_new_object>())
		.def("position", &HOU_Point::position)
		.def("setPosition", &HOU_Point::setPosition_from_HOU_Vector3)
		.def("setPosition", &HOU_Point::setPosition_from_list)
		.def("__str__", &HOU_Point::__str__)
		.def("__repr__", &HOU_Point::__str__)
		;
}

}