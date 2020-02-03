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

boost::uuids::string_generator gen;

BoxGeometryOp::BoxGeometryOp() {
  BOOST_LOG_TRIVIAL(debug) << "Box geometry operator constructed!";
}


BoxGeometryOp::~BoxGeometryOp() {
  BOOST_LOG_TRIVIAL(debug) << "Box geometry operator destructed!";
}


bool BoxGeometryOp::cookData(uint output_index, OpDataBase &out_data) {
  out_data = GeometryOpData();
  return true;
}

// factory methods
OpBase *BoxGeometryOp::myConstructor() {
	return new BoxGeometryOp();
}

void BoxGeometryOp::registerOperator(OpTable *op_table) {  
  OpDataSocketTemplateList input_socket_templates;  /// operator node inputs
  input_socket_templates.emplace_back(OpDataSocketTemplate(0, OP_DATA_TYPE_INFO(GeometryOpData), OpDataSocketTemplateFlags::INPUT_SOCKET));

  OpDataSocketTemplateList outputs_socket_templates;  /// operator node outputs
  outputs_socket_templates.emplace_back(OpDataSocketTemplate(0,  OP_DATA_TYPE_INFO(GeometryOpData), OpDataSocketTemplateFlags::OUTPUT_SOCKET));

  OpTypeInfo up_type_info(
    "box",  // type name
    "Box",  // ui name
    0,      // version
    boost::uuids::string_generator()("{4c25ee76-72d3-4a2f-a8cc-2207fa3aca11}") // uuid
  );

  op_table->registerOpNodeTemplate(new OpNodeTemplate(
    up_type_info,
    BoxGeometryOp::myConstructor, /// op constructor
    input_socket_templates,
    outputs_socket_templates,
    OpNodeTemplate::Flags::OP_FLAG_GENERATOR
  ));
}

}