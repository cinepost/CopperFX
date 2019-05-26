#ifndef NODE_FLOW_SCENE_H
#define NODE_FLOW_SCENE_H

#include <QObject>
#include <QWidget>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsScene>

#include "NodeItem.h"


namespace copper { namespace ui {

class NodeItem;
class NodeConnectionItem;

class NodeFlowScene : public QGraphicsScene {
	Q_OBJECT

	public:
		NodeFlowScene(QWidget *parent, const std::string &op_node_path = "/");

	public:
		void buildSceneAt(const std::string &op_node_path);
		const std::string& sceneLevelPath() const;

	public:
		void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

  public:
  	// boost slots
  	void onOpNodePosChanged(const std::string& op_node_path);
  	void onOpNetworkChanged(const std::string &op_node_path);
    void onOpNodeCreated(const std::string &op_node_path, const std::string &op_network_path);

	private:
		std::string _op_node_path;

		QVector<NodeItem*> _node_items;
		QVector<NodeConnectionItem*> _connection_items;
};

}}

#endif // NODE_FLOW_SCENE_H