#ifndef __Geometry_h__
#define __Geometry_h__

#include <vector>

#include "Geometry/Point.h"
#include "Node/Node.h"

class Point;

class Geometry {
	public:
		Geometry();
		~Geometry();

		Geometry *freeze();
		std::vector<Point> *points();
		Node *sopNode();

		Point *createPoint();

	private:
		Node *_sop_node;
		std::vector<Point> *_points;
};

#endif