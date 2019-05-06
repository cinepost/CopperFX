#ifndef OP_NODE_H
#define OP_NODE_H

#include <string>
#include <map>
#include <unordered_map>

#include "copper/Util/UT_StringUtils.h"
#include "copper/OpParameter/OpParameter.h"
#include "copper/Operator/NetworkBoxItem.h"
#include "copper/Operator/OpDataSocket.h"


namespace copper {

class OpBase;
class OpNetwork;
class OpDefinition;

class OpNode : public NetworkBoxItem {
	friend class Engine;
	friend class OpNetwork;
	friend class OpDefinition;

	public:
		OpNode(const OpNode &OpNode); // copy constructor

		OpNode 		*node(const std::string &node_path);
		const std::string name() const;
		const std::string path() const;
		void setName(const std::string &name );

		std::vector<OpNode*> children() const;
		std::vector<OpDataSocket> inputs() const;
		std::vector<OpDataSocket> outputs() const;

		virtual OpNetwork *castToOpNetwork();

	protected:
		virtual OpNetwork 	*parent();
		virtual OpNetwork 	*root();

	protected:
		OpNode(OpNetwork *parent, OpDefinition *op_def, const std::string &name = "");
		OpNetwork 		*_parent;
		std::string		_name;
		OpBase 				*_operator;
		OpDefinition 	*_op_def;

		std::unordered_map<std::string, OpNode *> _children;

		std::vector<OpDataSocket> _inputs;
		std::vector<OpDataSocket> _outputs;

		void addOpNode(OpNode *op_node);
		const std::string buildBase1NodeName(const std::string &name);

};

}

#endif // OP_NODE_H