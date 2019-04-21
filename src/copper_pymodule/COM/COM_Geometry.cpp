//#include "copper_pymodule/COM/COM_Module.h"
#include "copper_pymodule/COM/COM_Point.h"
#include "copper_pymodule/COM/COM_Geometry.h"

COM_Geometry::COM_Geometry() {
	this->_geo = new GEO_Geometry();
}

COM_Geometry::COM_Geometry(GEO_Geometry *geo) {
	this->_geo = geo;
}

PyObject* COM_Geometry::points() {
	std::vector<Point3d *> *points = _geo->points();
	boost::python::tuple* l = new boost::python::tuple();

	std::vector<Point3d *>::iterator it;
	int i = 0;
	for(it = points->begin(); it != points->end(); it++, i++ ) {
		(*l) += boost::python::make_tuple(boost::shared_ptr<COM_Point>(new COM_Point(i, *it, this)));
	}

    return l->ptr();
};

COM_Point *COM_Geometry::createPoint() {
	return new COM_Point(_geo->points()->size(), _geo->createPoint(), this);
}

namespace copper_pymodule {

	void export_Geometry() {
		boost::python::class_<COM_Geometry, boost::noncopyable>("Geometry")
			//.def("freeze", &COM_Geometry::freeze, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("points", &COM_Geometry::points)
			.def("createPoint", &COM_Geometry::createPoint, boost::python::return_value_policy<boost::python::manage_new_object>())
			;

		//boost::python::to_python_converter<std::vector<Point*, std::allocator<Point*> >, vector_to_python_tuple<Point*> >();
		//boost::python::to_python_converter<COM_Point *, COM_object_ptr_to_python<COM_Point>>();
	}

}