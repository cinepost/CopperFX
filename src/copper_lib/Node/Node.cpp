#include "Node/Node.h"

Node::Node() {
	// This constructor is called only once, when root Node created. //
	name = "/";
	parent_node = NULL;
	child_nodes.empty();
}


Node::Node( Node *parent ) {
	Node();
	parent_node = parent;
}


const std::string Node::getName() {
	return name;
}


void Node::setName( std::string name ) {
	this->name = name;
}


const std::string Node::path() {
	return name;
}


Node *Node::parent() {
	return parent_node;
}


Node *Node::rootNode() {
	if (!parent_node) return this;
	return parent_node->rootNode();
}


std::string Node::buildBase1NodeName(std::string name){
	if ( child_nodes.find(name) != child_nodes.end() ) {
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
	child_nodes[new_node_name] = new_node;
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
		it = child_nodes.find(node_path);
		if ( it != child_nodes.end() ) return it->second;
	}else{
		std::string node_name = node_path.substr(0, found + 1);
		std::string path = node_path.substr(found + 2);
		it = child_nodes.find(node_name);
		if ( it != child_nodes.end() ) return it->second->node(path);
	}

	return NULL;
}

bool Node::cook() {
	return true;
}






