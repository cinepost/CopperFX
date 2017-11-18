#include "HOM_Node.h"


//Node *(Node::*createNode)(std::string) = &Node::createNode;
//Node *(Node::*createNamedNode)(std::string, std::string) = &Node::createNode;

boost::shared_ptr<HOM_Node> HOM_Node::createNodeByType(std::string type_name) {
	return boost::shared_ptr<HOM_Node>(createNode(type_name));
}// = &Node::createNode;

boost::shared_ptr<HOM_Node> HOM_Node::createNamedNodeByType(std::string type_name, std::string name) {
	return boost::shared_ptr<HOM_Node>(createNode(type_name, name));
}// = &Node::createNode;

namespace hou {
	void export_Node() {
		boost::python::class_<HOM_Node, boost::shared_ptr<HOM_Node>>("Node", boost::python::no_init)
			.def("createNode", &HOM_Node::createNode, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("createNode", &HOM_Node::createNamedNode, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("node", &HOM_Node::node, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parent", &HOM_Node::parent, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("name", &HOM_Node::getName)
			.def("setName", &HOM_Node::setName)
			.def("cook", &HOM_Node::cook)
			;
	}
}