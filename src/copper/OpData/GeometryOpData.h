#ifndef GEOMETRY_OP_DATA_H
#define GEOMETRY_OP_DATA_H

#include <vector>
#include <string>
#include <map>

#include "copper/OpData/BaseOpData.h"
#include "copper/Prims/Point3.h"

namespace copper {

class GeometryOpData: public BaseOpData {
	public:
		GeometryOpData(){};

		virtual const std::string name() const;
		virtual const std::string typeName() const;
		virtual const unsigned int version() const;

		virtual void saveToFile(std::string filename, const unsigned int version);
    virtual void loadFromFile(std::string filename, const unsigned int version);

    std::vector<Point3d>  *points();
    std::vector<Point3d>  *points() const;
    Point3d 							*createPoint();
		
	private:
		std::vector<Point3d> _points;
};

// factory methods
BaseOpData *geometryOpDataConstructor();
std::string	geometryOpDataTypeName();

}

#endif // GEOMETRY_OP_DATA_H