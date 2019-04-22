#ifndef PLUGIN_OBJECTFACTORY_H
#define PLUGIN_OBJECTFACTORY_H

#include <map>
#include <vector>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/type_traits.hpp>

#include "copper/OpData/BaseOpData.h"
#include "copper/Operator/BaseOperator.h"
#include "copper/Util/Singleton.h"
#include "copper/Plugin/PluginApi.h"


namespace copper {

template <class T>
class ObjectFactory { //: public Singleton<ObjectFactory<T>> {
  typedef std::string (*objectTypeName)();
  typedef T *(*objectConstructor)();

  typedef std::unordered_map<std::string, T*> HashTableByTypeName;
  typedef std::unordered_map<std::type_index, T*> HashTableByTypeInfo;

  public:
    ObjectFactory() {};

    T *createObject(void);
    T *createObjectByTypeName(std::string object_type_name);
    void registerType(objectTypeName typeName, objectConstructor constructor);
    void registerType(std::string type_name, objectConstructor constructor);

  private:
    HashTableByTypeName _constructors_by_type_name;
    HashTableByTypeInfo _constructors_by_type_info;
};

template <class T>
T *ObjectFactory<T>::createObject(void) {
  return nullptr;
}

template <class T>
T *ObjectFactory<T>::createObjectByTypeName(std::string object_type_name){
  return nullptr;
}

template <class T>
void ObjectFactory<T>::registerType(objectTypeName typeName, objectConstructor constructor){
  registerType(typeName(), constructor);
}

template <class T>
void ObjectFactory<T>::registerType(std::string type_name, objectConstructor constructor){
  //BOOST_MPL_ASSERT((boost::is_base_of<T, BaseOpData>)); // protection against wrong types registrations
  //_constructors_by_name[object_type_name] = reinterpret_cast<T*>(constructor);
  //_constructors_by_name.insert( std::pair<std::string, objectConstructor>(type_name(), reinterpret_cast<T*>(constructor)) );

  //std::pair<std::string, objectConstructor> *p = new std::pair<std::string, objectConstructor>(type_name, constructor);
  //_constructors_by_type_name.insert( new std::pair<std::string, objectConstructor>(type_name, constructor) );
  _constructors_by_type_info[typeid(T)] = reinterpret_cast<T*>(constructor);
  _constructors_by_type_name[type_name] = reinterpret_cast<T*>(constructor);
  BOOST_LOG_TRIVIAL(debug) << "Registered " << typeid(T).name() << " \"" << type_name << "\"\n";
}

}

#endif // PL_OBJECTFACTORY_H