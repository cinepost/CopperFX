#ifndef COM_VERTEX_H
#define COM_VERTEX_H

#include <boost/python.hpp>
#include <boost/format.hpp>

#include "copper/GEO/Vertex.h"

class COM_Vertex {
	public:
		COM_Vertex(Vertex *vtx);

	private:
		Vertex *vtx;
};

#endif