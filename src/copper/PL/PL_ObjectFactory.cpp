#include <copper/PL/PL_ObjectFactory.h>


template <class T>
T *PL_ObjectFactory<T>::createObject(void) {

}

template <class T>
T *PL_ObjectFactory<T>::createObjectByName(std::string object_type_name){

}

template <class T>
void PL_ObjectFactory<T>::registerType(std::string object_type_name, objectConstructor constructor){
	BOOST_MPL_ASSERT((boost::is_base_of<T, PL_BaseAPI>)); // protection against wrong types registrations
	_constructors_by_name[object_type_name] = reinterpret_cast<T*>(constructor);
}