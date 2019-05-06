#include <iostream>
#include <cassert>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "copper/Operator/OpBase.h"
#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpNetwork.h"
#include "copper/Operator/OpDefinition.h"

namespace copper {

OpNode::OpNode(OpNetwork *parent, OpDefinition *op_def, const std::string &name) {
	//assert(parent != nullptr && "OpNode parent pointer should never be null!");
	_parent = parent;
	_name = name;
	_op_def = op_def;
}

OpNode::OpNode(const OpNode &node){
	std::cout << "OpNode copied" << std::endl;
}

const std::string OpNode::name() const {
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

OpNetwork *OpNode::parent() {
	assert(_parent != nullptr && "OpNode parent pointer should never be null!");
	return _parent;
}

OpNetwork *OpNode::root() {
	assert(_parent != nullptr && "OpNode parent pointer should never be null!");
	return _parent->root();
}

std::vector<OpNode*> OpNode::children() const {
	std::vector<OpNode*> children;
	for (auto const& item : _children) {
    children.push_back(item.second);
	}
	return children;
}

std::vector<OpDataSocket> OpNode::inputs() const {
	return _inputs;
}

std::vector<OpDataSocket> OpNode::outputs() const {
	return _outputs;
}


const std::string OpNode::buildBase1NodeName(const std::string &name){
	if ( _children.find(name) != _children.end() ) {
		// this OpNode name already taken by child OpNode, let's rename it by Base1 rule
		return buildBase1NodeName(makeBase1String(name)); // TODO: some speedup instead of dumb recursion
	}
	return name;
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
