#ifndef __Point_h__
#define __Point_h__

#include <stdexcept>
#include <vector>

#include "Math/Vector3.h"
#include "Geometry/Geometry.h"

class Geometry;

class Point {
	public:
		Point(Geometry *geo);

		Geometry *geometry();
		double weight();
		void setWeight(double weight);

		Vector3 position();
		void setPosition(double x, double y, double z);
		void setPosition(Vector3& pos);

	private:
		Geometry *_geo;
		double	_weight;
		Vector3 _pos;
};

#endif