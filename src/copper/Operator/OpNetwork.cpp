#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "OpNetwork.h"


namespace copper {


OpNetwork::OpNetwork(OpNetwork *parent, std::string name, OpCreator *op): OpNode::OpNode(parent, name, op) { }

OpNode *OpNetwork::createNode( const std::string &node_type_name ) {
	return createNode( node_type_name, node_type_name );
}


OpNode *OpNetwork::createNode( const std::string &node_type_name, const std::string &node_name ) {
	std::string new_node_name = buildBase1NodeName(node_name);
	//_children.insert(std::make_pair<std::string, OpNode *>(new_node_name, new OpNode(this, new_node_name)));

	OpNode *new_node = new OpNode(this, new_node_name);
	_children[new_node_name] = new_node;
	BOOST_LOG_TRIVIAL(debug) << "OpNode of type " << node_type_name << " named \"" << new_node->name() << "\" created at " << this->name();
	return new_node;
}

OpNetwork *OpNetwork::parent() {
	if(_parent == nullptr) {
		return this;
	}
	return _parent;
}

OpNetwork *OpNetwork::root() {
	if(_parent == nullptr) {
		return this;
	}
	return _parent->root();
}

bool OpNetwork::isRoot() const {
	if (_parent == nullptr) {
		return true;
	}
	return false;
}

}