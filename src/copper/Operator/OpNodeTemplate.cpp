#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "OpNodeTemplate.h"

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpDataSocket.h"


namespace copper {

OpNodeTemplate::OpNodeTemplate(
	unsigned int version,
	std::string type_name,
	std::string ui_name,
	opConstructor op_contructor,
	OpDataSocketTemplateList input_socket_templates,
	OpDataSocketTemplateList output_socket_templates, 
	OpNodeTemplate::Flags flags ) {

	_version  = version;
	_type_name = type_name; 
	_ui_name = ui_name;
	_opConstructor = op_contructor; 
	_input_socket_templates = input_socket_templates;
	_output_socket_templates = output_socket_templates;
	_flags = flags;
}

const std::string& OpNodeTemplate::typeName() const {
	return _type_name;
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
		new_node_name = _type_name;
	}

	OpNode *op_node = new OpNode(parent_op_node, this, new_node_name);

	// TODO: add all necessary check to validate sockets

	op_node->_operator = _opConstructor();
	
	for(auto& input_template: _input_socket_templates) {
		op_node->_inputs.push_back(input_template.createOpDataSocket());
	}

	for(auto& output_template: _output_socket_templates) {
		op_node->_outputs.push_back(output_template.createOpDataSocket());
	}
	/*
	op_node->_inputs = _inputs;
	for(auto input: op_node->_inputs) {
		input._op_node = op_node;
	}
	op_node->_outputs = _outputs;
	for(auto output: op_node->_inputs) {
		output._op_node = op_node;
	}
	*/

	return op_node;
}

}