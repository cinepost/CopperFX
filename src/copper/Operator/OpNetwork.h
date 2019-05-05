#ifndef OP_NETWORK_H
#define OP_NETWORK_H

#include <string>
#include <map>

#include "copper/Engine.h"
#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpCreator.h"


namespace copper {

class OpNetwork: public OpNode {
	friend class OP_Engine;
	friend class OpNode;

	public:
		OpNetwork(OpNetwork *parent, std::string name, OpCreator *op = nullptr);

		OpNode 		*createNode(const std::string &op_type_name);
		OpNode 		*createNode(const std::string &op_type_name, const std::string &node_name);

	protected:
		bool	isRoot() const;
		OpNetwork 	*parent();
		OpNetwork 	*root() override;
};

}

#endif // OP_NETWORK_H