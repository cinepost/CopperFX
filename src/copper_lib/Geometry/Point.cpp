#include "Geometry/Point.h"

Point::Point(Geometry *geo) {
	_geo = geo;
	_weight = 1.0;
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