#include <boost/python.hpp>
#include <string>

#include "copper/include/Node.h"
#include "copper/include/Engine.h"

namespace python = boost::python;

Engine& engine = Engine::Instance();

Node* node(std::string path)
{
   //static Node root_node;
   return engine.node(path);
}

Node 	*(Node::*createNode)(std::string) = &Node::createNode;
Node 	*(Node::*createNamedNode)(std::string, std::string) = &Node::createNode;

BOOST_PYTHON_MODULE(hou){
    //python::def("init", &initEngine,
    //    python::return_value_policy<python::manage_new_object>());
    python::def("node", node, python::return_value_policy<python::reference_existing_object>());

    python::class_<Node>("Node", python::no_init)
        .def("createNode", createNode, python::return_value_policy<python::manage_new_object>())
       	.def("createNode", createNamedNode, python::return_value_policy<python::manage_new_object>())
       	.def("node", &Node::node, python::return_value_policy<python::reference_existing_object>())
        .def("parent", &Node::parent, python::return_value_policy<python::reference_existing_object>())
        .def("name", &Node::name)
        .def("setName", &Node::setName);
}