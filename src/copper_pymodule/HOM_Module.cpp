#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <string>
#include <iostream>

#include "Engine.h"

#include "HOM/HOM_Node.h"
#include "HOM/HOM_Module.h"

namespace HOM {
  Engine& engine = Engine::Instance();

  float time() { return engine.time(); }
  void setTime(float time) { engine.setTime(time); }

  float frame(){ return engine.frame(); }
  void setFrame(float frame){ engine.setFrame(frame); }

  float fps(){ return engine.fps(); }
  void setFps(float fps){ engine.setFps(fps); }

  boost::shared_ptr<HOM_Node> getNode(std::string node_path) {
    return boost::shared_ptr<HOM_Node>(engine.node(node_path));
  }

  void export_Vector2();
  void export_Vector3();
  void export_Point();
  void export_Geometry();
  void export_Node();
}


BOOST_PYTHON_MODULE(HOM){
  
  boost::python::def("time", HOM::time);
  boost::python::def("setTime", HOM::setTime);

  boost::python::def("frame", HOM::frame);
  boost::python::def("setFrame", HOM::setFrame);

  boost::python::def("fps", HOM::fps);
  boost::python::def("setFps", HOM::setFps);

  boost::python::def("node", HOM::getNode, boost::python::return_value_policy<boost::python::reference_existing_object>());

  // Vectors
  HOM::export_Vector2();
  HOM::export_Vector3();

  // Point
  HOM::export_Point();

  // Geometry
  HOM::export_Geometry();

  // Node
  HOM::export_Node();

}






