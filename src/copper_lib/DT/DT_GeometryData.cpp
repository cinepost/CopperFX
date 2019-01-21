#include "copper/DT/DT_GeometryData.h"


std::string DT_GeometryData::name() const {
	return "Geometry";
}

bool DT_GeometryData::cookData(float time) {
	return true;
}