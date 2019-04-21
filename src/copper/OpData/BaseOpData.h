#ifndef BASE_OP_DATA_H
#define BASE_OP_DATA_H

#include <string>
#include <map>

#include "copper/Plugin/PluginApi.h"

namespace copper {

class BaseOpData: public BaseAPI {
  virtual const std::string typeName() const = 0; // internal type name

  virtual void saveToFile(std::string filename, const unsigned int version) = 0;
  virtual void loadFromFile(std::string filename, const unsigned int version) = 0;		
};

}

#endif // BASE_OP_DATA_H