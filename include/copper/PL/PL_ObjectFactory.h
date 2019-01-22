#ifndef PL_OBJECTFACTORY_H
#define PL_OBJECTFACTORY_H

#include <map>
#include <vector>
#include <string>
#include <unordered_map>

#include <boost/mpl/assert.hpp>
#include <boost/type_traits.hpp>

#include "copper/PL/PL_PluginApi.h"

template <class T>
class PL_ObjectFactory {
  typedef T *(*objectConstructor)();
  typedef std::unordered_map<std::string, T*> HashTableByName;
  typedef std::unordered_map<const std::type_info*, T*> HashTableByType;

  public:
    PL_ObjectFactory() {};

    T *createObject(void);
    T *createObjectByName(std::string object_type_name);
    void registerType(std::string object_type_name, objectConstructor constructor);

  private:
    HashTableByName _constructors_by_name;
    HashTableByType _constructors_by_type;
};

typedef PL_ObjectFactory<PL_DataAPI> PL_DataFactory;
typedef PL_ObjectFactory<PL_OperatorAPI> PL_OperatorsFactory;

#endif // PL_OBJECTFACTORY_H