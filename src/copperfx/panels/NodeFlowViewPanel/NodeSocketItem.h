#ifndef NODE_SOCKET_ITEM_H
#define NODE_SOCKET_ITEM_H

#include <QVector>
#include <QSizeF>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsObject>

#include "copper/Operator/OpDataSocket.h"
#include "NodeItem.h"


class QDragEnterEvent;
class QDropEvent;

namespace copper { namespace ui {

class NodeItem;
class NodeConnectionItem;

class NodeSocketItem : public QGraphicsObject {
	Q_OBJECT

	public:
		NodeSocketItem(NodeItem *parent, OpDataSocket *opdata_socket);

  public:
    bool isInput() const;
    bool isOutput() const;
    bool isConnected(NodeSocketItem *socket_item) const;
    NodeItem *nodeItem();

    QSizeF size() const;
    QVector<NodeConnectionItem*>& connections();

  public:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

	private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    //QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

  private:
  	QSizeF _size = QSizeF(10,10);

    OpDataSocket *_opdata_socket;
    QVector<NodeConnectionItem*> _connections;

    bool _is_input = false;
    bool _hovered = false;

    NodeItem *_parent = nullptr;
    NodeConnectionItem *_temp_connection_item = nullptr;
};

}}

#endif // NODE_SOCKET_ITEM_H