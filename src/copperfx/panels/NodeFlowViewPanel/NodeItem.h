#ifndef NODE_ITEM_H
#define NODE_ITEM_H

#include <QSizeF>
#include <QPainter>
#include <QVector>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsObject>
#include <QGraphicsSimpleTextItem>

#include <flags/flags.hpp>

#include "copper/Operator/OpNode.h"
#include "copper/Operator/OpDataSocket.h"

#include "NodeSocketItem.h"


namespace copper { namespace ui {

class NodeFlowScene;
class NodeSocketItem;

class NodeItem : public QGraphicsItem {
  public:
  enum class Flags {
    SOCKETS_VERTICAL    = 0x01, /// Socket for output data
    SOCKETS_HORIZONTAL  = 0x02, /// Socket for ouput data
  };

	//Q_OBJECT

	public:
		NodeItem(NodeFlowScene *scene, OpNode *op_node, NodeItem::Flags flags);
    ~NodeItem();

    QSizeF size() const;
    const OpNode *opNode() const;
    const QVector<NodeSocketItem*>& inputSocketItems() const;
    const QVector<NodeSocketItem*>& outputSocketItems() const;

	private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

  private:
    void addSocket(const OpDataSocket *opdata_socket);

  private:
    NodeFlowScene *_scene;
  	bool _locked;
    NodeItem::Flags _flags;
    OpNode *_op_node;

    QGraphicsSimpleTextItem _node_name_item;

  	QSizeF _size = QSizeF(60,20);

    QVector<NodeSocketItem*> _input_socket_items;
    QVector<NodeSocketItem*> _output_socket_items;
};

}}

ALLOW_FLAGS_FOR_ENUM(copper::ui::NodeItem::Flags)

#endif // NODE_ITEM_H