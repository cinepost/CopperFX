//#include "copper_pymodule/COM/HOU_Module.h"
#include "copper_pymodules/HOU/HOU_Point.h"
#include "copper_pymodules/HOU/HOU_Geometry.h"


using namespace copper;
namespace hou_module {

HOU_Geometry::HOU_Geometry() {
	this->_geo = new GeometryOpData();
}

HOU_Geometry::HOU_Geometry(GeometryOpData *geo) {
	this->_geo = geo;
}

PyObject* HOU_Geometry::points() {
	std::vector<Point3d> *points = _geo->points();
	boost::python::tuple* l = new boost::python::tuple();

	std::vector<Point3d>::iterator it;
	int i = 0;
	for(it = points->begin(); it != points->end(); it++, i++ ) {
		(*l) += boost::python::make_tuple(boost::shared_ptr<HOU_Point>(new HOU_Point(i, &*it, this)));
	}

    return l->ptr();
};

HOU_Point *HOU_Geometry::createPoint() {
	return new HOU_Point(_geo->points()->size(), _geo->createPoint(), this);
}


void export_Geometry() {
	boost::python::class_<HOU_Geometry, boost::noncopyable>("Geometry")
		//.def("freeze", &HOU_Geometry::freeze, boost::python::return_value_policy<boost::python::manage_new_object>())
		.def("points", &HOU_Geometry::points)
		.def("createPoint", &HOU_Geometry::createPoint, boost::python::return_value_policy<boost::python::manage_new_object>())
		;

	//boost::python::to_python_converter<std::vector<Point*, std::allocator<Point*> >, vector_to_python_tuple<Point*> >();
	//boost::python::to_python_converter<HOU_Point *, HOU_object_ptr_to_python<HOU_Point>>();
}

}