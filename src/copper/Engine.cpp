#include <iostream>

#include "copper/Engine.h"

#include "copper/OpData/ImageOpData.h"
#include "copper/OpData/GeometryOpData.h"

#include "copper/operators/BoxGeometryOp/BoxGeometryOp.h"

namespace copper {

Engine::Engine() {
    BOOST_LOG_TRIVIAL(debug) << "Initializing CopperFX engine...";

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

    _root = new OpNetwork(nullptr, "/"); /// Create root node network
    _root->createNode("box"); /// test geometry node

    BOOST_LOG_TRIVIAL(debug) << "CopperFX engine initialization done.";
}

void Engine::init() {
    if (!_initialized) {
        // Register internally defined opdata
        _opdata_factory.registerType( GeometryOpData::myTypeName, GeometryOpData::myConstructor );
        _opdata_factory.registerType( ImageOpData::myTypeName, ImageOpData::myConstructor );

        // Register internally defined operators
        BoxGeometryOp::registerOperator(&_op_factory);  

        // connect engine signals
        EngineSignals::getInstance().signalCreateOpNode.connect(boost::bind(&Engine::onCreateOpNode, this, _1, _2));

        _initialized = true;
    }  
}

OpDataFactory *Engine::dataFactory(){ 
    return &_opdata_factory;
}

OpFactory *Engine::opFactory(){
    return &_op_factory;
}

OpNetwork *Engine::root() {
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

void Engine::onCreateOpNode(const std::string &op_node_type_name, const std::string &op_network_path) {
    BOOST_LOG_TRIVIAL(debug) << "Creating OpNode of type: " << op_node_type_name;
    OpNode *op_node = _root->createNode(op_node_type_name);
    BOOST_LOG_TRIVIAL(debug) << "OpNode created path: " << op_node->path();
}

}