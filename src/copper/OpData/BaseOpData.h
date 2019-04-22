#ifndef BASE_OP_DATA_H
#define BASE_OP_DATA_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"

namespace copper {

class BaseOpData: public BaseAPI {
	public:
  	virtual const std::string name() const = 0; // plugin instance name used for display purposes
  	virtual const std::string typeName() const = 0; // plugin instance type name

  	virtual void saveToFile(std::string filename, const unsigned int version) = 0;
  	virtual void loadFromFile(std::string filename, const unsigned int version) = 0;
};

}

#endif // BASE_OP_DATA_H