#ifndef NODE_FLOW_SCENE_H
#define NODE_FLOW_SCENE_H

#include <QObject>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsScene>

#include "NodeItem.h"


namespace copper { namespace ui {

class NodeFlowScene : public QGraphicsScene {
	Q_OBJECT

	public:
		NodeFlowScene(QObject *parent = nullptr);

	  void createTestNode(void);
};

}}

#endif // NODE_FLOW_SCENE_H