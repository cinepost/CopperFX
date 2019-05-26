#include "copper/Operator/OpNodeTemplate.h"
#include "OpTable.h"


namespace copper {

void OpTable::registerOpNodeTemplate(OpNodeTemplate *op_node_template) {
	_op_node_templates_by_type_name[op_node_template->typeName()] = op_node_template;
}

OpNodeTemplate *OpTable::getOpNodeTemplate(const std::string &type_name) {
	return _op_node_templates_by_type_name[type_name];
}

const std::vector<std::string> OpTable::registeredTypeNames() const {
	std::vector<std::string> type_names;
	for (auto const& item : _op_node_templates_by_type_name) {
		type_names.push_back(item.first);
	}
	return type_names;
}

}