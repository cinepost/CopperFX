#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace copper {

struct TypeInfo {
	std::string type_name;
	std::string ui_name;
	unsigned int version;
	boost::uuids::uuid type_uuid;

	TypeInfo() {};
	virtual ~TypeInfo() {};
	TypeInfo(const TypeInfo &info):
		type_name(info.type_name), ui_name(info.ui_name), version(info.version), type_uuid(info.type_uuid) {};
	TypeInfo(std::string type_name, std::string ui_name, unsigned int version, boost::uuids::uuid type_uuid):
		type_name(type_name), ui_name(ui_name), version(version), type_uuid(type_uuid) {};

	TypeInfo typeInfo() const {
		return TypeInfo(type_name, ui_name, version, type_uuid);
	}

	bool operator<(const TypeInfo &info)const{return version>info.version;}

	friend std::ostream& operator << (std::ostream& oss, TypeInfo const &info) {
  	oss << "Type: \"" << info.type_name << "\" uuid: " << boost::uuids::to_string(info.type_uuid) << " version: " << info.version;
  	return oss;
	}
};

//template<typename Entry>
//struct TypeEntry: TypeInfo {
//	Entry entry;
//};

}

#endif // TYPE_INFO_H