#include "copper_pymodules/HOU/HOU_Prim.h"

using namespace copper;
namespace hou_module {

void export_Prim() {
	boost::python::class_<HOU_Prim, boost::shared_ptr<HOU_Prim>>("Vector3", boost::python::no_init)
		//.def("addVertex", &HOU_Prim::addVertex)
		;
}

}