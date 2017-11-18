#include "HOM/HOM_Prim.h"


namespace hou {
	void export_Prim() {
		boost::python::class_<HOM_Prim, boost::shared_ptr<HOM_Prim>>("Vector3", boost::python::no_init)
			//.def("addVertex", &HOM_Prim::addVertex)
			;
	}
}