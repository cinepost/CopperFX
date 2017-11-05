#include "Math/Vector3.h"

Vector3::Vector3(std::vector<double> &comps){
	setTo(comps);
}

double Vector3::x(){ return _comps[0]; }
double Vector3::y(){ return _comps[1]; }
double Vector3::z(){ return _comps[2]; }

void Vector3::setTo(double x, double y, double z){
	_comps[0] = x; _comps[1] = y; _comps[2] = z;
}

void Vector3::setTo(std::vector<double> &comps){
	if((3 <= comps.size()) && (comps.size() <= 4)) {
		_comps[0] = comps[0];
		_comps[1] = comps[1];
		_comps[2] = comps[2];
	}
}

double &Vector3::operator[](int index) {
	return _comps[index];
}