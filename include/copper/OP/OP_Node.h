#ifndef __OP_Node_h__
#define __OP_Node_h__

#include <string>
#include <map>
#include "UT/UT_StringUtils.h"
#include "OP/OP_Parameters.h"
#include "OP/OP_NetworkBoxItem.h"

class OP_Node : public OP_Parameters, public OP_NetworkBoxItem {
	friend class OP_Engine;
	public:
		OP_Node();
		OP_Node(OP_Node *parent);
		OP_Node *parent();
		OP_Node *createNode(std::string node_type_name);
		OP_Node *createNode(std::string node_type_name, std::string node_name);
		OP_Node *node(std::string node_path);
		const std::string getName();
		const std::string path();
		void setName( std::string name );
		bool cook();

	private:
		OP_Node *rootNode();
		//virtual void cookData() = 0;
		std::string buildBase1NodeName(std::string name);

	private:
		OP_Node *parent_node;
		std::string	name;
		std::map<std::string, OP_Node *> child_nodes;
};

#endif