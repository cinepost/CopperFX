#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include "BoxGeometryOp.h"
#include "copper/OpData/GeometryOpData.h"

namespace copper {

BoxGeometryOp::BoxGeometryOp() {
  BOOST_LOG_TRIVIAL(debug) << "Box geometry operator constructed!";
}


BoxGeometryOp::~BoxGeometryOp() {
  BOOST_LOG_TRIVIAL(debug) << "Box geometry operator  destructed!";
}

const std::string BoxGeometryOp::name() const{
  return "Box";
}

const std::string BoxGeometryOp::typeName() const{
  return "box";
}

const unsigned int BoxGeometryOp::version() const{
	return 0;
}

bool BoxGeometryOp::cookData(OpDataBase &out_data) {
  out_data = GeometryOpData();
  return true;
}

// factory methods
std::string BoxGeometryOp::myTypeName() {
  return "box";
}

OperatorBase *BoxGeometryOp::myConstructor() {
	return new BoxGeometryOp();
}

}