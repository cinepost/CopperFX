#ifndef __GEO_Geometry_h__
#define __GEO_Geometry_h__

#include <vector>
#include <iostream>

#include <boost/shared_ptr.hpp>

#include "copper/GEO/Point3.h"
#include "copper/Operator/OP_Node.h"


namespace copper {

class GEO_Geometry {
	public:
		GEO_Geometry();
		GEO_Geometry(const GEO_Geometry &geo); // copy constructor
		~GEO_Geometry();

		GEO_Geometry *freeze();
		std::vector<Point3d*> *points();
		std::vector<Point3d*> *points() const;
		OP_Node *sopNode();

		Point3d *createPoint();

	private:
		OP_Node *_sop_node;
		std::vector<Point3d*> _points;
};

}

#endif