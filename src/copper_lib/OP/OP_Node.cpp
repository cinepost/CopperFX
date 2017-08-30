#include "OP/OP_Node.h"

OP_Node::OP_Node() {
	// This constructor is called only once, when root OP_Node created. //
	name = "/";
	parent_node = NULL;
	child_nodes.empty();
}


OP_Node::OP_Node( OP_Node *parent ) {
	OP_Node();
	parent_node = parent;
}


const std::string OP_Node::getName() {
	return name;
}


void OP_Node::setName( std::string name ) {
	this->name = name;
}


const std::string OP_Node::path() {
	return name;
}


OP_Node *OP_Node::parent() {
	return parent_node;
}


OP_Node *OP_Node::rootNode() {
	if (!parent_node) return this;
	return parent_node->rootNode();
}


std::string OP_Node::buildBase1NodeName(std::string name){
	if ( child_nodes.find(name) != child_nodes.end() ) {
		// this OP_Node name already taken by child OP_Node, let's rename it by Base1 rule
		return buildBase1NodeName(makeBase1String(name)); // TODO: some speedup instead of dumb recursion
	}
	return name;
}


OP_Node *OP_Node::createNode( std::string node_type_name ) {
	return createNode( node_type_name, node_type_name );
}


OP_Node *OP_Node::createNode( std::string node_type_name, std::string node_name ) {
	std::string new_node_name = buildBase1NodeName(node_name);

	OP_Node *new_node = new OP_Node(this);
	new_node->setName(new_node_name);
	child_nodes[new_node_name] = new_node;
	return new_node;
}


OP_Node *OP_Node::node( std::string node_path ) {
	// if path is "/" return root OP_Node
	if (node_path == "/"){
		return rootNode();
	}
	
	// split path by "/" and look for child OP_Node
	std::size_t found = node_path.find_first_of("/");

	// if path starts with "/" return OP_Node with path from root
	if (found == 0) {
		return rootNode()->node(node_path.substr(1));
	}

	std::map<std::string, OP_Node *>::iterator it;
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

bool OP_Node::cook() {
	return true;
}





