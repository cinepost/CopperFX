#include "HOM/HOM_Node.h"


//Node *(Node::*createNode)(std::string) = &Node::createNode;
//Node *(Node::*createNamedNode)(std::string, std::string) = &Node::createNode;

HOM_Node::HOM_Node(OP_Node *node) {
	this->_node = node;
}

boost::shared_ptr<HOM_Node> HOM_Node::createNode(std::string type_name) {
	return boost::shared_ptr<HOM_Node>(new HOM_Node(_node->createNode(type_name)));
}

boost::shared_ptr<HOM_Node> HOM_Node::createNamedNode(std::string type_name, std::string name) {
	return boost::shared_ptr<HOM_Node>(new HOM_Node(_node->createNode(type_name, name)));
}

boost::shared_ptr<HOM_Node> HOM_Node::node(std::string path) {
	return boost::shared_ptr<HOM_Node>(new HOM_Node(_node->node(path)));
}


namespace hou {
	void export_Node() {
		boost::python::class_<HOM_Node, boost::shared_ptr<HOM_Node>>("Node", boost::python::no_init)
			.def("createNode", &HOM_Node::createNode)
			.def("createNode", &HOM_Node::createNamedNode)
			.def("node", &HOM_Node::node)
			//.def("parent", &HOM_Node::parent, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//.def("name", &HOM_Node::getName)
			//.def("setName", &HOM_Node::setName)
			//.def("cook", &HOM_Node::cook)
			;
	}
}