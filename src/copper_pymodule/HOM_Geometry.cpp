#include "HOM_Geometry.h"

PyObject* HOM_Geometry_points(Geometry &geo) {
	std::vector<Point *> *points = geo.points();
	boost::python::tuple* l = new boost::python::tuple();

	std::vector<Point *>::iterator it;
	int i = 0;
	for(it = points->begin(); it != points->end(); it++, i++ ) {
		(*l) += boost::python::make_tuple(boost::shared_ptr<HOM_Point>(new HOM_Point(i, *it, &geo)));
	}

    return l->ptr();
};

boost::shared_ptr<HOM_Point> HOM_Geometry_createPoint(Geometry & geo) {
	return boost::shared_ptr<HOM_Point>(new HOM_Point(geo.points()->size(), geo.createPoint(), &geo));
}

namespace HOM {
	void export_Geometry() {
		boost::python::class_<Geometry, boost::shared_ptr<Geometry>, boost::noncopyable>("Geometry")
			.def("freeze", &Geometry::freeze, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("points", &HOM_Geometry_points)
			.def("createPoint", &HOM_Geometry_createPoint)
			;

		//boost::python::to_python_converter<std::vector<Point*, std::allocator<Point*> >, vector_to_python_tuple<Point*> >();
	}
}