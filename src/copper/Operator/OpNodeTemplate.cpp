#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "OpNodeTemplate.h"

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpDataSocket.h"


namespace copper {

OpNodeTemplate::OpNodeTemplate(
	OpTypeInfo type_info,
	opConstructor op_contructor,
	OpDataSocketTemplateList input_socket_templates,
	OpDataSocketTemplateList output_socket_templates, 
	OpNodeTemplate::Flags flags ) {

	_type_info = type_info; 
	_opConstructor = op_contructor; 
	_input_socket_templates = input_socket_templates;
	_output_socket_templates = output_socket_templates;
	_flags = flags;
}

const OpTypeInfo& OpNodeTemplate::typeInfo() const {
	return _type_info;
}

const std::string& OpNodeTemplate::typeName() const {
	return _type_info.type_name;
}

opConstructor OpNodeTemplate::constructor() const {
	return _opConstructor;
}

const OpDataSocketTemplateList *OpNodeTemplate::inputs() const {
	return &_input_socket_templates;
}

const OpDataSocketTemplateList *OpNodeTemplate::outputs() const {
	return &_output_socket_templates;
}

OpNode *OpNodeTemplate::createOpNode(OpNode *parent_op_node, const std::string &name) {
	std::string new_node_name = name;
	
	if (name == "") {
		new_node_name = _type_info.type_name;
	}

	OpNode *op_node = new OpNode(parent_op_node, this, new_node_name);

	// install operator
	op_node->_operator = _opConstructor();
	
	for(auto& input_template: _input_socket_templates) {
		op_node->_inputs.push_back(input_template.createOpDataSocket(op_node));
	}

	for(auto& output_template: _output_socket_templates) {
		op_node->_outputs.push_back(output_template.createOpDataSocket(op_node));
	}

	return op_node;
}

}