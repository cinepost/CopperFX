#ifndef NODE_SOCKET_ITEM_H
#define NODE_SOCKET_ITEM_H

#include <QSizeF>
#include <QPainter>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsObject>

#include "copper/Operator/OpDataSocket.h"
#include "NodeItem.h"


namespace copper { namespace ui {

class NodeItem;

class NodeSocketItem : public QGraphicsObject {
	Q_OBJECT

	public:
		NodeSocketItem(NodeItem *parent, OpDataSocket *opdata_socket);

  public:
    bool isInput() const;
    bool isOutput() const;

	private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    //QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

  private:
  	QSizeF _size = QSizeF(10,10);

    OpDataSocket *_opdata_socket;
};

}}

#endif // NODE_SOCKET_ITEM_H