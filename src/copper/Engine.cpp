#include "copper/Engine.h"

Engine::Engine() {
    BOOST_LOG_TRIVIAL(debug) << "Initializing CopperFX engine...";

    // Create root node
    _root_node = new OP_Node();
    _root_node->setName("/");
    _nodes_map["/"] = _root_node;


    // Set animation defaults
    _fps = 24.0;
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
    BOOST_LOG_TRIVIAL(debug) << "CopperFX engine initialization done.";
}

OP_Node *Engine::node(std::string node_path) {
	return _root_node->node(node_path);
}

float Engine::time() { return _time; }
void Engine::setTime(float time){ _time = time; }

float Engine::frame() { return _frame; }
void Engine::setFrame(float frame){ _frame = frame; }

float Engine::fps() { return _fps; }
void Engine::setFps(float fps){ _fps = fps; }