#include "copper/OpData/ImageOpData.h"


namespace copper {

const std::string ImageOpData::name() const {
	return "Image";
}

const std::string ImageOpData::typeName() const {
	return "image";
}

const unsigned int ImageOpData::version() const {
	return 0;
}

void ImageOpData::saveToFile(std::string filename, const unsigned int version) { }
void ImageOpData::loadFromFile(std::string filename, const unsigned int version) { }

// factory methods
std::string ImageOpData::myTypeName() {
    return "image";
}

OpDataBase *ImageOpData::myConstructor() {
    return new ImageOpData();
}

}