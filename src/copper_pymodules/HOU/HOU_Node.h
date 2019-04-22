#ifndef HOU_NODE_H
#define HOU_NODE_H

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "copper/Operator/OP_Node.h"


using namespace copper;
namespace hou_module {

class HOU_Node: public OP_Node {
	public:
		HOU_Node(OP_Node *node);
		boost::shared_ptr<HOU_Node> createNode(std::string type_name);
		boost::shared_ptr<HOU_Node> createNamedNode(std::string type_name, std::string name);
		boost::shared_ptr<HOU_Node> node(std::string path);
	private:
		OP_Node *_node;
};

void export_Node();

}

#endif