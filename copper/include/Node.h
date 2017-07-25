#ifndef __Node_h__
#define __Node_h__

#include <string>
#include <map>
#include "String_Utils.h"
#include "Parameters.h"
#include "NodeNetworkItem.h"

class Engine;

class Node : public Parameters, public NodeNetworkItem {
	friend class Engine;
	public:
		Node();
		Node(Node *parent);
		Node *parent();
		Node *rootNode();
		Node *createNode(std::string node_type_name);
		Node *createNode(std::string node_type_name, std::string node_name);
		Node *node(std::string node_path);
		const std::string name();
		const std::string path();
		void setName( std::string name );
		bool isRoot();

	private:
		std::string buildBase1NodeName(std::string name);

	private:
		Node *_parent_node;
		std::string	_name;
		std::map<std::string, Node *> _child_nodes;
};

#endif