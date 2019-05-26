#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include "copper/OpData/GeometryOpData.h"
#include "copper/Operator/OpNodeTemplate.h"
#include "copper/Operator/OpDataSocket.h"
#include "copper/Operator/OpDataSocketTemplate.h"

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
  OpDataSocketTemplateList input_socket_templates;    /// operator node inputs
  input_socket_templates.push_back(new OpDataSocketTemplate<GeometryOpData>(0, OpDataSocketTemplateFlags::INPUT_SOCKET));

  OpDataSocketTemplateList outputs_socket_templates;  /// operator node outputs
  outputs_socket_templates.push_back(new OpDataSocketTemplate<GeometryOpData>(0, OpDataSocketTemplateFlags::OUTPUT_SOCKET));

  op_table->registerOpNodeTemplate( new OpNodeTemplate(
    0,                            /// version
    "box",                        /// internal operator name
    "Box",                        /// name used in ui
    BoxGeometryOp::myConstructor, /// op constructor
    input_socket_templates,
    outputs_socket_templates,
    OpNodeTemplate::Flags::OP_FLAG_GENERATOR
  ));
}

}