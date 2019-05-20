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
		NodeFlowScene(QWidget *parent, const std::string &op_node_path = "/");

	public:
		void buildSceneAt(const std::string &op_node_path);

	public:
		void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

	private:
		std::string _op_node_path;
		
		NodeConnectionItem *_temp_connection_item = nullptr;
};

}}

#endif // NODE_FLOW_SCENE_H