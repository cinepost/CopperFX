#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include <boost/signals2.hpp>
	
#include "copper/OpData/OpDataBase.h"
#include "copper/Operator/OpBase.h"
#include "copper/Plugin/AbstractFactory.h"
#include "copper/Util/Singleton.h"

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpNetwork.h"
#include "copper/Operator/OpFactory.h"


namespace copper {

typedef AbstractFactory<OpDataBase> OpDataFactory;

class EngineSignals: public Singleton<EngineSignals> {
	public:
		// public engine signals
		boost::signals2::signal<void(const std::string&, const std::string&)> signalCreateOpNode;
		boost::signals2::signal<void(const std::string&, const std::string&)> signalOpNodeCreated;
		boost::signals2::signal<void(const std::string&)> signalOpNetworkChanged;
};

// Engine class is a singleton, but we might need more than one engine so  things are subject to change in the future...
class Engine: public Singleton<Engine> {

	public:
		// public engine signals
		
		//boost::signals2::signal<void(const std::string&, const std::string&)> signalCreateOpNode;
		//boost::signals2::signal<void(const std::string&, const std::string&)> signalOpNodeCreated;

  public:
		Engine();
		~Engine() {};

	public:
		void init();

		OpNetwork *root();
		OpNode *node(std::string node_path);

		float time();
		void setTime(float time);

		float frame();
		void setFrame(float frame);

		float fps();
		void setFps(float fps);

		OpDataFactory *dataFactory();
		OpFactory *opFactory();

	// signal handlers
	private:
		void onCreateOpNode(const std::string &op_node_type_name, const std::string &op_network_path);

	private:
		OpNetwork *_root;

		// animation related
		float _time, _frame, _fps;

		// Factories 
		OpDataFactory _opdata_factory;
		OpFactory _op_factory;

		bool _initialized;

};

}

#endif // ENGINE_H