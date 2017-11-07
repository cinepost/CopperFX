#ifndef __Geometry_h__
#define __Geometry_h__

#include <vector>
#include <iostream>

#include "Geometry/Point.h"
#include "Node/Node.h"

class Point;

class Geometry {
	public:
		Geometry();
		Geometry(const Geometry &geo); // copy constructor
		~Geometry();

		Geometry *freeze();
		std::vector<Point> *points();
		std::vector<Point> *points() const;
		Node *sopNode();

		Point *createPoint();

		std::string name();
		void setName(std::string name);

		int numPoints();

	private:
		std::string _name;
		Node *_sop_node;
		std::vector<Point> _points;
};

#endif