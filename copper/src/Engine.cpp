#include "../include/Engine.h"

Engine::Engine() {
	std::cout << "Initializing CopperFX engine..." << std::endl;

    // *** Create root node *** //
    _root_node = new Node();
    _root_node->setName("/");
    _nodes_map["/"] = _root_node;


    // *** Load Plugins *** //
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
}


Node *Engine::node(std::string node_path) {
	return _root_node->node(node_path);
}

Node *Engine::rootNode() {
	return _root_node;
}