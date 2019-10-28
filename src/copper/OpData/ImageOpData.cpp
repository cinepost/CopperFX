#include "copper/OpData/ImageOpData.h"

namespace copper {

std::string ImageOpData::_ui_name = "Image";

const std::string& ImageOpData::name() const {
	return ImageOpData::_ui_name;
}

void ImageOpData::saveToFile(const std::string& filename, const unsigned int version) const { }
void ImageOpData::loadFromFile(const std::string& filename, const unsigned int version) { }

// factory methods
OpDataBase *ImageOpData::myConstructor() {
    return new ImageOpData();
}

void ImageOpData::registerDataType(OpDataTable *op_data_table) {
	TypeInfo info {
		"img",
		"Image",
		0,
		boost::uuids::string_generator()("{dfcc184a-10df-4016-aceb-349396b12d51}"),
	};

  op_data_table->registerOpDataType(
    info,                       /// data type info
    ImageOpData::myConstructor  /// op constructor
  );
}

}