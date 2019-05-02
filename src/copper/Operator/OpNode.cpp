#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpNetwork.h"

namespace copper {

OpNode::OpNode(OpNetwork *parent, std::string name, OpCreator *op) {
	_parent = parent;
	_name = name;
	_operator = nullptr;
}

OpNode::OpNode(const OpNode &node){
	std::cout << "OpNode copied" << std::endl;
}

const std::string OpNode::getName() {
	return _name;
}

void OpNode::setName( std::string name ) {
	_name = name;
}

const std::string OpNode::path() {
	return _name;
}

OpNetwork *OpNode::parent() const {
	return _parent;
}

OpNetwork *OpNode::root() const {
	return _parent->root();
}

std::string OpNode::buildBase1NodeName(std::string name){
	if ( _children.find(name) != _children.end() ) {
		// this OpNode name already taken by child OpNode, let's rename it by Base1 rule
		return buildBase1NodeName(makeBase1String(name)); // TODO: some speedup instead of dumb recursion
	}
	return _name;
}

OpNode *OpNode::node( std::string node_path ) {
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

	std::map<std::string, OpNode *>::iterator it;
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
