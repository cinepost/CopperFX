#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "copper/Engine.h"
#include "copper/Operator/OpNode.h"

#include "NodeFlowScene.h"


namespace copper { namespace ui {

NodeFlowScene::NodeFlowScene(QWidget *parent, const std::string &op_node_path): QGraphicsScene(parent) {
	BOOST_LOG_TRIVIAL(debug) << "Constructing Node Flow Scene panel.";
	setSceneRect(-100000, -100000, 200000, 200000);

	buildSceneAt(op_node_path);
	BOOST_LOG_TRIVIAL(debug) << "Node Flow Scene panel constructed!";
}

/// build/rebuild scene
void NodeFlowScene::buildSceneAt(const std::string &op_node_path) {
	BOOST_LOG_TRIVIAL(debug) << "Building Node Flow Scene at: " << op_node_path;
	_op_node_path = op_node_path;
	this->clear();
	OpNode *op_node_level = Engine::getInstance().root()->node(op_node_path);
	for(auto&& op_node: op_node_level->children()) {
		BOOST_LOG_TRIVIAL(debug) << "Adding node: " << op_node->path();
		addItem(new NodeItem(op_node, NodeItem::Flags::SOCKETS_HORIZONTAL));
	}
	BOOST_LOG_TRIVIAL(debug) << "Node Flow Scene built at: " << op_node_path;
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


}}