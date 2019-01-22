#include "copper_pymodule/COM/COM_Vector.h"

COM_Vector3::COM_Vector3(boost::python::list& list) {
	setToFromList(list);
}

void COM_Vector3::setToFromList(boost::python::list& list) {
	if ( boost::python::len(list) == 3 ) {
		this->x = boost::python::extract<double>(list[0]);
		this->y = boost::python::extract<double>(list[1]);
		this->z = boost::python::extract<double>(list[2]);
	} else {
		throw std::invalid_argument( "Invalid size." );
	}
}

static std::string COM_Vector3__str__(COM_Vector3 const &self) {
	boost::format formater("[%f, %f, %f]");
	formater % self[0] % self[1] % self[2];
	return formater.str();
}

static std::string COM_Vector3__repr__(COM_Vector3 const &self) {
	boost::format formater("<COM.Vector3 %s>");
    formater % COM_Vector3__str__(self);
    return formater.str();
}


namespace copper_pymodule {
  void export_Vector2() {

  }

	void export_Vector3() {
		boost::python::class_<COM_Vector3, boost::shared_ptr<COM_Vector3>>("Vector3")
			.def(boost::python::init<double>())
			.def(boost::python::init<double, double, double>())
			.def(boost::python::init<boost::python::list&>())
			.def("setTo", &COM_Vector3::setToFromList)
			//.def("length", &Vector3::length)
			//.def("lengthSquared", &Vector3::lengthSquared)
			//.def("normalized", &Vector3::normalized)
			//.def("distanceTo", &Vector3::distance)
			.def("__str__", &COM_Vector3__str__)
			.def("__repr__", &COM_Vector3__repr__)
			//.def( "__getitem__", &Vector3::operator[], boost::python::arg( "index" ), boost::python::return_internal_reference<>())
			;
	}
}