#ifndef PLUGIN_OBJECTFACTORY_H
#define PLUGIN_OBJECTFACTORY_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/type_traits.hpp>

#include "copper/OpData/OpDataBase.h"
#include "copper/Operator/OperatorBase.h"
#include "copper/Util/Singleton.h"
#include "copper/Plugin/PluginApi.h"


namespace copper {

template <class T>
class ObjectFactory {
  typedef std::string (*objectTypeName)();
  typedef T *(*objectConstructor)();

  typedef std::unordered_map<std::string, objectConstructor> HashTableByTypeName;
  typedef std::unordered_map<std::type_index, objectConstructor> HashTableByTypeInfo;

  public:
    ObjectFactory() {};

    T *createObjectByTypeName(std::string object_type_name);
    T *createObjectByTypeId(std::type_index object_type_id);

    void registerType(objectTypeName typeNameCallable, objectConstructor constructor);
    void registerType(std::string type_name, objectConstructor constructor);

    void printRegisteredTypes(); // mostly for debugging purposes

  private:
    HashTableByTypeName _constructors_by_type_name;
    HashTableByTypeInfo _constructors_by_type_info;
};

template <class T>
void ObjectFactory<T>::printRegisteredTypes() {
  std::cout << "ObjectFactory begin ---------\n";
  for (std::pair<std::string, objectConstructor> element : _constructors_by_type_name) {
    std::cout << element.first << ", ";
  }
  std::cout << "\nObjectFactory end -----------\n";
}

template <class T>
T *ObjectFactory<T>::createObjectByTypeName(std::string object_type_name) {
  BOOST_LOG_TRIVIAL(debug) << "ObjectFactory::createObjectByTypeName " << object_type_name << " " << _constructors_by_type_name[object_type_name];
  return _constructors_by_type_name[object_type_name]();
}

template <class T>
T *ObjectFactory<T>::createObjectByTypeId(std::type_index object_type_id) {
  BOOST_LOG_TRIVIAL(debug) << "ObjectFactory::createObjectByTypeId " << object_type_id << " " << _constructors_by_type_info[object_type_id];
  return _constructors_by_type_info[object_type_id]();
}

template <class T>
void ObjectFactory<T>::registerType(objectTypeName typeNameCallable, objectConstructor constructor){
  registerType(typeNameCallable(), constructor);
}

template <class T>
void ObjectFactory<T>::registerType(std::string type_name, objectConstructor constructor){
  BOOST_MPL_ASSERT((boost::is_base_of<BaseAPI, T>)); // protection against wrong types registrations

  _constructors_by_type_info[typeid(T)] = constructor;
  _constructors_by_type_name[type_name] = constructor;

  BOOST_LOG_TRIVIAL(debug) << "Registered " << typeid(T).name() << " \"" << type_name << "\"";
}

}

#endif // PL_OBJECTFACTORY_H