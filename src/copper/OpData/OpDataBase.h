#ifndef OP_DATA_BASE_H
#define OP_DATA_BASE_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"

namespace copper {

class OpDataBase: public BaseAPI {
	public:
  	static const std::string& name() = 0; // plugin instance name used for display purposes
  	static const std::string& typeName() = 0; // plugin instance type name

  	virtual void saveToFile(const std::string& filename, const unsigned int version) = 0;
  	virtual void loadFromFile(const std::string& filename, const unsigned int version) = 0;
};

}

#endif // OP_DATA_BASE_H