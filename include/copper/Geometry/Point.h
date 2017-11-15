#ifndef __Point_h__
#define __Point_h__

#include <stdexcept>
#include <vector>
#include <iostream>

#include "Math/Vector3.h"

class Point {
	public:
		Point();
		Point(const Point &pt);  // copy constructor

		double weight();
		void setWeight(double weight);

		Vector3 position();
		void setPosition(double x, double y, double z);
		void setPosition(Vector3& pos);

	private:
		double	_weight;
		Vector3 _pos;
};

#endif