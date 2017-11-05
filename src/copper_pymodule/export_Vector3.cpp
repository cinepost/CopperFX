#include <boost/python.hpp>
#include <boost/format.hpp>

#include "Math/Vector3.h"

double Vector3_x(Vector3 const &self) {
	return self[0];
}

double Vector3_y(Vector3 const &self) {
	return self[1];
}

double Vector3_z(Vector3 const &self) {
	return self[2];
}


void setVector3FromList(Vector3& vec, boost::python::list& values) {
	if ( boost::python::len(values) == 3 ) {
		vec.set(boost::python::extract<double>(values[0]), boost::python::extract<double>(values[1]), boost::python::extract<double>(values[2]));
	} else {
		throw std::invalid_argument( "Invalid size." );
	}
}

static std::string Vector3__str__(Vector3 const &self) {
	boost::format formater("[%f, %f, %f]");
	formater % self[0] % self[1] % self[2];
	return formater.str();
}

static std::string Vector3__repr__(Vector3 const &self) {
	boost::format formater("<hou.Vector3 %s>");
    formater % Vector3__str__(self);
    return formater.str();
}

namespace hou {
	void export_Vector3() {
		boost::python::class_<Vector3>("Vector3")
			.def(boost::python::init<double>())
			.def(boost::python::init<double, double, double>())
			.def("x", Vector3_x)
			.def("y", Vector3_y)
			.def("z", Vector3_y)
			.def("setTo", &setVector3FromList)
			.def("length", &Vector3::length)
			.def("lengthSquared", &Vector3::lengthSquared)
			.def("normalized", &Vector3::normalized)
			.def("distanceTo", &Vector3::distance)
			.def("__str__", Vector3__str__)
			.def("__repr__", Vector3__repr__)
			//.def( "__getitem__", &Vector3::operator[], boost::python::arg( "index" ), boost::python::return_internal_reference<>())
			;
	}
}