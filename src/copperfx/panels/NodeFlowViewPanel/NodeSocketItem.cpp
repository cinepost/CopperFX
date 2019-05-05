#include <QRect>
#include <QColor>
#include <QGraphicsScene>

#include "NodeSocketItem.h"

namespace copper { namespace ui {

NodeSocketItem::NodeSocketItem(NodeItem *parent, OpDataSocket *opdata_socket): QGraphicsObject(parent) {
  _opdata_socket = opdata_socket;

  setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
  setFlag(QGraphicsItem::ItemIsMovable, false);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, false);
  //setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

  setAcceptHoverEvents(true);
  setZValue(0);
  setCacheMode(QGraphicsItem::DeviceCoordinateCache);

  //setPos(_op_node->x(), _op_node->y());
}

bool NodeSocketItem::isInput() const {
  return _opdata_socket->isInput();
}

bool NodeSocketItem::isOutput() const {
  return _opdata_socket->isOutput();
}

QRectF NodeSocketItem::boundingRect() const {
  qreal pen_width = 1;
  return QRectF(-_size.width()/2.0 - pen_width/2, -_size.height()/2.0 - pen_width/2, _size.width() + pen_width, _size.height() + pen_width);
}

void NodeSocketItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  QRectF rect = QRectF(-_size.width()/2.0, -_size.height()/2.0, _size.width(), _size.height());

  painter->setPen(QColor(0, 255, 0));
  painter->drawEllipse(rect);
}

}}