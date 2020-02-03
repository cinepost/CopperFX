#ifndef OP_DATA_BASE_H
#define OP_DATA_BASE_H

#include <string>
#include <map>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>

#include "copper/Plugin/PluginApi.h"
#include "copper/Plugin/TypeInfo.h"

namespace copper {

class OpDataBase: public BaseAPI {
	public:
  	virtual void saveToFile(const std::string& filename, const unsigned int version) const = 0;
  	virtual void loadFromFile(const std::string& filename, const unsigned int version) = 0;
};

/*
 * helpers to get type info from opdata class
 */

#define OP_DATA_TYPE_INFO(T) __opDataTypeInfo<T>()

template <class T>
inline TypeInfo __opDataTypeInfo() {
    return T::opDataTypeInfo();
}

}

#endif // OP_DATA_BASE_H