#include <copper/Plugin/ObjectFactory.h>

namespace copper {

template <class T>
T *ObjectFactory<T>::createObject(void) {
  return nullptr;
}

template <class T>
T *ObjectFactory<T>::createObjectByName(std::string object_type_name){
  return nullptr;
}

template <class T>
void ObjectFactory<T>::registerType(std::string object_type_name, objectConstructor constructor){
	BOOST_MPL_ASSERT((boost::is_base_of<T, BaseAPI>)); // protection against wrong types registrations
	_constructors_by_name[object_type_name] = reinterpret_cast<T*>(constructor);
}

}