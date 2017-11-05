#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "Math/Vector3.h"

void setVector3FromList(Vector3& vec, boost::python::list& values) {
	if ( boost::python::len(values) == 3 ) {
		vec.setTo(boost::python::extract<double>(values[0]), boost::python::extract<double>(values[1]), boost::python::extract<double>(values[2]));
	} else {
		throw std::invalid_argument( "Invalid size." );
	}
}

namespace hou {
	void export_Vector3() {
		boost::python::class_<Vector3>("Vector3")
			.def("x", &Vector3::x)
			.def("y", &Vector3::y)
			.def("z", &Vector3::z)
			.def("setTo", &setVector3FromList)
			//.def( "__getitem__", &Vector3::operator[], boost::python::arg( "index" ), boost::python::return_internal_reference<>())
			;
	}
}