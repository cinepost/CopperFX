#include <atomic>

#include "copper/Util/IndexableObject.h"

namespace copper {

IndexableObject::IndexableObject() {
	_guid = IndexableObject::getNextGUID();
}

IndexableObject::IndexableObject(const IndexableObject &iobject) {
	_guid = IndexableObject::getNextGUID();
}

obj_guid_t IndexableObject::GUID() const {
	return _guid;
}

obj_guid_t IndexableObject::getNextGUID() {
  static std::atomic<obj_guid_t> ID{0};  
  return ++ID; 
}

}
