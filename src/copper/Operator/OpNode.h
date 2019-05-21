#ifndef OP_NODE_H
#define OP_NODE_H

#include <string>
#include <map>
#include <unordered_map>

#include <boost/optional.hpp>

#include "copper/Util/UT_StringUtils.h"
#include "copper/OpParameter/OpParameter.h"
#include "copper/Operator/NetworkBoxItem.h"
#include "copper/Operator/OpDataSocket.h"


namespace copper {

class OpBase;
class OpDefinition;

class OpNode : public NetworkBoxItem {
	friend class Engine;
	friend class OpDefinition;

	public:
		OpNode(const OpNode &OpNode); // copy constructor

		OpNode 		*node(const std::string &node_path);
		const std::string& name() const;
		const std::string path() const;
		void setName(const std::string &name );

		std::vector<OpNode*> children() const;
		std::vector<const OpDataSocket*> inputs() const;
		std::vector<const OpDataSocket*> outputs() const;

		OpDataSocket *input(unsigned int index);
		OpDataSocket *output(unsigned int index);

		OpNode 		*createNode(const std::string &op_type_name);
		OpNode 		*createNode(const std::string &op_type_name, const std::string &node_name);

		bool setInput(unsigned int input_index, const std::string &output_op_node_path, unsigned int output_index = 0);

		virtual bool isSubnetwork() const;
		bool isRoot() const;

	protected:
		virtual OpNode 	*parent();
		virtual OpNode 	*root();

	protected:
		OpNode(OpNode *parent, OpDefinition *op_def, const std::string &name = "");
		OpNode 				*_parent;
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