#include "Math/Vector2.h"

Vector2::Vector2(const Vector2 &vec) {
	_comps[0] = vec._comps[0]; _comps[1] = vec._comps[1];
}

Vector2::Vector2(std::vector<double> &comps){
	set(comps);
}

void Vector2::set(double x, double y){
	_comps[0] = x; _comps[1] = y;
}

void Vector2::set(std::vector<double> &comps){
	if((2 <= comps.size()) && (comps.size() <= 4)) {
		_comps[0] = comps[0];
		_comps[1] = comps[1];
	}
}

double Vector2::length() {
	return sqrt(_comps[0] * _comps[0] + _comps[1] * _comps[1]);
}

double Vector2::lengthSquared() {
	return _comps[0] * _comps[0] + _comps[1] * _comps[1];
}

Vector2 Vector2::normalized() {
	double length = this->length();
	return Vector2(_comps[0] / length, _comps[1] / length);
}

double Vector2::distance(Vector2 &vec) {
	return sqrt((_comps[0] - vec[0]) * (_comps[0] - vec[0]) + (_comps[1] - vec[1]) * (_comps[1] - vec[1]));
}

double &Vector2::operator[](int index) {
	return _comps[index];
}

const double &Vector2::operator[](int index) const {
	return _comps[index];
}

bool Vector2::operator==(const Vector2& vec) {
	return _comps[0] == vec._comps[0] && _comps[1] == vec._comps[1];
}