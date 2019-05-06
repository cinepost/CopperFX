#ifndef OP_NETWORK_H
#define OP_NETWORK_H

#include <string>
#include <map>

#include "copper/Engine.h"
#include "copper/Operator/OpNode.h"


namespace copper {

class OpDefinition;

class OpNetwork: public OpNode {
	friend class OP_Engine;
	friend class OpNode;

	public:
		OpNetwork(OpNetwork *parent, OpDefinition *op_def, const std::string &name);

		OpNode 		*createNode(const std::string &op_type_name);
		OpNode 		*createNode(const std::string &op_type_name, const std::string &node_name);

	protected:
		bool	isRoot() const;
		OpNetwork 	*parent();
		OpNetwork 	*root() override;
};

}

#endif // OP_NETWORK_H