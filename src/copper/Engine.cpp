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

    _root = new OpNetwork(nullptr, nullptr, "/"); /// Create root node network
    _root->createNode("box"); /// test geometry node

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
        BoxGeometryOp::registerOperator(&_op_factory);
        BOOST_LOG_TRIVIAL(debug) << "Internal operators types registration done.";

        // connect engine signals
        EngineSignals::getInstance().signalCreateOpNode.connect(boost::bind(&Engine::onCreateOpNode, this, _1, _2, _3));

        _initialized = true;
        BOOST_LOG_TRIVIAL(debug) << "CopperFX engine initialization done.";
    }  
}

OpDataFactory *Engine::dataFactory(){ 
    return &_opdata_factory;
}

OpFactory *Engine::opFactory(){
    return &getInstance()._op_factory;
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
OpNode *Engine::onCreateOpNode(const std::string &op_node_type_name, const std::string &op_network_path, const std::string &node_name) {
    BOOST_LOG_TRIVIAL(debug) << "Creating OpNode of type: " << op_node_type_name;

    //OpNode *op_node = _root->createNode(op_node_type_name);
    OpDefinition *op_def = Engine::opFactory()->opDefinition(op_node_type_name);
    if (op_def == nullptr) {
        BOOST_LOG_TRIVIAL(error) << "Unable to get OpDefinition for type: " << op_node_type_name;
        return nullptr;
    }

    OpNetwork *op_network = _root;

    BOOST_LOG_TRIVIAL(debug) << "creating node";

    OpNode *new_node = op_def->createOpNode(op_network, op_network->buildBase1NodeName(op_node_type_name));
    op_network->addOpNode(new_node);
    BOOST_LOG_TRIVIAL(debug) << "OpNode of type " << op_node_type_name << " named \"" << new_node->name() << "\" created at " << op_network->path();

    EngineSignals::getInstance().signalOpNodeCreated(new_node->path(), op_network->path()); // fire node created (node_path, network_path)
    EngineSignals::getInstance().signalOpNetworkChanged(op_network->path());

    BOOST_LOG_TRIVIAL(debug) << "OpNode created path: " << new_node->path();
}

}