#include "copper/OpData/GeometryOpData.h"


namespace copper {

const std::string GeometryOpData::name() const {
	return "Geometry";
}

const std::string GeometryOpData::typeName() const {
	return "geometry";
}

const unsigned int GeometryOpData::version() const {
	return 0;
}

void GeometryOpData::saveToFile(std::string filename, const unsigned int version) { }
void GeometryOpData::loadFromFile(std::string filename, const unsigned int version) { }

// factory methods
std::string geometryOpDataTypeName() {
    return "geometry";
}

BaseOpData *geometryOpDataConstructor() {
    return new GeometryOpData();
}

}