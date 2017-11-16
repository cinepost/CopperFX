#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/Math/Vector2.h"

double Vector2_x(Vector2 const &self) {
	return self[0];
}

double Vector2_y(Vector2 const &self) {
	return self[1];
}

void setVector2FromList(Vector2 &vec, boost::python::list const &values) {
	if ( boost::python::len(values) == 2 ) {
		vec.set(boost::python::extract<double>(values[0]), boost::python::extract<double>(values[1]));
	} else {
		throw std::invalid_argument( "Invalid size." );
	}
}

static std::string Vector2__str__(Vector2 const &self) {
	boost::format formater("[%f, %+f]");
	formater % self[0] % self[1];
	return formater.str();
}

static std::string Vector2__repr__(Vector2 const &self) {
	boost::format formater("<hou.Vector2 %s>");
    formater % Vector2__str__(self);
    return formater.str();
}

namespace hou {
	void export_Vector2() {
		boost::python::class_<Vector2>("Vector2")
			.def(boost::python::init<double, double>())
			.def("x", Vector2_x)
			.def("y", Vector2_y)
			.def("setTo", &setVector2FromList)
			.def("length", &Vector2::length)
			.def("lengthSquared", &Vector2::lengthSquared)
			.def("normalized", &Vector2::normalized)
			.def("distanceTo", &Vector2::distance)
			.def("__str__", Vector2__str__)
			.def("__repr__", Vector2__repr__)
			//.def( "__getitem__", &Vector3::operator[], boost::python::arg( "index" ), boost::python::return_internal_reference<>())
			;
	}
}