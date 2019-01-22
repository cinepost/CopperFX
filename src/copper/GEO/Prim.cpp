#include "copper/GEO/Prim.h"

std::vector<Vertex*> * Prim::vertices() {
	return &_vertices;
}

Vertex *Prim::addVertex(Point *pt) {
	_vertices.push_back(new Vertex(pt));
	return _vertices.back();
}