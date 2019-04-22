#ifndef HOU_PRIM_H
#define HOU_PRIM_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/OpData/GeometryOpData.h"
#include "copper/Prims/Prim.h"
#include "copper_pymodules/HOU/HOU_Prim.h"
#include "copper_pymodules/HOU/HOU_Point.h"
#include "copper_pymodules/HOU/HOU_Vertex.h"


using namespace copper;
namespace hou_module {

class HOU_Prim: public Prim {
	public:
		HOU_Vertex *addVertex(HOU_Point *pt);

	private:
		GeometryOpData *_geo;
};

void export_Prim();

}

#endif