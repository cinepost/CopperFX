#include "copper/Operator/OpDefinition.h"
#include "OpFactory.h"


namespace copper {

void OpFactory::registerOpDefinition(OpDefinition *op_def) {
	_op_definitions_by_type_name[op_def->typeName()] = op_def;
}

OpDefinition* OpFactory::opDefinition(const std::string &type_name) {
	return _op_definitions_by_type_name[type_name];
}

std::vector<std::string> OpFactory::registeredTypeNames() {
	std::vector<std::string> type_names;
	for (auto const& item : _op_definitions_by_type_name) {
		type_names.push_back(item.first);
	}
	return type_names;
}

}