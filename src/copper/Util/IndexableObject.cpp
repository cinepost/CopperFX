#include <atomic>

#include "copper/Util/IndexableObject.h"

namespace copper {

IndexableObject::IndexableObject() {
	_id = IndexableObject::getNextID();
}

IndexableObject::IndexableObject(const IndexableObject &iobject) {
	_id = IndexableObject::getNextID();
}

obj_id_t IndexableObject::getNextID() {
  static std::atomic<obj_id_t> ID{0};  
  return ++ID; 
}

}
