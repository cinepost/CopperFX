#include "NodeFlowScene.h"


namespace copper { namespace ui {

NodeFlowScene::NodeFlowScene(QObject *parent): QGraphicsScene(parent) {
	setSceneRect(-100000, -100000, 200000, 200000);
}

void NodeFlowScene::createTestNode(void) {
  addItem(new NodeItem(nullptr));
}

}}