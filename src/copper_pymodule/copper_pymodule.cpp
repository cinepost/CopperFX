#include <boost/python.hpp>
#include <string>

#include "OP/OP_Node.h"
#include "Engine.h"

namespace python = boost::python;

Engine& engine = Engine::Instance();

namespace engine_interface {

  OP_Node* OP_Node(std::string path){ return engine.node(path); }
  float time(){ return engine.time(); }
  void setTime(float time){ engine.setTime(time); }

  float frame(){ return engine.frame(); }
  void setFrame(float frame){ engine.setFrame(frame); }
  
  float fps(){ return engine.fps(); }
  void setFps(float fps){ engine.setFps(fps); }
}

OP_Node 	*(OP_Node::*createNode)(std::string) = &OP_Node::createNode;
OP_Node 	*(OP_Node::*createNamedNode)(std::string, std::string) = &OP_Node::createNode;

BOOST_PYTHON_MODULE(hou){
    //python::def("init", &initEngine,
    //    python::return_value_policy<python::manage_new_object>());
    python::def("node", engine_interface::OP_Node, python::return_value_policy<python::reference_existing_object>());
    
    python::def("time", engine_interface::time);
    python::def("setTime", engine_interface::setTime);

    python::def("frame", engine_interface::frame);
    python::def("setFrame", engine_interface::setFrame);

    python::def("fps", engine_interface::fps);
    python::def("setFps", engine_interface::setFps);


    python::class_<OP_Node>("OP_Node", python::no_init)
        .def("createOP_Node", createNode, python::return_value_policy<python::manage_new_object>())
       	.def("createOP_Node", createNamedNode, python::return_value_policy<python::manage_new_object>())
       	.def("node", &OP_Node::node, python::return_value_policy<python::reference_existing_object>())
        .def("parent", &OP_Node::parent, python::return_value_policy<python::reference_existing_object>())
        .def("name", &OP_Node::getName)
        .def("setName", &OP_Node::setName)
        .def("cook", &OP_Node::cook);
}