#include <boost/python.hpp>

#include "Geometry/Geometry.h"

namespace hou {
	void export_Geometry() {
		boost::python::class_<Geometry, boost::noncopyable>("Geometry")
			.def("freeze", &Geometry::freeze, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("points", &Geometry::points, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createPoint", &Geometry::createPoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	}
}