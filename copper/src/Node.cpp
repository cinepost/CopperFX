#include "../include/Node.h"

Node::Node() {
	// This constructor is called only once, when root node created. //
	_name = "/";
	_parent_node = NULL;
	_child_nodes.empty();
}


Node::Node( Node *parent ) {
	Node();
	_parent_node = parent;
}


const std::string Node::name() {
	return _name;
}


void Node::setName( std::string name ) {
	_name = name;
}


const std::string Node::path() {
	return _name;
}


Node *Node::parent() {
	return _parent_node;
}


Node *Node::rootNode() {
	if (isRoot()) return this;
	return _parent_node->rootNode();
}


bool Node::isRoot() {
	if ( _parent_node ) return false;
	return true;
}


std::string Node::buildBase1NodeName(std::string name){
	if ( _child_nodes.find(name) != _child_nodes.end() ) {
		// this node name already taken by child node, let's rename it by Base1 rule
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
	_child_nodes[new_node_name] = new_node;
	return new_node;
}


Node *Node::node( std::string node_path ) {
	// if path is "/" return root node
	if (node_path == "/"){
		return rootNode();
	}
	
	// split path by "/" and look for child node
	std::size_t found = node_path.find_first_of("/");

	// if path starts with "/" return node with path from root
	if (found == 0) {
		return rootNode()->node(node_path.substr(1));
	}

	std::map<std::string, Node *>::iterator it;
	if (found == std::string::npos) {
		// no "/" in path name, search for child with this name
		it = _child_nodes.find(node_path);
		if ( it != _child_nodes.end() ) return it->second;
	}else{
		std::string node_name = node_path.substr(0, found + 1);
		std::string path = node_path.substr(found + 2);
		it = _child_nodes.find(node_name);
		if ( it != _child_nodes.end() ) return it->second->node(path);
	}

	return NULL;
}






