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
#include "copper/Operator/OpTable.h"


namespace copper {

typedef AbstractFactory<OpDataBase> OpDataFactory;

class OpNode;

class EngineSignals: public Singleton<EngineSignals> {
	public:
		// public engine signals
		boost::signals2::signal<OpNode*(const std::string&, const std::string&, const std::string&)> signalCreateOpNode;
		boost::signals2::signal<bool(unsigned int, const std::string&, unsigned int, const std::string&)> signalConnectOpNodes;

		boost::signals2::signal<void(const std::string&, const std::string&)> signalOpNodeCreated;
		boost::signals2::signal<void(const std::string&)> signalOpNetworkChanged;
		boost::signals2::signal<void(const std::string&)> signalOpNodePosChanged;
};

// Engine class is a singleton, but we might need more than one engine so  things are subject to change in the future...
class Engine: public Singleton<Engine> {
  public:
		Engine();
		~Engine() {};

	public:
		void init();

		OpNode *root();
		OpNode *node(std::string node_path);
		OpNode *node(obj_id_t id);

		float time();
		void setTime(float time);

		float frame();
		void setFrame(float frame);

		float fps();
		void setFps(float fps);

		OpDataFactory *dataFactory();
		OpTable *opTable();

	// signal handlers
	private:
		OpNode* onCreateOpNode(const std::string &op_node_type_name, const std::string &op_node_path, const std::string &node_name = "");
		bool    onConnectOpNodes(unsigned int input_index, const std::string &input_op_node_path, unsigned int output_index, const std::string &output_op_node_path);

	private:
		OpNode *_root;

		// animation related
		float _time, _frame, _fps;

		// Factories 
		OpDataFactory _opdata_factory;
		OpTable _op_table;

		bool _initialized;

};

}

#endif // ENGINE_H