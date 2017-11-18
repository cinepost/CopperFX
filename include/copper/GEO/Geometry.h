#ifndef __Geometry_h__
#define __Geometry_h__

#include <vector>
#include <iostream>

#include <boost/shared_ptr.hpp>

#include "GEO/Point.h"
#include "OP/Node.h"

class Point;

class Geometry {
	public:
		Geometry();
		Geometry(const Geometry &geo); // copy constructor
		~Geometry();

		Geometry *freeze();
		std::vector<Point*> *points();
		std::vector<Point*> *points() const;
		Node *sopNode();

		Point *createPoint();

	private:
		Node *_sop_node;
		std::vector<Point*> _points;
};

#endif