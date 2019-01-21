#ifndef PL_PLUGINAPI_H
#define PL_PLUGINAPI_H

#include <boost/config.hpp>
#include <string>

class BOOST_SYMBOL_VISIBLE PL_OperatorAPI {
	public:
	  virtual std::string name() const = 0;
	  virtual float calculate(float x, float y) = 0;

	  virtual ~PL_OperatorAPI() {}
};


class BOOST_SYMBOL_VISIBLE PL_DataAPI {
	public:
		virtual std::string name() const = 0;

		virtual ~PL_DataAPI() {}
};

#endif // PL_PLUGINAPI_H