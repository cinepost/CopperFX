#include <iostream>

#include "copper/Engine.h"

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpDefinition.h"

#include "copper/OpData/ImageOpData.h"
#include "copper/OpData/GeometryOpData.h"

#include "copper/operators/BoxGeometryOp/BoxGeometryOp.h"


namespace copper {

Engine::Engine() {
  BOOST_LOG_TRIVIAL(debug) << "Creating CopperFX engine...";
  _initialized = false;

  // Set animation defaults
  _fps = 25.0;
  _time = 0.0;
  _frame = 1.0;

  // Load Plugins 
  /*
  bool allPluginsLoaded = true;
  try {
  	theKernel.loadPlugin("NetworkViewPanel");
  }
  catch(const std::exception &exception) {
  	allPluginsLoaded = false;
  	std::cerr << "Unhandled error: " << exception.what() << std::endl;
  }

  if (allPluginsLoaded) {
  	std::cout << "CopperFX engine initialized. All good." << std::endl;
  } else {
  	std::cout << "CopperFX engine initialized with errors. Not all plugins loaded." << std::endl;
  }
  */

  init();

  _root = new OpNode(nullptr, nullptr, "/"); /// Create root node 
  OpNode *box1 = _root->createNode("box"); /// test geometry node
  OpNode *box2 = _root->createNode("box"); /// test geometry node

  box2->setInput(0, box1->path(), 0);

  BOOST_LOG_TRIVIAL(debug) << "CopperFX engine creation done.";
}

void Engine::init() {
  if (!_initialized) {
    BOOST_LOG_TRIVIAL(debug) << "Initializing CopperFX engine...";

    // Register internally defined opdata
    BOOST_LOG_TRIVIAL(debug) << "Registering internal opdata types ...";
    _opdata_factory.registerType( GeometryOpData::myTypeName, GeometryOpData::myConstructor );
    _opdata_factory.registerType( ImageOpData::myTypeName, ImageOpData::myConstructor );
    BOOST_LOG_TRIVIAL(debug) << "Internal opdata types registration done.";

    // Register internally defined operators
    BOOST_LOG_TRIVIAL(debug) << "Registering internal operator types ...";
    BoxGeometryOp::registerOperator(&_op_table);
    BOOST_LOG_TRIVIAL(debug) << "Internal operators types registration done.";

    // connect engine signals
    EngineSignals::getInstance().signalCreateOpNode.connect(boost::bind(&Engine::onCreateOpNode, this, _1, _2, _3));
    EngineSignals::getInstance().signalConnectOpNodes.connect(boost::bind(&Engine::onConnectOpNodes, this, _1, _2, _3, _4));

    _initialized = true;
    BOOST_LOG_TRIVIAL(debug) << "CopperFX engine initialization done.";
  }  
}

OpDataFactory *Engine::dataFactory() { 
  return &_opdata_factory;
}

OpTable *Engine::opTable() {
  return &_op_table;
}

OpNode *Engine::root() {
  return _root;
}

OpNode *Engine::node(std::string node_path) {
	return _root->node(node_path);
}

float Engine::time() { return _time; }
void Engine::setTime(float time){ _time = time; }

float Engine::frame() { return _frame; }
void Engine::setFrame(float frame){ _frame = frame; }

float Engine::fps() { return _fps; }
void Engine::setFps(float fps){ _fps = fps; }

// engine signals handlers
OpNode *Engine::onCreateOpNode(const std::string &op_node_type_name, const std::string &op_node_path, const std::string &node_name) {
  BOOST_LOG_TRIVIAL(debug) << "Creating OpNode of type: " << op_node_type_name;

  OpDefinition *op_def = _op_table.opDefinition(op_node_type_name);

  if (op_def == nullptr) {
    BOOST_LOG_TRIVIAL(error) << "Unable to get OpDefinition for type: " << op_node_type_name;
    return nullptr;
  }

  OpNode *op_node = node(op_node_path);

  OpNode *new_node = op_def->createOpNode(op_node, op_node->buildBase1NodeName(op_node_type_name));
  op_node->addOpNode(new_node);
  BOOST_LOG_TRIVIAL(debug) << "OpNode of type " << op_node_type_name << " named \"" << new_node->name() << "\" created at " << op_node->path();

  EngineSignals::getInstance().signalOpNetworkChanged(op_node->path()); // notify that op_node changed

  BOOST_LOG_TRIVIAL(debug) << "OpNode created path: " << new_node->path();
  return new_node;
}

bool Engine::onConnectOpNodes(unsigned int input_index, const std::string &input_op_node_path, unsigned int output_index, const std::string &output_op_node_path) {
  BOOST_LOG_TRIVIAL(debug) << "Connecting output socket " << output_index << " of node " << output_op_node_path << " to input socket " << input_index << " of node " << input_op_node_path;
  
  OpNode *input_node = node(input_op_node_path);
  if(input_node == nullptr)return false;

  OpNode *output_node = node(output_op_node_path);
  if(output_node == nullptr)return false;

  if(input_node->parent() != output_node->parent()) {
    BOOST_LOG_TRIVIAL(error) << "Unable connect nodes on different levels! " << input_index;
    return false;
  }

  OpDataSocket *input_socket = input_node->input(input_index);
  if (input_socket == nullptr) {
    BOOST_LOG_TRIVIAL(error) << "Unable to get input data socket idx: " << input_index;
    return false;
  }

  OpDataSocket *output_socket = output_node->output(output_index);
  if (output_socket == nullptr) {
    BOOST_LOG_TRIVIAL(error) << "Unable to get output data socket idx: " << output_index;
    return false;
  }

  if (!input_socket->connect(output_socket)) return false;

  EngineSignals::getInstance().signalOpNetworkChanged(input_node->parent()->path());
  return true;
}

}