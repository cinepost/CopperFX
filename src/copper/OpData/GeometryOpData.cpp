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

}