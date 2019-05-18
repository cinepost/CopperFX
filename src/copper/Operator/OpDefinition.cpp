#include "OpDefinition.h"

#include "copper/Operator/OpNode.h"

namespace copper {

OpDefinition::OpDefinition(
	unsigned int version,
	std::string type_name,
	std::string ui_name,
	opConstructor op_contructor,
	std::vector<OpDataSocket> inputs,
	std::vector<OpDataSocket> outputs,
	OpDefinition::Flags flags
	): 
	_version(version), 
	_type_name(type_name), 
	_ui_name(ui_name), 
	_opConstructor(op_contructor), 
	_inputs(inputs), 
	_outputs(outputs),
	_flags(flags) { }

std::string OpDefinition::typeName() const {
	return _type_name;
}

opConstructor OpDefinition::constructor() const {
	return _opConstructor;
}

const std::vector<OpDataSocket> *OpDefinition::inputs() const {
	return &_inputs;
}

const std::vector<OpDataSocket> *OpDefinition::outputs() const {
	return &_outputs;
}

OpNode *OpDefinition::createOpNode(OpNode *parent_op_network, const std::string &name) {
	std::string new_node_name = name;
	
	if (name == "") {
		new_node_name = _type_name;
	}

	OpNode *op_node = new OpNode(parent_op_network, this, new_node_name);
	op_node->_operator = _opConstructor();
	op_node->_inputs = _inputs;
	op_node->_outputs = _outputs;

	return op_node;
}

}