#include "OpCreator.h"


namespace copper {

OpCreator::OpCreator(
	unsigned int version,
	std::string type_name,
	std::string ui_name,
	opConstructor op_contructor,
	std::vector<OpDataSocket> inputs,
	std::vector<OpDataSocket> outputs,
	Flags flags
	): 
	_version(version), 
	_type_name(type_name), 
	_ui_name(ui_name), 
	_opConstructor(op_contructor), 
	_inputs(inputs), 
	_outputs(outputs),
	_flags(flags) { }

std::string OpCreator::typeName() {
	return _type_name;
}

opConstructor OpCreator::constructor(){
	return _opConstructor;
}

}