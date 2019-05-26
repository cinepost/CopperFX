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

class OpNode;
class OpBase;
class OpNodeTemplate;

typedef uint64_t opnode_uuid_t;
typedef std::unordered_map<std::string, OpNode *>   opnode_by_path_hashmap_t;
typedef std::unordered_map<opnode_uuid_t, OpNode *> opnode_by_uuid_hashmap_t;

class OpNode : public NetworkBoxItem {
	friend class Engine;
	friend class OpNodeTemplate;

	public:
		OpNode(const OpNode &OpNode); // copy constructor

		OpNode 	*parent();
		OpNode 	*root();
		OpNode 	*node(const std::string &node_path);
		OpNode 	*node(opnode_uuid_t uuid);

		const std::string& name() const;
		const std::string path() const;
		void setName(const std::string &name );

		std::vector<OpNode*> children() const;
		std::vector<const OpDataSocketBase*> inputs() const;
		std::vector<const OpDataSocketBase*> outputs() const;

		OpDataSocketBase *input(unsigned int index);
		OpDataSocketBase *output(unsigned int index);

		OpNode 		*createNode(const std::string &op_type_name);
		OpNode 		*createNode(const std::string &op_type_name, const std::string &node_name);

		bool setInput(unsigned int input_index, const std::string &output_op_node_path, unsigned int output_index = 0);

		virtual bool isSubnetwork() const;
		bool isRoot() const;

		void  setX(float x);
		void  setY(float y);
		void  setPos(float x, float y);

	private:
		static opnode_uuid_t getNextNodeUUID();

	protected:
		OpNode(OpNode *parent, OpNodeTemplate *op_def, const std::string &name = "");

	protected:
		void addOpNode(OpNode *op_node);
		const std::string buildBase1NodeName(const std::string &name);

	protected:
		OpNode 					*_parent;
		std::string			_name;
		OpBase 					*_operator;
		OpNodeTemplate 	*_op_def;

		opnode_by_path_hashmap_t _children;
		opnode_by_uuid_hashmap_t _children_by_uuid;

	protected:
		uint64_t _uuid; 
		std::vector<OpDataSocketBase*> _inputs;
		std::vector<OpDataSocketBase*> _outputs;

};

}

#endif // OP_NODE_H