#include <iostream>
#include <cassert>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "copper/Engine.h"

#include "copper/Operator/OpBase.h"
#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpDefinition.h"

namespace copper {

OpNode::OpNode(OpNode *parent, OpDefinition *op_def, const std::string &name) {
	//assert(parent != nullptr && "OpNode parent pointer should never be null!");
	_parent = parent;
	_name = name;
	_op_def = op_def;

	_inputs.empty();
	_outputs.empty();
}

OpNode::OpNode(const OpNode &node){
	std::cout << "OpNode copied" << std::endl;
}

const std::string& OpNode::name() const {
	return _name;
}

void OpNode::setName(const std::string &name ) {
	_name = buildBase1NodeName(name);
}

const std::string OpNode::path() const {
	if (_parent == nullptr ) {
		return _name;
	} else if (_parent->isRoot()) {
		return  "/" + _name;
	}
	return _parent->path() + "/" + _name;
}

OpNode *OpNode::parent() {
	return _parent;
}

OpNode *OpNode::root() {
	if (_parent) {
		return _parent->root();
	}
	return this;
}

std::vector<OpNode*> OpNode::children() const {
	std::vector<OpNode*> children;
	for (auto const& item : _children) {
    children.push_back(item.second);
	}
	return children;
}

std::vector<const OpDataSocket*> OpNode::inputs() const {
	std::vector<const OpDataSocket*> ins;
	for (auto const& in: _inputs)
		ins.push_back(&in);
	return ins;
}

std::vector<const OpDataSocket*> OpNode::outputs() const {
	std::vector<const OpDataSocket*> outs;
	for (auto const& out: _outputs)
		outs.push_back(&out);
	return outs;
}

OpDataSocket *OpNode::input(unsigned int index) {
	if (index < _inputs.size()) { 
		return &_inputs[index]; 
	}
	return nullptr;
}

OpDataSocket *OpNode::output(unsigned int index) {
	if (index < _outputs.size()) { 
		return &_outputs[index]; 
	}
	return nullptr;
}

bool OpNode::isSubnetwork() const {
	return false;
}

bool OpNode::isRoot() const {
	if (_parent) {
		return false;
	}
	return true;
}

const std::string OpNode::buildBase1NodeName(const std::string &name){
	if ( _children.find(name) != _children.end() ) {
		// this OpNode name already taken by child OpNode, let's rename it by Base1 rule
		return buildBase1NodeName(makeBase1String(name)); // TODO: some speedup instead of dumb recursion
	}
	return name;
}

OpNode *OpNode::createNode( const std::string &node_type_name ) {
	return createNode( node_type_name, node_type_name );
}

OpNode *OpNode::createNode( const std::string &node_type_name, const std::string &node_name ) {
	boost::optional<OpNode *> new_node = EngineSignals::getInstance().signalCreateOpNode(node_type_name, this->path(), node_name );
	if (new_node)
		return *new_node;
	
	return nullptr;
}

bool OpNode::setInput(unsigned int input_index, const std::string &output_op_node_path, unsigned int output_index) {
	boost::optional<bool> connected = EngineSignals::getInstance().signalConnectOpNodes(input_index, this->path(), output_index, output_op_node_path);
	if (connected)
		return *connected;

	return false;
}

void OpNode::setX(float x) {
	NetworkBoxItem::setX(x);
	EngineSignals::getInstance().signalOpNodePosChanged(this->path());
}

void OpNode::setY(float y) {
	NetworkBoxItem::setY(y);
	EngineSignals::getInstance().signalOpNodePosChanged(this->path());
}

void OpNode::setPos(float x, float y) {
	NetworkBoxItem::setPos(x, y);
	EngineSignals::getInstance().signalOpNodePosChanged(this->path());
}

void OpNode::addOpNode(OpNode *op_node) {
	_children[op_node->name()] = op_node;
}

OpNode *OpNode::node( const std::string &node_path ) {
	// if path is "/" return root OpNode
	if (node_path == "/"){
		return root();
	}
	
	// split path by "/" and look for child OpNode
	std::size_t found = node_path.find_first_of("/");

	// if path starts with "/" return OpNode with path from root
	if (found == 0) {
		return root()->node(node_path.substr(1));
	}

	std::unordered_map<std::string, OpNode *>::iterator it;
	if (found == std::string::npos) {
		// no "/" in path name, search for child with this name
		it = _children.find(node_path);
		if ( it != _children.end() ) return it->second;
	}else{
		std::string node_name = node_path.substr(0, found + 1);
		std::string path = node_path.substr(found + 2);
		it = _children.find(node_name);
		if ( it != _children.end() ) return it->second->node(path);
	}

	return nullptr;
}

}
