#include <QRect>
#include <QColor>
#include <QGraphicsScene>

#include "NodeItem.h"
#include "NodeSocketItem.h"

namespace copper { namespace ui {

NodeItem::NodeItem(OpNode *op_node): QGraphicsObject(nullptr),
  _locked(false), _op_node(op_node)
{
  
  setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
  setFlag(QGraphicsItem::ItemIsMovable, true);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

  setAcceptHoverEvents(true);
  setZValue(0);
  setCacheMode(QGraphicsItem::DeviceCoordinateCache);

  setPos(_op_node->x(), _op_node->y());

  // create input sockets
  for(auto input : _op_node->inputs()) {
    addSocket(&input);
  }
}

QRectF NodeItem::boundingRect() const {
  qreal pen_width = 1;
  return QRectF(-_size.width()/2.0 - pen_width/2, -_size.height()/2.0 - pen_width/2, _size.width() + pen_width, _size.height() + pen_width);
}

void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  QRectF rect = QRectF(-_size.width()/2.0, -_size.height()/2.0, _size.width(), _size.height());

  painter->setPen(QColor(255, 255, 255));
  painter->drawRoundedRect(rect, 1.5, 1.5);

  painter->setPen(QColor(255, 255, 255));
  painter->drawText(rect, Qt::AlignCenter, _op_node->name().c_str());
}

void NodeItem::addSocket(OpDataSocket *opdata_socket) {
  NodeSocketItem *socket_item = new NodeSocketItem(this, opdata_socket);
  _input_socket_items.push_back(socket_item);
}

QVariant NodeItem::itemChange(GraphicsItemChange change, const QVariant &value) {
  if (change == ItemPositionChange && scene()) {
    // value is the new position.
    QPointF newPos = value.toPointF();
    QRectF rect = scene()->sceneRect();
    if (!rect.contains(newPos)) {
      // Keep the item inside the scene rect.
      newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
      newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
    }
    _op_node->setX(newPos.x());
    _op_node->setY(newPos.y());

    return newPos;
  }
  return QGraphicsItem::itemChange(change, value);
}

}}