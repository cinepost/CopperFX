#ifndef PLUGIN_OBJECTFACTORY_H
#define PLUGIN_OBJECTFACTORY_H

#include <map>
#include <vector>
#include <string>
#include <unordered_map>

#include <boost/mpl/assert.hpp>
#include <boost/type_traits.hpp>

#include "copper/OpData/BaseOpData.h"
#include "copper/Operator/BaseOperator.h"
#include "copper/Util/Singleton.h"
#include "copper/Plugin/PluginApi.h"


namespace copper {

template <class T>
class ObjectFactory { //: public Singleton<ObjectFactory<T>> {
  typedef T *(*objectConstructor)();
  typedef std::unordered_map<std::string, T*> HashTableByName;
  typedef std::unordered_map<const std::type_info*, T*> HashTableByType;

  public:
    ObjectFactory() {};

    T *createObject(void);
    T *createObjectByName(std::string object_type_name);
    void registerType(std::string object_type_name, objectConstructor constructor);

  private:
    HashTableByName _constructors_by_name;
    HashTableByType _constructors_by_type;
};

typedef ObjectFactory<BaseOpData> DataFactory;
typedef ObjectFactory<BaseOperator> OperatorFactory;

}

#endif // PL_OBJECTFACTORY_H