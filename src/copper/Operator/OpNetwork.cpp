#include "OpNetwork.h"


namespace copper {


OpNetwork::OpNetwork(OpNetwork *parent, std::string name, OpCreator *op): OpNode::OpNode(parent, name, op) { }

OpNode *OpNetwork::createNode( std::string node_type_name ) {
	return createNode( node_type_name, node_type_name );
}


OpNode *OpNetwork::createNode( std::string node_type_name, std::string node_name ) {
	std::string new_node_name = buildBase1NodeName(node_name);

	OpNode *new_node = new OpNode(this, new_node_name);
	new_node->setName(new_node_name);
	_children[new_node_name] = new_node;
	return new_node;
}	

}