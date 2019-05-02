#include "copper_pymodules/HOU/HOU_Node.h"


using namespace copper;
namespace hou_module {

//Node *(Node::*createNode)(std::string) = &Node::createNode;
//Node *(Node::*createNamedNode)(std::string, std::string) = &Node::createNode;

HOU_Node::HOU_Node(OpNode *node) {
	this->_node = node;
}

boost::shared_ptr<HOU_Node> HOU_Node::createNode(std::string type_name) {
	return boost::shared_ptr<HOU_Node>(new HOU_Node(_node->createNode(type_name)));
}

boost::shared_ptr<HOU_Node> HOU_Node::createNamedNode(std::string type_name, std::string name) {
	return boost::shared_ptr<HOU_Node>(new HOU_Node(_node->createNode(type_name, name)));
}

boost::shared_ptr<HOU_Node> HOU_Node::node(std::string path) {
	return boost::shared_ptr<HOU_Node>(new HOU_Node(_node->node(path)));
}

void export_Node() {
	boost::python::class_<HOU_Node, boost::shared_ptr<HOU_Node>>("Node", boost::python::no_init)
		.def("createNode", &HOU_Node::createNode)
		.def("createNode", &HOU_Node::createNamedNode)
		.def("node", &HOU_Node::node)
		//.def("parent", &HOU_Node::parent, boost::python::return_value_policy<boost::python::reference_existing_object>())
		//.def("name", &HOU_Node::getName)
		//.def("setName", &HOU_Node::setName)
		//.def("cook", &HOU_Node::cook)
		;
}

}