#ifndef __export_Node_h__
#define __export_Node_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "OP/OP_Node.h"


class HOM_Node: public OP_Node {
	public:
		HOM_Node(OP_Node *node);
		boost::shared_ptr<HOM_Node> createNode(std::string type_name);
		boost::shared_ptr<HOM_Node> createNamedNode(std::string type_name, std::string name);
		boost::shared_ptr<HOM_Node> node(std::string path);
	private:
		OP_Node *_node;
};

#endif