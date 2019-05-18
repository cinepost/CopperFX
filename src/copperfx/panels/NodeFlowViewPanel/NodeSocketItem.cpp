#include <iostream>

#include <QRect>
#include <QColor>
#include <QWidget>
#include <QGraphicsScene>

#include "NodeSocketItem.h"
#include "NodeConnectionItem.h"


namespace copper { namespace ui {

NodeSocketItem::NodeSocketItem(NodeItem *parent, OpDataSocket *opdata_socket): QGraphicsObject(parent), _opdata_socket(opdata_socket) {
  setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
  setFlag(QGraphicsItem::ItemIsMovable, false);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, false);
  //setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

  setAcceptHoverEvents(true);
  setZValue(0);
  setCacheMode(QGraphicsItem::DeviceCoordinateCache);

  if (_opdata_socket->isInput()) {
    _is_input = true;
  }
}

bool NodeSocketItem::isInput() const {
  return _is_input;//_opdata_socket->isInput();
}

bool NodeSocketItem::isOutput() const {
  return !_is_input;//_opdata_socket->isOutput();
}

QVector<NodeConnectionItem*>& NodeSocketItem::connections() {
  return _connections;
}

bool NodeSocketItem::isConnected(NodeSocketItem *socket) {
  foreach(NodeConnectionItem *conn, _connections)
    if (conn->socketFrom() == socket || conn->socketTo() == socket)
      return true;

  return false;
}

QSizeF NodeSocketItem::size() const {
  return _size;
}

QRectF NodeSocketItem::boundingRect() const {
  qreal pen_width = 1;
  return QRectF(-_size.width()/2.0 - pen_width/2, -_size.height()/2.0 - pen_width/2, _size.width() + pen_width, _size.height() + pen_width);
}

void NodeSocketItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
  _hovered = true;
  QGraphicsObject::hoverEnterEvent(event);
}

void NodeSocketItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
  _hovered = false;
  QGraphicsObject::hoverLeaveEvent(event);
}

void NodeSocketItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);

  QRectF rect = QRectF(-_size.width()/2.0, -_size.height()/2.0, _size.width(), _size.height());

  if ( _hovered ) {
    painter->setPen(QColor(255, 190, 64));
  } else {
    painter->setPen(QColor(0, 0, 0));
  }

  painter->setBrush(Qt::gray);
  painter->drawEllipse(rect);
}

}}