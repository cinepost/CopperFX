#include "copper/Prims/Prim.h"


namespace copper {

std::vector<Vertex*> * Prim::vertices() {
	return &_vertices;
}

Vertex *Prim::addVertex(Point3d *pt) {
	_vertices.push_back(new Vertex(pt));
	return _vertices.back();
}

}