#include <iostream>

#include <boost/signals2.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "copper/Engine.h"
#include "copper/Operator/OpNode.h"

#include "NodeItem.h"
#include "NodeConnectionItem.h"
#include "NodeFlowScene.h"


namespace copper { namespace ui {

NodeFlowScene::NodeFlowScene(QWidget *parent, const std::string &op_node_path): QGraphicsScene(parent) {
	BOOST_LOG_TRIVIAL(debug) << "Constructing Node Flow Scene panel.";
	setSceneRect(-100000, -100000, 200000, 200000);

	buildSceneAt(op_node_path);

	// connect engine signals
  EngineSignals::getInstance().signalOpNodePosChanged.connect(boost::bind(&NodeFlowScene::onOpNodePosChanged, this, _1));
  EngineSignals::getInstance().signalOpNetworkChanged.connect(boost::bind(&NodeFlowScene::onOpNetworkChanged, this, _1));

	BOOST_LOG_TRIVIAL(debug) << "Node Flow Scene panel constructed!";
}

void NodeFlowScene::onOpNetworkChanged(const std::string &op_node_path) {
	std::cout << "NodeFlowScene onOpNetworkChanged called\n";
  if (_op_node_path == op_node_path) {
    buildSceneAt(op_node_path);
  }
}

/// build/rebuild scene
void NodeFlowScene::buildSceneAt(const std::string &op_node_path) {
	BOOST_LOG_TRIVIAL(debug) << "Building Node Flow Scene at: " << op_node_path;
	_op_node_path = op_node_path;
	this->clear();
	OpNode *op_node_level = Engine::getInstance().root()->node(op_node_path);
	
	// create node items
	for(auto&& op_node: op_node_level->children()) {
		NodeItem *node_item = new NodeItem(this, op_node, NodeItem::Flags::SOCKETS_HORIZONTAL);
		_node_items.append(node_item);

		for(auto input_socket_item : node_item->inputSocketItems()) {
			_input_socket_items_map.insert(socket_item->opDataSocket()->GUID(), input_socket_item);
		}

		for(auto output_socket_item : node_item->outputSocketItems()) {
			_output_socket_items_map.insert(socket_item->opDataSocket()->GUID(), output_socket_item);
		}
	}

	// create connection items 
	for(auto socket_input_item: _input_socket_items_map.values()) {
		for(OpDataSocketGUID socket_item_guid: socket_input_item->opDataSocket()->inputGUIDs()) {
			NodeConnectionItem *connection_item = new NodeConnectionItem(this, socket_input_item, _output_socket_items_map[socket_item_guid]);
		}
	}


	BOOST_LOG_TRIVIAL(debug) << "Node Flow Scene built at: " << op_node_path;
}


const QVector<NodeItem*>& NodeFlowScene::nodeItems() const {
	return _node_items;
}


const std::string& NodeFlowScene::sceneLevelPath() const {
	return _op_node_path;
}


void NodeFlowScene::mousePressEvent(QGraphicsSceneMouseEvent * event) {
	QGraphicsScene::mousePressEvent(event);
}


void NodeFlowScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event) {
	QGraphicsScene::mouseMoveEvent(event);
}


void NodeFlowScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
	QGraphicsScene::mouseReleaseEvent(event);
}


void NodeFlowScene::onOpNodePosChanged(const std::string& op_node_path) {
	OpNode *op_node = Engine::getInstance().root()->node(op_node_path);
	if (op_node) {
		// check if we are at right level
		if (op_node->parent()->path() == _op_node_path) {
			for ( auto node_item: _node_items) {
				if(node_item->opNode() == op_node) {
					//node_item->setPos(op_node->x(), op_node->y());
				}
			}
		}
	}
}


}}