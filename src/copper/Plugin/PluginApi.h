#ifndef PLUGINAPI_H
#define PLUGINAPI_H

#include <boost/config.hpp>
#include <string>


namespace copper {

class BOOST_SYMBOL_VISIBLE BaseAPI {
  public:
  	static const std::string& name() = 0; // plugin instance name used for display purposes
  	static const std::string& typeName() = 0; // plugin instance type name
  	virtual const unsigned int version() const = 0; // plugin instance version
  	virtual ~BaseAPI() {}

  private:
  	template<class T> friend class AbstractFactory;
};

}

#endif // PLUGINAPI_H