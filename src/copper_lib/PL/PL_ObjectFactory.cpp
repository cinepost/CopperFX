#include <copper/PL/PL_ObjectFactory.h>


template <class T>
T *PL_ObjectFactory<T>::createObject(void) {

}

template <class T>
T *PL_ObjectFactory<T>::createObjectByName(std::string object_type_name){

}

template <class T>
void PL_ObjectFactory<T>::registerType(std::string object_type_name, objectConstructor constructor){
	
}