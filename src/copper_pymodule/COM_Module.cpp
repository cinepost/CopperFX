#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <string>
#include <iostream>

#include "copper/Engine.h"

#include "copper_pymodule/COM/COM_Node.h"
#include "copper_pymodule/COM/COM_Module.h"

namespace copper_pymodule {
  Engine& engine = Engine::getInstance();

  float time() { return engine.time(); }
  void setTime(float time) { engine.setTime(time); }

  float frame(){ return engine.frame(); }
  void setFrame(float frame){ engine.setFrame(frame); }

  float fps(){ return engine.fps(); }
  void setFps(float fps){ engine.setFps(fps); }

  boost::shared_ptr<COM_Node> getNode(std::string node_path) {
    return boost::shared_ptr<COM_Node>(new COM_Node(engine.node(node_path)));
  }

  void export_Vector2();
  void export_Vector3();
  void export_Point();
  void export_Geometry();
  void export_Node();


  BOOST_PYTHON_MODULE(cfx){
    
    boost::python::def("time", &time);
    boost::python::def("setTime", &setTime);

    boost::python::def("frame", &frame);
    boost::python::def("setFrame", &setFrame);

    boost::python::def("fps", &fps);
    boost::python::def("setFps", &setFps);

    boost::python::def("node", &getNode);

    // Vectors
    export_Vector3();

    // Point
    export_Point();

    // Geometry
    export_Geometry();

    // Node
    export_Node();

  }
}





