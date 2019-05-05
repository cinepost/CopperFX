#ifndef NODE_FLOW_SCENE_H
#define NODE_FLOW_SCENE_H

#include <QObject>
#include <QWidget>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsScene>

#include "NodeItem.h"


namespace copper { namespace ui {

class NodeFlowScene : public QGraphicsScene {
	Q_OBJECT

	public:
		NodeFlowScene(QWidget *parent, const std::string &op_network_path);

	public:
		void buildScene();

	private:
		std::string _op_network_path;
};

}}

#endif // NODE_FLOW_SCENE_H