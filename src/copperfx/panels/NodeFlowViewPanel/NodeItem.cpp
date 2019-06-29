#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <QRect>
#include <QColor>
#include <QGraphicsScene>

#include "NodeItem.h"
#include "NodeSocketItem.h"
#include "NodeFlowScene.h"

namespace copper { namespace ui {

NodeItem::NodeItem(NodeFlowScene *scene, OpNode *op_node, NodeItem::Flags flags): QGraphicsItem(nullptr) {
  BOOST_LOG_TRIVIAL(debug) << "Constructing Node Item.";

  _scene = scene;
  _scene->addItem(this);
  _locked = false;
  _flags = flags;
  _op_node = op_node;

  setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
  setFlag(QGraphicsItem::ItemIsMovable, true);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
  setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
  setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

  setAcceptHoverEvents(true);
  setZValue(-1);
  setCacheMode(QGraphicsItem::DeviceCoordinateCache);

  setPos(_op_node->x(), _op_node->y());

  // create input sockets
  for(auto input : _op_node->inputs()) {
    addSocket(input);
  }

  // create output sockets
  for(auto output : _op_node->outputs()) {
    addSocket(output);
  }

  _node_name_item.setParentItem(this);
  _node_name_item.setPos(size().width() / 2.0 + 1, 0);
  _node_name_item.setBrush(QColor(192, 192, 192));
  _node_name_item.setText(_op_node->name().c_str());
  BOOST_LOG_TRIVIAL(debug) << "Node Item constructed!";
}


NodeItem::~NodeItem() {
  _scene->removeItem(this);
}


QSizeF NodeItem::size() const {
  return _size;
}

const OpNode *NodeItem::opNode() const {
  return _op_node;
}


QRectF NodeItem::boundingRect() const {
  qreal pen_width = 1;
  return QRectF(-_size.width()/2.0 - pen_width/2, -_size.height()/2.0 - pen_width/2, _size.width() + pen_width, _size.height() + pen_width);
}


void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);

  QRectF rect = QRectF(-_size.width()/2.0, -_size.height()/2.0, _size.width(), _size.height());

  if (isSelected()) {
    painter->setPen(QColor(255, 190, 64));
  } else {
    painter->setPen(QColor(0, 0, 0));
  }

  painter->setBrush(Qt::gray);
  painter->drawRoundedRect(rect, 1.0, 1.0);
}


void NodeItem::addSocket(const OpDataSocket *opdata_socket) {
  NodeSocketItem *node_socket_item = new NodeSocketItem(this, opdata_socket);
  if(node_socket_item->isInput()) {
    _input_socket_items.append(node_socket_item);
  } else {
    _output_socket_items.append(node_socket_item);
  }

  // update sockets positions
  for(auto socket_item : _input_socket_items) {
      socket_item->setPos(0, -10);
  }
  
  for(auto socket_item : _output_socket_items) {
      socket_item->setPos(0, 10);
  }
}


const QVector<NodeSocketItem*>&  NodeItem::inputSocketItems() const {
  return _input_socket_items;
}


const QVector<NodeSocketItem*>&  NodeItem::outputSocketItems() const {
  return _output_socket_items;
}


void NodeItem::mousePressEvent(QGraphicsSceneMouseEvent * event) {
  if(_locked) return;

  // deselect all other items after this one is selected
  if (!isSelected() && !(event->modifiers() & Qt::ControlModifier)) {
    scene()->clearSelection();
  }
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