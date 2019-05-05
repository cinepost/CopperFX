#ifndef NODE_ITEM_H
#define NODE_ITEM_H

#include <QSizeF>
#include <QPainter>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsObject>

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpDataSocket.h"

#include "NodeSocketItem.h"


namespace copper { namespace ui {

class NodeSocketItem;

class NodeItem : public QGraphicsObject {
  public:
  enum Flags {
    SOCKETS_VERTICAL  = 0x01, /// Socket for output data
    SOCKETS_HORIZONTAL  = 0x02, /// Socket for ouput data
  };

	Q_OBJECT

	public:
		NodeItem(OpNode *op_node);

	private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void addSocket(OpDataSocket *opdata_socket);

  private:
  	bool _locked;
  	QSizeF _size = QSizeF(60,20);

  	OpNode *_op_node;

    std::vector<NodeSocketItem*> _input_socket_items;
    std::vector<NodeSocketItem*> _output_socket_items;
};

}}

#endif // NODE_ITEM_H