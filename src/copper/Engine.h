#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
	
#include "copper/OpData/OpDataBase.h"
#include "copper/Operator/OpBase.h"
#include "copper/Plugin/AbstractFactory.h"
#include "copper/Util/Singleton.h"

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpNetwork.h"
#include "copper/Operator/OpFactory.h"

namespace copper {

typedef AbstractFactory<OpDataBase> OpDataFactory;
//typedef AbstractFactory<OperatorBase> OpFactory;

// Engine class is a singleton, but we might need more than one engine so 
// things may change in the future...
class Engine: public Singleton<Engine> {
  public:
		Engine();
		~Engine() {};

		void init();

		OpNode *node(std::string node_path);

		float time();
		void setTime(float time);

		float frame();
		void setFrame(float frame);

		float fps();
		void setFps(float fps);

		OpDataFactory *dataFactory();
		OpFactory *opFactory();

	private:
		OpNetwork *_root;

		// animation related
		float _time, _frame, _fps;

		// Factories 
		OpDataFactory _opdata_factory;
		OpFactory _op_factory;

};

}

#endif // ENGINE_H