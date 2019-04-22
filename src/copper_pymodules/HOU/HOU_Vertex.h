#ifndef HOU_VERTEX_H
#define HOU_VERTEX_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/Prims/Vertex.h"

using namespace copper;

namespace hou_module {

class HOU_Vertex {
	public:
		HOU_Vertex(Vertex *vtx);

	private:
		Vertex *vtx;
};

}

#endif