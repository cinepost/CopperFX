#include <boost/python.hpp>

#include "copper/Node/Node.h"

Node *(Node::*createNode)(std::string) = &Node::createNode;
Node *(Node::*createNamedNode)(std::string, std::string) = &Node::createNode;

namespace hou {
	void export_Node() {
		boost::python::class_<Node>("Node", boost::python::no_init)
			.def("createNode", createNode, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("createNode", createNamedNode, boost::python::return_value_policy<boost::python::manage_new_object>())
			.def("node", &Node::node, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parent", &Node::parent, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("name", &Node::getName)
			.def("setName", &Node::setName)
			.def("cook", &Node::cook)
			;
	}
}