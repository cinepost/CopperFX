#include "Geometry/Point.h"

Point::Point(): _weight{0.0} {
	std::cout << "Point constructed" << std::endl;
}

Point::Point(const Point &pt) {
	_weight = pt._weight;
	_pos = pt._pos;
	std::cout << "Point copied" << std::endl;
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