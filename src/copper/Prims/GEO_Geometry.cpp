#include "copper/Prims/GEO_Geometry.h"


namespace copper {

GEO_Geometry::GEO_Geometry(): _sop_node{NULL} {
	std::cout << "GEO_Geometry constructed" << std::endl;
}

GEO_Geometry::GEO_Geometry(const GEO_Geometry &geo): GEO_Geometry() {
	_sop_node = geo._sop_node;
	_points = geo._points;
	std::cout << "GEO_Geometry copied" << std::endl;
}

GEO_Geometry::~GEO_Geometry() {
	std::cout << "GEO_Geometry destroyed" << std::endl;
}

GEO_Geometry *GEO_Geometry::freeze(){
	GEO_Geometry *frozen_geo = new GEO_Geometry();
	return frozen_geo;
}

std::vector<Point3d*> *GEO_Geometry::points() {
	return &(this)->_points;
}

std::vector<Point3d*> *GEO_Geometry::points() const {
	return const_cast<std::vector<Point3d*> *>(&(this)->_points);
}

OP_Node *GEO_Geometry::sopNode(){
	return _sop_node;
}

Point3d *GEO_Geometry::createPoint() {
	_points.push_back(new Point3d());
	return this->_points.back();
}

}