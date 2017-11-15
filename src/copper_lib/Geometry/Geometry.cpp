#include "Geometry/Geometry.h"

Geometry::Geometry(): _sop_node{NULL} {
	std::cout << "Geometry constructed" << std::endl;
}

Geometry::Geometry(const Geometry &geo): Geometry() {
	_sop_node = geo._sop_node;
	_points = geo._points;
	std::cout << "Geometry copied" << std::endl;
}

Geometry::~Geometry() {
	std::cout << "Geometry destroyed" << std::endl;
}

Geometry *Geometry::freeze(){
	Geometry *frozen_geo = new Geometry();
	return frozen_geo;
}

std::vector<Point*> *Geometry::points() {
	return &(this)->_points;
}

std::vector<Point*> *Geometry::points() const {
	return const_cast<std::vector<Point*> *>(&(this)->_points);
}

Node *Geometry::sopNode(){
	return _sop_node;
}

Point *Geometry::createPoint() {
	_points.push_back(new Point());
	return this->_points.back();
}
