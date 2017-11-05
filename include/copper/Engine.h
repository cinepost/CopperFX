#ifndef __Engine_h__
#define __Engine_h__

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Kernel.h"
//#include "GPU_Manager.h"
#include "Node/Node.h"

using namespace CopperEngine;

// Engine class is a singleton
class Engine {
    public:
    	static Engine& Instance() {
    		// this is a lazy and thread safe code
    		static Engine e;
    		return e;
    	}
		
		Node *node(std::string node_path);

		float time();
		void setTime(float time);

		float frame();
		void setFrame(float frame);

		float fps();
		void setFps(float fps);

	private:
		Engine(); // constructor is protected
		~Engine() {}; // so as destructor

		// need to forbid copying
		Engine(Engine const&) = delete;
		Engine& operator= (Engine const&) = delete;

		Kernel theKernel;

		Node *_root_node;
		std::map<std::string, Node *> _nodes_map;

		// animation related
		float _time, _frame, _fps;

};

#endif