#ifndef OP_DATA_BASE_H
#define OP_DATA_BASE_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"

namespace copper {

class OpDataBase: public BaseAPI {
	public:
  	virtual void saveToFile(const std::string& filename, const unsigned int version) const = 0;
  	virtual void loadFromFile(const std::string& filename, const unsigned int version) = 0;
};

}

#endif // OP_DATA_BASE_H