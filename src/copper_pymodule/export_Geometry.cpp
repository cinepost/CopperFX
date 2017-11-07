#include <boost/python.hpp>

#include "copper_pymodule.h"
#include "Geometry/Point.h"
#include "Geometry/Geometry.h"

std::vector<Point> Geometry_points(Geometry &geo) {
	return *geo.points();
};

Point *Geometry_createPoint(Geometry &geo) {
	return geo.createPoint();
};


namespace hou {
	void export_Geometry() {
		boost::python::class_<Geometry>("Geometry")
			.def("freeze", &Geometry::freeze, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("points", &Geometry_points)
			.def("createPoint", &Geometry_createPoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("numPoints", &Geometry::numPoints)
			.def("name", &Geometry::name)
			.def("setName", &Geometry::setName)
			;

		boost::python::to_python_converter<std::vector<Point, std::allocator<Point> >, vector_to_python_tuple<Point> >();
	}
}