#ifndef PL_OBJECTFACTORY_H
#define PL_OBJECTFACTORY_H

#include <map>
#include <vector>
#include <string>
#include <unordered_map>

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

#endif // PL_OBJECTFACTORY_H