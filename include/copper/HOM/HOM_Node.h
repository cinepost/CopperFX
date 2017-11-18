#ifndef __export_Node_h__
#define __export_Node_h__

#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <vector>

#include "OP/Node.h"


class HOM_Node: public Node {
	public:
		boost::shared_ptr<HOM_Node> createNode(std::string type_name);// = &Node::createNode;
		boost::shared_ptr<HOM_Node> createNamedNode(std::string type_name, std::string name);// = &Node::createNode;
};

#endif