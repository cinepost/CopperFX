#include "HOM/HOM_Module.h"
#include "HOM/HOM_Point.h"
#include "HOM/HOM_Geometry.h"

HOM_Geometry::HOM_Geometry() {
	this->_geo = new GEO_Geometry();
}

HOM_Geometry::HOM_Geometry(GEO_Geometry *geo) {
	this->_geo = geo;
}

PyObject* HOM_Geometry::points() {
	std::vector<Point *> *points = _geo->points();
	boost::python::tuple* l = new boost::python::tuple();

	std::vector<Point *>::iterator it;
	int i = 0;
	for(it = points->begin(); it != points->end(); it++, i++ ) {
		(*l) += boost::python::make_tuple(boost::shared_ptr<HOM_Point>(new HOM_Point(i, *it, this)));
	}

    return l->ptr();
};

HOM_Point *HOM_Geometry::createPoint() {
	return new HOM_Point(_geo->points()->size(), _geo->createPoint(), this);
}

namespace hou {
	void export_Geometry() {
		boost::python::class_<HOM_Geometry, boost::noncopyable>("Geometry")
			//.def("freeze", &HOM_Geometry::freeze, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("points", &HOM_Geometry::points)
			.def("createPoint", &HOM_Geometry::createPoint, boost::python::return_value_policy<boost::python::manage_new_object>())
			;

		//boost::python::to_python_converter<std::vector<Point*, std::allocator<Point*> >, vector_to_python_tuple<Point*> >();
		//boost::python::to_python_converter<HOM_Point *, hom_object_ptr_to_python<HOM_Point>>();
	}
}