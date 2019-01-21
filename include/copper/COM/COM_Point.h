#ifndef COM_NODE_H
#define COM_NODE_H

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "GEO/GEO_Geometry.h"
#include "GEO/Point.h"

#include "COM/COM_Geometry.h"
#include "COM_Vector.h"

class COM_Geometry;

class COM_Point {
	public:
		COM_Point(int index, Point * point, COM_Geometry *com_geo);

		COM_Vector3 position();
		void setPosition_from_list(boost::python::list& list);
		void setPosition_from_COM_Vector3(COM_Vector3 &vec);
		COM_Geometry *geometry();

		std::string __str__();

	private:
		int _index;
		Point *_point;
		COM_Geometry *_com_geo;
};

#endif