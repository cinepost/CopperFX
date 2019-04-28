#include <QRect>
#include <QColor>

#include "NodeItem.h"

namespace copper { namespace ui {

NodeItem::NodeItem(std::shared_ptr<OpBase> op): QGraphicsObject(nullptr),
  _locked(false), _op(op)
{
  
  setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
  setFlag(QGraphicsItem::ItemIsMovable, true);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

  setAcceptHoverEvents(true);
  setZValue(0);
  setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

QRectF NodeItem::boundingRect() const {
  qreal pen_width = 1;
  return QRectF(-_size.width()/2.0 - pen_width/2, -_size.height()/2.0 - pen_width/2, _size.width() + pen_width, _size.height() + pen_width);
}

void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  painter->setPen(QColor(255, 255, 255));
  painter->drawRoundedRect(-_size.width()/2.0, -_size.height()/2.0, _size.width(), _size.height(), 1.5, 1.5);
}

}}