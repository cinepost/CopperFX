#include <boost/python.hpp>
#include <string>

#include "copper/include/Node.h"
#include "copper/include/Engine.h"

namespace python = boost::python;

Engine& engine = Engine::Instance();

namespace engine_interface {

  Node* node(std::string path){ return engine.node(path); }
  float time(){ return engine.time(); }
  void setTime(float time){ engine.setTime(time); }

  float frame(){ return engine.frame(); }
  void setFrame(float frame){ engine.setFrame(frame); }
  
  float fps(){ return engine.fps(); }
  void setFps(float fps){ engine.setFps(fps); }
}

Node 	*(Node::*createNode)(std::string) = &Node::createNode;
Node 	*(Node::*createNamedNode)(std::string, std::string) = &Node::createNode;

BOOST_PYTHON_MODULE(hou){
    //python::def("init", &initEngine,
    //    python::return_value_policy<python::manage_new_object>());
    python::def("node", engine_interface::node, python::return_value_policy<python::reference_existing_object>());
    
    python::def("time", engine_interface::time);
    python::def("setTime", engine_interface::setTime);

    python::def("frame", engine_interface::frame);
    python::def("setFrame", engine_interface::setFrame);

    python::def("fps", engine_interface::fps);
    python::def("setFps", engine_interface::setFps);


    python::class_<Node>("Node", python::no_init)
        .def("createNode", createNode, python::return_value_policy<python::manage_new_object>())
       	.def("createNode", createNamedNode, python::return_value_policy<python::manage_new_object>())
       	.def("node", &Node::node, python::return_value_policy<python::reference_existing_object>())
        .def("parent", &Node::parent, python::return_value_policy<python::reference_existing_object>())
        .def("name", &Node::name)
        .def("setName", &Node::setName);
}