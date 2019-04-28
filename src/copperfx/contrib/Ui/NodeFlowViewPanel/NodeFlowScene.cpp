#include "NodeFlowScene.h"


namespace copper { namespace ui {

NodeFlowScene::NodeFlowScene(QObject *parent): QGraphicsScene(parent) {
	
}

void NodeFlowScene::createTestNode(void) {
  addItem(new NodeItem(nullptr));
}

}}