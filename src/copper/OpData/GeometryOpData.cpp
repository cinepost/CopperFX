#include "copper/OpData/GeometryOpData.h"


namespace copper {

std::string GeometryOpData::_ui_name = "Image";

const std::string& GeometryOpData::name() const {
	return GeometryOpData::_ui_name;
}

void GeometryOpData::saveToFile(const std::string& filename, const unsigned int version) const { }
void GeometryOpData::loadFromFile(const std::string& filename, const unsigned int version) { }

std::vector<Point3d> *GeometryOpData::points() {
	return &_points;
}

std::vector<Point3d> *GeometryOpData::points() const {
	return const_cast<std::vector<Point3d> *>(&(this)->_points);
}

Point3d *GeometryOpData::createPoint() {
	_points.emplace_back();
	return &this->_points.back();
}

// factory methods
std::string GeometryOpData::myTypeName() {
    return "geometry";
}

OpDataBase *GeometryOpData::myConstructor() {
    return new GeometryOpData();
}

}