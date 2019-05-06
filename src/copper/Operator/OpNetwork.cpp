#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include "copper/Operator/OpDefinition.h"
#include "OpNetwork.h"


namespace copper {

OpNetwork::OpNetwork(OpNetwork *parent, OpDefinition *op_def, const std::string &name): OpNode::OpNode(parent, op_def, name ) { }

OpNode *OpNetwork::createNode( const std::string &node_type_name ) {
	return createNode( node_type_name, node_type_name );
}

OpNode *OpNetwork::createNode( const std::string &node_type_name, const std::string &node_name ) {
	/*
	BOOST_LOG_TRIVIAL(debug) << "Creating OpNode of type " << node_type_name;

	std::string new_node_name = buildBase1NodeName(node_name);
	BOOST_LOG_TRIVIAL(debug) << "get op definition";
	OpDefinition * op_def = Engine::opFactory()->opDefinition(node_type_name);
	BOOST_LOG_TRIVIAL(debug) << "creating node";
	op_def->createOpNode(this, node_name);

	OpNode *new_node = new OpNode(this, new_node_name);
	_children[new_node_name] = new_node;
	BOOST_LOG_TRIVIAL(debug) << "OpNode of type " << node_type_name << " named \"" << new_node->name() << "\" created at " << this->name();

	EngineSignals::getInstance().signalOpNodeCreated(new_node->path(), this->path()); // fire node created (node_path, network_path)
	EngineSignals::getInstance().signalOpNetworkChanged(this->path());
	*/
	return EngineSignals::getInstance().signalCreateOpNode(node_type_name, this->path(), node_name );
}

OpNetwork *OpNetwork::parent() {
	if (_parent == nullptr) {
		return this;
	}
	return _parent;
}

OpNetwork *OpNetwork::root() {
	if (_parent == nullptr) {
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