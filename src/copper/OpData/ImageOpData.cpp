#include "copper/OpData/ImageOpData.h"


namespace copper {

std::string ImageOpData::_ui_name = "Image";

const std::string& ImageOpData::name() const {
	return ImageOpData::_ui_name;
}

void ImageOpData::saveToFile(const std::string& filename, const unsigned int version) const { }
void ImageOpData::loadFromFile(const std::string& filename, const unsigned int version) { }

// factory methods
std::string ImageOpData::myTypeName() {
    return "image";
}

OpDataBase *ImageOpData::myConstructor() {
    return new ImageOpData();
}

}