#include "COM/COM_Node.h"


//Node *(Node::*createNode)(std::string) = &Node::createNode;
//Node *(Node::*createNamedNode)(std::string, std::string) = &Node::createNode;

COM_Node::COM_Node(OP_Node *node) {
	this->_node = node;
}

boost::shared_ptr<COM_Node> COM_Node::createNode(std::string type_name) {
	return boost::shared_ptr<COM_Node>(new COM_Node(_node->createNode(type_name)));
}

boost::shared_ptr<COM_Node> COM_Node::createNamedNode(std::string type_name, std::string name) {
	return boost::shared_ptr<COM_Node>(new COM_Node(_node->createNode(type_name, name)));
}

boost::shared_ptr<COM_Node> COM_Node::node(std::string path) {
	return boost::shared_ptr<COM_Node>(new COM_Node(_node->node(path)));
}


namespace copper_pymodule {
	void export_Node() {
		boost::python::class_<COM_Node, boost::shared_ptr<COM_Node>>("Node", boost::python::no_init)
			.def("createNode", &COM_Node::createNode)
			.def("createNode", &COM_Node::createNamedNode)
			.def("node", &COM_Node::node)
			//.def("parent", &COM_Node::parent, boost::python::return_value_policy<boost::python::reference_existing_object>())
			//.def("name", &COM_Node::getName)
			//.def("setName", &COM_Node::setName)
			//.def("cook", &COM_Node::cook)
			;
	}
}