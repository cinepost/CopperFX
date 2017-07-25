#ifndef __Engine_h__
#define __Engine_h__

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Kernel.h"
//#include "GPU_Manager.h"
#include "Node.h"

using namespace CopperEngine;

// Engine class is a singleton
class Engine: public Node {
    public:
    	static Engine& Instance() {
    		// this is a lazy and thread safe code
    		static Engine e;
    		return e;
    	}
		
		Node *node(std::string node_path);
		Node *rootNode();

	private:
		Engine(); // constructor is protected
		~Engine() {}; // so as destructor

		// need to forbid copying
		Engine(Engine const&) = delete;
		Engine& operator= (Engine const&) = delete;

		Kernel theKernel;

		Node *_root_node;
		std::map<std::string, Node *> _nodes_map;

};

#endif