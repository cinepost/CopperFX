#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <string>
#include <iostream>

#include "copper/Math/Vector3.h"
#include "copper/Geometry/Point.h"
#include "copper/Node/Node.h"
#include "copper/Engine.h"

#include "HOM_Module.h"

namespace HOM {
  Engine& engine = Engine::Instance();

  Node* getNode(std::string path){ return engine.node(path); }
  float time(){ return engine.time(); }
  void setTime(float time){ engine.setTime(time); }

  float frame(){ return engine.frame(); }
  void setFrame(float frame){ engine.setFrame(frame); }

  float fps(){ return engine.fps(); }
  void setFps(float fps){ engine.setFps(fps); }

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






