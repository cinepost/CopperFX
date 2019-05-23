#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include "copper/OpData/GeometryOpData.h"
#include "copper/Operator/OpDataSocket.h"
#include "copper/Operator/OpDefinition.h"

#include "BoxGeometryOp.h"

namespace copper {

BoxGeometryOp::BoxGeometryOp() {
  BOOST_LOG_TRIVIAL(debug) << "Box geometry operator constructed!";
}


BoxGeometryOp::~BoxGeometryOp() {
  BOOST_LOG_TRIVIAL(debug) << "Box geometry operator destructed!";
}


bool BoxGeometryOp::cookData(uint output_index, OpDataBase &out_data) {
  //out_data = GeometryOpData();
  return true;
}

// factory methods
OpBase *BoxGeometryOp::myConstructor() {
	return new BoxGeometryOp();
}

void BoxGeometryOp::registerOperator(OpTable *op_table) {
  std::vector<OpDataSocket> input_sockets;    /// operator inputs
  input_sockets.emplace_back(OpDataSocket(0, 0, "geometry", OpDataSocket::Flags::INPUT_SOCKET));

  std::vector<OpDataSocket> outputs_sockets;  /// operator outputs
  outputs_sockets.emplace_back(OpDataSocket(0, 0, "geometry", OpDataSocket::Flags::OUTPUT_SOCKET));

  op_table->registerOpDefinition( new OpDefinition(
    0,                            // version
    "box",                        /// internal operator name
    "Box",                        /// name used in ui
    BoxGeometryOp::myConstructor, /// op constructor
    input_sockets,
    outputs_sockets,
    OpDefinition::Flags::OP_FLAG_GENERATOR
  ));
}

}