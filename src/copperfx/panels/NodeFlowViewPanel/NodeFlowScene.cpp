#include <iostream>

#include "copper/Engine.h"
#include "copper/Operator/OpNode.h"

#include "NodeFlowScene.h"


namespace copper { namespace ui {

NodeFlowScene::NodeFlowScene(QWidget *parent, const std::string &op_network_path): QGraphicsScene(parent) {
	_op_network_path = op_network_path;

	setSceneRect(-100000, -100000, 200000, 200000);

	buildScene();
}

/// build/rebuild scene
void NodeFlowScene::buildScene() {
	this->clear();
	OpNode *op_network = Engine::getInstance().root()->node(_op_network_path);
	std::cout << "Creating NodeFlowScene at: ";// << op_network->path();
	for(auto&& op_node: op_network->children()) {
		addItem(new NodeItem(op_node, NodeItem::Flags::SOCKETS_HORIZONTAL));
	}
}


}}