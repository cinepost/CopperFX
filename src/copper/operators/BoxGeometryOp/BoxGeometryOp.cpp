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
  TypeInfo input_data_type {
    "geo",
    "Geometry",
    0,
    boost::uuids::string_generator()("{dc4f6d0e-12e1-4273-a9d5-8bcf146e09dd}"),
  };

  OpDataSocketTemplateList input_socket_templates;  /// operator node inputs
  input_socket_templates.emplace_back(OpDataSocketTemplate(0, input_data_type, OpDataSocketTemplateFlags::INPUT_SOCKET));

  TypeInfo output_data_type {
    "geo",
    "Geometry",
    0,
    boost::uuids::string_generator()("{dc4f6d0e-12e1-4273-a9d5-8bcf146e09dd}"),
  };

  OpDataSocketTemplateList outputs_socket_templates;  /// operator node outputs
  outputs_socket_templates.emplace_back(OpDataSocketTemplate(0, output_data_type, OpDataSocketTemplateFlags::OUTPUT_SOCKET));

  OpTypeInfo info_1(
    "box",  // type name
    "Box",  // ui name
    1,      // version
    boost::uuids::string_generator()("{4c25ee76-72d3-4a2f-a8cc-2207fa3aca11}") // uuid
  );

  op_table->registerOpNodeTemplate(new OpNodeTemplate(
    info_1,
    BoxGeometryOp::myConstructor, /// op constructor
    input_socket_templates,
    outputs_socket_templates,
    OpNodeTemplate::Flags::OP_FLAG_GENERATOR
  ));

  OpTypeInfo info_0(
    "box",  // type name
    "Box",  // ui name
    0,      // version
    boost::uuids::string_generator()("{4c25ee76-72d3-4a2f-a8cc-2207fa3aca11}") // uuid
  );

  op_table->registerOpNodeTemplate(new OpNodeTemplate(
    info_0,
    BoxGeometryOp::myConstructor, /// op constructor
    input_socket_templates,
    outputs_socket_templates,
    OpNodeTemplate::Flags::OP_FLAG_GENERATOR
  ));

  OpTypeInfo info_2(
    "box",  // type name
    "Box",  // ui name
    2,      // version
    boost::uuids::string_generator()("{4c25ee76-72d3-4a2f-a8cc-2207fa3aca11}") // uuid
  );

  op_table->registerOpNodeTemplate(new OpNodeTemplate(
    info_2,
    BoxGeometryOp::myConstructor, /// op constructor
    input_socket_templates,
    outputs_socket_templates,
    OpNodeTemplate::Flags::OP_FLAG_GENERATOR
  ));
}

}