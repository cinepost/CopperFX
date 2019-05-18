#ifndef NODE_CONNECTION_ITEM_H
#define NODE_CONNECTION_ITEM_H

#include <QSizeF>
#include <QPainter>
#include <QtCore/QUuid>
#include <QGraphicsPathItem>

#include "NodeSocketItem.h"


namespace copper { namespace ui {

class NodeSocketItem;

class NodeConnectionItem : public QGraphicsPathItem {
  public:
	//Q_OBJECT

	public:
		NodeConnectionItem(QGraphicsItem *parent = nullptr);
    ~NodeConnectionItem();

    void setPosFrom(const QPointF &pos);
    void setPosTo(const QPointF &pos);
    void setSocketFrom(NodeSocketItem *socket_item);
    void setSocketTo(NodeSocketItem *socket_item);
    void updatePosFromPorts();
    void updatePath();
    NodeSocketItem* socketFrom() const;
    NodeSocketItem* socketTo() const;

  private:
  	QPointF _pos_from;
    QPointF _pos_to;
    NodeSocketItem *_socket_from;
    NodeSocketItem *_socket_to;
};

}}

#endif // NODE_CONNECTION_ITEM_H