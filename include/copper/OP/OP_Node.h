#ifndef __OP_Node_h__
#define __OP_Node_h__

#include <string>
#include <map>

#include "UT/UT_StringUtils.h"
#include "PRM/Parameters.h"
#include "OP/OP_NetworkBoxItem.h"

class OP_Node : public Parameters, public OP_NetworkBoxItem {
	friend class OP_Engine;
	public:
		OP_Node();
		OP_Node(OP_Node *parent);
		OP_Node(const OP_Node &OP_Node); // copy constructor

		OP_Node *parent();
		OP_Node *createNode(std::string OP_Node_type_name);
		OP_Node *createNode(std::string OP_Node_type_name, std::string OP_Node_name);
		OP_Node *node(std::string OP_Node_path);
		const std::string getName();
		const std::string path();
		void setName( std::string name );
		bool cook();

	private:
		OP_Node *rootNode();
		//virtual void cookData() = 0;
		std::string buildBase1NodeName(std::string name);

	private:
		OP_Node *_parent;
		std::string	_name;
		std::map<std::string, OP_Node *> _children;
};

#endif