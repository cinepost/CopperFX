#include <iostream>

#include "copper/Engine.h"
#include "copper/Operator/OpNode.h"

#include "NodeFlowScene.h"


namespace copper { namespace ui {

NodeFlowScene::NodeFlowScene(QWidget *parent, const std::string &op_node_path): QGraphicsScene(parent) {
	setSceneRect(-100000, -100000, 200000, 200000);

	buildSceneAt(op_node_path);
}

/// build/rebuild scene
void NodeFlowScene::buildSceneAt(const std::string &op_node_path) {
	_op_node_path = op_node_path;
	this->clear();
	OpNode *op_network = Engine::getInstance().root()->node(op_node_path);
	std::cout << "Creating NodeFlowScene at: " << op_node_path;
	for(auto&& op_node: op_network->children()) {
		addItem(new NodeItem(op_node, NodeItem::Flags::SOCKETS_HORIZONTAL));
	}
}


}}