#ifndef OP_DATA_BASE_H
#define OP_DATA_BASE_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"

namespace copper {

class OpDataBase: public BaseAPI {
	public:
  	virtual const std::string& name() const = 0; // plugin instance name used for display purposes
  	virtual const std::string& typeName() const = 0; // plugin instance type name

  	virtual void saveToFile(const std::string& filename, const unsigned int version) const = 0;
  	virtual void loadFromFile(const std::string& filename, const unsigned int version) = 0;
};

}

#endif // OP_DATA_BASE_H