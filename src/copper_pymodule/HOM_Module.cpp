#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <string>
#include <iostream>

#include "Engine.h"

#include "HOM/HOM_Node.h"
#include "HOM/HOM_Module.h"

namespace hou {
  Engine& engine = Engine::Instance();

  float time() { return engine.time(); }
  void setTime(float time) { engine.setTime(time); }

  float frame(){ return engine.frame(); }
  void setFrame(float frame){ engine.setFrame(frame); }

  float fps(){ return engine.fps(); }
  void setFps(float fps){ engine.setFps(fps); }

  boost::shared_ptr<HOM_Node> getNode(std::string node_path) {
    return boost::shared_ptr<HOM_Node>(new HOM_Node(engine.node(node_path)));
  }

  void export_Vector2();
  void export_Vector3();
  void export_Point();
  void export_Geometry();
  void export_Node();
}


BOOST_PYTHON_MODULE(hou){
  
  boost::python::def("time", &hou::time);
  boost::python::def("setTime", &hou::setTime);

  boost::python::def("frame", &hou::frame);
  boost::python::def("setFrame", &hou::setFrame);

  boost::python::def("fps", &hou::fps);
  boost::python::def("setFps", &hou::setFps);

  boost::python::def("node", &hou::getNode);

  // Vectors
  //HOM::export_Vector2();
  hou::export_Vector3();

  // Point
  hou::export_Point();

  // Geometry
  hou::export_Geometry();

  // Node
  hou::export_Node();

}






