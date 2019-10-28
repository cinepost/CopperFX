#include "copper/Operator/OpNodeTemplate.h"
#include "OpTable.h"


namespace copper {

void OpTable::registerOpNodeTemplate(OpNodeTemplate *op_node_template) {
	if (op_node_template) {
		TypeInfo op_type_info = op_node_template->typeInfo();

		BOOST_LOG_TRIVIAL(debug) << "Registering operator: \"" << op_type_info.type_name 
		<< "\" uuid: " << op_type_info.type_uuid 
		<< " with version: " << op_type_info.version;
		
		OpNodeTemplateEntry entry {
			op_type_info,
			op_node_template,
		};

		if(!_op_node_templates_table.insert(entry).second){
    	BOOST_LOG_TRIVIAL(warning) << "Operator \"" << op_type_info.type_name << "\" already registered!";
  	}
	}
}

OpNodeTemplate *OpTable::getOpNodeTemplate(std::string type_name) {
	//std::pair<OpNodeTemplatesTable::iterator, OpNodeTemplatesTable::iterator> entries=_op_node_templates_table.get<type_name_version>().equal_range(type_name);

	auto range = boost::make_iterator_range(_op_node_templates_table.get<type_name_version>().equal_range(type_name));

	OpNodeTemplate* op_node_template = range.begin()->op_node_template;

	if( op_node_template) return op_node_template;
	BOOST_LOG_TRIVIAL(error) << "Unable to get any version of OpNodeTemplate: " << type_name << " !!!";
	return NULL; //entries.first->op_node_template;
}

OpNodeTemplate *OpTable::getOpNodeTemplate(boost::uuids::uuid type_uuid){
	return NULL;
}

OpNodeTemplate *OpTable::getOpNodeTemplate(std::string type_name, unsigned int version) {
 return NULL;
}


OpNodeTemplate *OpTable::getOpNodeTemplate(boost::uuids::uuid type_uuid, unsigned int version) {
	// search for type_uuid with version 
	OpNodeTemplatesTable::iterator it=_op_node_templates_table.find(std::make_tuple(type_uuid, version));
	return it->op_node_template;
}

const std::vector<TypeInfo> OpTable::registeredOperators() const {
	std::vector<TypeInfo> types;
	for (auto const& entry : _op_node_templates_table) {
		types.push_back(entry.type_info);
	}
	return types;
}

}