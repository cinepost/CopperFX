#include "Geometry/Point.h"

Point::Point(): _geo{NULL}, _weight{0.0} {
	std::cout << "Point constructed" << std::endl;
}

Point::Point(Geometry *geo): Point() {
	_geo = geo;
}

Point::Point(const Point &pt) {
	_geo = pt._geo;
	_weight = pt._weight;
	_pos = pt._pos;
	std::cout << "Point copied" << std::endl;
}

Geometry *Point::geometry() {
	return _geo;
}

double Point::weight() {
	return _weight;
}

void Point::setWeight(double weight) {
	_weight = weight;
}

Vector3 Point::position() {
	return _pos;
}

void Point::setPosition(double x, double y, double z) {
	_pos[0] = x; _pos[1] = y; _pos[2] = z;
}

void Point::setPosition(Vector3 &pos) {
	_pos = pos;
}