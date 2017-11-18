#include "OP/Node.h"

Node::Node(): _parent{NULL}, _name{"/"} {
	std::cout << "Node constructed" << std::endl;
}


Node::Node( Node *parent ): Node() {
	_parent = parent;
}

Node::Node(const Node &node){
	std::cout << "Node copied" << std::endl;
}

const std::string Node::getName() {
	return _name;
}


void Node::setName( std::string name ) {
	_name = name;
}


const std::string Node::path() {
	return _name;
}


Node *Node::parent() {
	return _parent;
}


Node *Node::rootNode() {
	if (!_parent) return this;
	return _parent->rootNode();
}


std::string Node::buildBase1NodeName(std::string name){
	if ( _children.find(name) != _children.end() ) {
		// this Node name already taken by child Node, let's rename it by Base1 rule
		return buildBase1NodeName(makeBase1String(name)); // TODO: some speedup instead of dumb recursion
	}
	return name;
}


Node *Node::createNode( std::string node_type_name ) {
	return createNode( node_type_name, node_type_name );
}


Node *Node::createNode( std::string node_type_name, std::string node_name ) {
	std::string new_node_name = buildBase1NodeName(node_name);

	Node *new_node = new Node(this);
	new_node->setName(new_node_name);
	_children[new_node_name] = new_node;
	return new_node;
}


Node *Node::node( std::string node_path ) {
	// if path is "/" return root Node
	if (node_path == "/"){
		return rootNode();
	}
	
	// split path by "/" and look for child Node
	std::size_t found = node_path.find_first_of("/");

	// if path starts with "/" return Node with path from root
	if (found == 0) {
		return rootNode()->node(node_path.substr(1));
	}

	std::map<std::string, Node *>::iterator it;
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

	return NULL;
}

bool Node::cook() {
	return true;
}






