#ifndef PLUGIN_PLUGINAPI_H
#define PLUGIN_PLUGINAPI_H

#include <boost/config.hpp>
#include <string>

namespace copper {

class BOOST_SYMBOL_VISIBLE BaseAPI {
  public:
  	virtual const std::string name() const = 0; // plugin instance name used for display purposes
  	virtual const std::string typeName() const = 0; // plugin instance type name
  	virtual const unsigned int version() const = 0; // plugin instance version
  	virtual ~BaseAPI() {}
};

}

#endif // PL_PLUGINAPI_H