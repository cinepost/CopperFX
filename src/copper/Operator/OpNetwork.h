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

	public:
		OpNetwork(OpNetwork *parent, std::string name, OpCreator *op = nullptr);

		OpNode 		*createNode(std::string op_type_name);
		OpNode 		*createNode(std::string op_type_name, std::string node_name);

	private:
		std::map<std::string, OpNode *> _children;
};

}

#endif // OP_NETWORK_H