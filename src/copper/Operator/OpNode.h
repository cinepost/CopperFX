#ifndef OP_NODE_H
#define OP_NODE_H

#include <string>
#include <map>
#include <unordered_map>

#include <boost/optional.hpp>

#include "copper/Util/UT_StringUtils.h"
#include "copper/Util/IndexableObject.h"
#include "copper/OpParameter/OpParameter.h"
#include "copper/Operator/NetworkBoxItem.h"
#include "copper/Operator/OpDataSocket.h"


namespace copper {

class OpNode;
class OpBase;
class OpNodeTemplate;

typedef std::unordered_map<std::string, OpNode *>   opnode_by_path_hashmap_t;
typedef std::unordered_map<obj_id_t, OpNode *> opnode_by_id_hashmap_t;

class OpNode : public IndexableObject, public NetworkBoxItem {
	friend class Engine;
	friend class OpNodeTemplate;

	public:
		OpNode(const OpNode &op_node); // copy constructor

		OpNode 	*parent();
		OpNode 	*root();
		OpNode 	*node(const std::string &node_path);
		OpNode 	*node(obj_id_t id);

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

		void  setX(float x);
		void  setY(float y);
		void  setPos(float x, float y);

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
		opnode_by_id_hashmap_t	 _children_by_id;

	protected:
		std::vector<OpDataSocket*> _inputs;
		std::vector<OpDataSocket*> _outputs;

};

}

#endif // OP_NODE_H