#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/composite_key.hpp>

#include <boost/signals2.hpp>
	
#include "copper/OpData/OpDataBase.h"
#include "copper/OpData/OpDataTable.h"
#include "copper/Operator/OpDataSocket.h"
#include "copper/Operator/OpBase.h"
#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpTable.h"
#include "copper/Plugin/AbstractFactory.h"
#include "copper/Util/Singleton.h"
#include "copper/Util/IndexableObject.h"


namespace copper {

namespace bmi = boost::multi_index;

//typedef AbstractFactory<OpDataBase> OpDataFactory;

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
		OpNode *node(OpNodeGUID guid);

		float time();
		void setTime(float time);

		float frame();
		void setFrame(float frame);

		float fps();
		void setFps(float fps);

		OpDataTable *dataTypesTable();
		OpTable *opTable();

	// signal handlers
	private:
		OpNode* onCreateOpNode(const std::string &op_node_type_name, const std::string &parent_node_path, const std::string &node_name = "");
		bool    onConnectOpNodes(unsigned int input_index, const std::string &input_op_node_path, unsigned int output_index, const std::string &output_op_node_path);

	private:
		OpNode *_root;

		// animation related
		float _time, _frame, _fps;

		// maps for op nodes and data sockets
		std::map<OpDataSocketGUID, OpDataSocket *> _op_data_sockets_map;
		std::map<OpNodeGUID, OpNode *> _op_nodes_map;

		// Plugin tables/factories 
		OpTable 		_op_table;
		OpDataTable _op_data_table;

		bool _initialized;

};

}

#endif // ENGINE_H