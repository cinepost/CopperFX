#include "Math/Vector3.h"

Vector3::Vector3(const Vector3 &vec) {
	_comps[0] = vec._comps[0]; _comps[1] = vec._comps[1]; _comps[2] = vec._comps[2];
}

Vector3::Vector3(std::vector<double> &comps){
	set(comps);
}

void Vector3::set(double x, double y, double z){
	_comps[0] = x; _comps[1] = y; _comps[2] = z;
}

void Vector3::set(std::vector<double> &comps){
	if((3 <= comps.size()) && (comps.size() <= 4)) {
		_comps[0] = comps[0];
		_comps[1] = comps[1];
		_comps[2] = comps[2];
	}
}

double Vector3::length() {
	return sqrt(_comps[0] * _comps[0] + _comps[1] * _comps[1] + _comps[2] * _comps[2]);
}

double Vector3::lengthSquared() {
	return _comps[0] * _comps[0] + _comps[1] * _comps[1] + _comps[2] * _comps[2];
}

Vector3 Vector3::normalized() {
	double length = this->length();
	return Vector3(_comps[0] / length, _comps[1] / length, _comps[2] / length);
}

double Vector3::distance(Vector3 &vec) {
	return sqrt((_comps[0] - vec[0]) * (_comps[0] - vec[0]) + (_comps[1] - vec[1]) * (_comps[1] - vec[1]) + (_comps[2] - vec[2]) * (_comps[2] - vec[2]));
}

double &Vector3::operator[](int index) {
	return _comps[index];
}

const double &Vector3::operator[](int index) const {
	return _comps[index];
}

bool Vector3::operator==(const Vector3& vec) {
	return _comps[0] == vec._comps[0] && _comps[1] == vec._comps[1] && _comps[2] == vec._comps[2];
}