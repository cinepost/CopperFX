#ifndef __HOU_Vertex_h__
#define __HOU_Vertex_h__

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "GEO/Vertex.h"

class HOM_Vertex {
	public:
		HOM_Vertex(Vertex *vtx);

	private:
		Vertex *vtx;
};

#endif