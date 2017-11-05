#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <string>
#include <iostream>

#include "Math/Vector3.h"
#include "Geometry/Point.h"
#include "Node/Node.h"
#include "Engine.h"

Engine& engine = Engine::Instance();

namespace hou {

  Node* getNode(std::string path){ return engine.node(path); }
  float time(){ return engine.time(); }
  void setTime(float time){ engine.setTime(time); }

  float frame(){ return engine.frame(); }
  void setFrame(float frame){ engine.setFrame(frame); }

  float fps(){ return engine.fps(); }
  void setFps(float fps){ engine.setFps(fps); }

  void export_Vector3();
  void export_Point();
  void export_Geometry();
  void export_Node();
}

BOOST_PYTHON_MODULE(hou){
  
  boost::python::def("time", hou::time);
  boost::python::def("setTime", hou::setTime);

  boost::python::def("frame", hou::frame);
  boost::python::def("setFrame", hou::setFrame);

  boost::python::def("fps", hou::fps);
  boost::python::def("setFps", hou::setFps);

  boost::python::def("node", hou::getNode, boost::python::return_value_policy<boost::python::reference_existing_object>());

  // Vector3
  hou::export_Vector3();

  // Point
  hou::export_Point();

  // Geometry
  hou::export_Geometry();

  // Node
  hou::export_Node();

}






