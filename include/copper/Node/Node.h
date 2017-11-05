#ifndef __Node_h__
#define __Node_h__

#include <string>
#include <map>
#include "UT/UT_StringUtils.h"
#include "Parameters/Parameters.h"
#include "Node/NetworkBoxItem.h"

class Node : public Parameters, public NetworkBoxItem {
	friend class OP_Engine;
	public:
		Node();
		Node(Node *parent);
		Node *parent();
		Node *createNode(std::string node_type_name);
		Node *createNode(std::string node_type_name, std::string node_name);
		Node *node(std::string node_path);
		const std::string getName();
		const std::string path();
		void setName( std::string name );
		bool cook();

	private:
		Node *rootNode();
		//virtual void cookData() = 0;
		std::string buildBase1NodeName(std::string name);

	private:
		Node *parent_node;
		std::string	name;
		std::map<std::string, Node *> child_nodes;
};

#endif