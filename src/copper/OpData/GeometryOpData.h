#ifndef GEOMETRY_OP_DATA_H
#define GEOMETRY_OP_DATA_H

#include <vector>
#include <string>
#include <map>

#include "copper/OpData/OpDataBase.h"
#include "copper/Prims/Point3.h"

namespace copper {

class GeometryOpData: public OpDataBase {
	public:
		GeometryOpData(){};

		const std::string name() const override;
		const std::string typeName() const override;
		const unsigned int version() const override;

		void saveToFile(std::string filename, const unsigned int version) override;
    void loadFromFile(std::string filename, const unsigned int version) override;

    std::vector<Point3d>  *points();
    std::vector<Point3d>  *points() const;
    Point3d 							*createPoint();

    // factory methods
    static std::string myTypeName();
		static OpDataBase *myConstructor();
		
	private:
		std::vector<Point3d> _points;
};

}

#endif // GEOMETRY_OP_DATA_H