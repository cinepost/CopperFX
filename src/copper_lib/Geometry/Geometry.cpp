#include "Geometry/Geometry.h"

Geometry::Geometry() {
	_sop_node = NULL;
	_points = new std::vector<Point>();
}

Geometry::~Geometry() {
	delete _points;
}

Geometry *Geometry::freeze(){
	Geometry *frozen_geo = new Geometry();
	return frozen_geo;
}

std::vector<Point> *Geometry::points() {
	return _points;
}

Node *Geometry::sopNode(){
	return _sop_node;
}

Point *Geometry::createPoint() {
	_points->push_back(Point(this));
	return &_points->back();
}