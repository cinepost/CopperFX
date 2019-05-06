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
	boost::optional<OpNode *> new_node = EngineSignals::getInstance().signalCreateOpNode(node_type_name, this->path(), node_name );
	if (new_node) {
		return *new_node;
	}
	return nullptr;
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