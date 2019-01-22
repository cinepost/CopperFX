#ifndef __GEO_Geometry_h__
#define __GEO_Geometry_h__

#include <vector>
#include <iostream>

#include <boost/shared_ptr.hpp>

#include "copper/GEO/Point.h"
#include "copper/OP/OP_Node.h"

class Point;

class GEO_Geometry {
	public:
		GEO_Geometry();
		GEO_Geometry(const GEO_Geometry &geo); // copy constructor
		~GEO_Geometry();

		GEO_Geometry *freeze();
		std::vector<Point*> *points();
		std::vector<Point*> *points() const;
		OP_Node *sopNode();

		Point *createPoint();

	private:
		OP_Node *_sop_node;
		std::vector<Point*> _points;
};

#endif