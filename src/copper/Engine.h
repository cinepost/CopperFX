#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
	
//#include "GPU/GPU_Manager.h"
#include "copper/Util/Singleton.h"
#include "copper/Operator/OP_Node.h"


namespace copper {

// Engine class is a singleton, but we might need more than one engine so 
// things may change in the future...
class Engine: public Singleton<Engine> {
  public:
		Engine();
		~Engine() {};

		OP_Node *node(std::string node_path);

		float time();
		void setTime(float time);

		float frame();
		void setFrame(float frame);

		float fps();
		void setFps(float fps);

	private:
		OP_Node *_root_node;
		std::map<std::string, OP_Node *> _nodes_map;

		// animation related
		float _time, _frame, _fps;

};

}

#endif // ENGINE_H