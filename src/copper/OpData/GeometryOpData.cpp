#include "copper/OpData/GeometryOpData.h"


namespace copper {

std::string GeometryOpData::_ui_name = "Geometry";

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

// opdata type info
TypeInfo GeometryOpData::opDataTypeInfo() {
	return TypeInfo {
		"geo",
		"Geometry",
		0,
		boost::uuids::string_generator()("{dc4f6d0e-12e1-4273-a9d5-8bcf146e09dd}")
	};
}

// factory methods
OpDataBase *GeometryOpData::myConstructor() {
    return new GeometryOpData();
}

void GeometryOpData::registerDataType(OpDataTable *op_data_table) {
  op_data_table->registerOpDataType(
    GeometryOpData::opDataTypeInfo(),   /// data type info
    GeometryOpData::myConstructor  		/// op constructor
  );
}

}