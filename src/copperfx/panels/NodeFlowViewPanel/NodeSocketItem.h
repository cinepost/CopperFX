#ifndef NODE_SOCKET_ITEM_H
#define NODE_SOCKET_ITEM_H

#include <QVector>
#include <QSizeF>
#include <QPainter>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsObject>

#include "copper/Operator/OpDataSocket.h"
#include "NodeItem.h"


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
    QSizeF size() const;
    QVector<NodeConnectionItem*>& connections();

    bool isConnected(NodeSocketItem *socket);

  public:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;

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
};

}}

#endif // NODE_SOCKET_ITEM_H