#ifndef NODE_ITEM_H
#define NODE_ITEM_H

#include <QSizeF>
#include <QPainter>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsObject>
#include <QGraphicsSimpleTextItem>

#include <flags/flags.hpp>

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpDataSocket.h"

#include "NodeSocketItem.h"


namespace copper { namespace ui {

class NodeSocketItem;

class NodeItem : public QGraphicsObject {
  public:
  enum class Flags {
    SOCKETS_VERTICAL    = 0x01, /// Socket for output data
    SOCKETS_HORIZONTAL  = 0x02, /// Socket for ouput data
  };

	Q_OBJECT

	public:
		NodeItem(OpNode *op_node, NodeItem::Flags flags);
    QSizeF size() const;

	private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

  public:
    void addSocket(OpDataSocket *opdata_socket);

  private:
  	bool _locked;
    NodeItem::Flags _flags;
    OpNode *_op_node;

    QGraphicsSimpleTextItem _node_name_item;

  	QSizeF _size = QSizeF(60,20);

    std::vector<NodeSocketItem*> _socket_items;
};

}}

ALLOW_FLAGS_FOR_ENUM(copper::ui::NodeItem::Flags)

#endif // NODE_ITEM_H