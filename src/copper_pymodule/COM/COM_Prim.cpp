#include "copper_pymodule/COM/COM_Prim.h"


namespace copper_pymodule {
	void export_Prim() {
		boost::python::class_<COM_Prim, boost::shared_ptr<COM_Prim>>("Vector3", boost::python::no_init)
			//.def("addVertex", &COM_Prim::addVertex)
			;
	}
}