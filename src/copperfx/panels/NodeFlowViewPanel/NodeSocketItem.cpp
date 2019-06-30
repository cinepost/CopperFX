#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <QDrag>
#include <QRect>
#include <QColor>
#include <QWidget>
#include <QMimeData>
#include <QGraphicsScene>

#include "NodeFlowDefines.h"
#include "NodeSocketItem.h"
#include "NodeConnectionItem.h"


namespace copper { namespace ui {

NodeSocketItem::NodeSocketItem(NodeItem *parent, const OpDataSocket *opdata_socket): QGraphicsItem(parent) {
  BOOST_LOG_TRIVIAL(debug) << "Constructing Node Socket Item.";

  _opdata_socket = opdata_socket;

  setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, false);
  setFlag(QGraphicsItem::ItemIsMovable, false);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, false);
  setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

  setAcceptDrops(true);
  setAcceptHoverEvents(true);
  setZValue(1);
  setCacheMode(QGraphicsItem::DeviceCoordinateCache);

  //setToolTip(_opdata_socket->dataTypeName());
  BOOST_LOG_TRIVIAL(debug) << "Node Socket Item data type UUID: " << _opdata_socket->dataTypeUUID();

  _parent = parent;

  if (_opdata_socket->isInput()) {
    _is_input = true;
  }
  BOOST_LOG_TRIVIAL(debug) << "Node Socket Item constructed.";
}

void NodeSocketItem::setHoverFlag(NodeSocketItem::HoverFlag flag) {
  _hover_flag = flag;
  update();
}

NodeItem *NodeSocketItem::nodeItem() {
  return _parent;
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

void NodeSocketItem::addConnection(NodeConnectionItem* connection_item) {
  _connections.append(connection_item);
}

bool NodeSocketItem::isConnected(NodeSocketItem *socket) const {
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
  return QRectF(-_size.width()/2.0 - pen_width/2.0, -_size.height()/2.0 - pen_width/2.0, _size.width() + pen_width, _size.height() + pen_width);
}

QPainterPath NodeSocketItem::shape() const {
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void NodeSocketItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
  //setToolTip(_opdata_socket->dataTypeName().c_str());
  setToolTip("Socket GUID: " + QString::number(opDataSocket()->GUID()));
  _hovered = true;
  //QGraphicsItem::hoverEnterEvent(event);
}

void NodeSocketItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
  QGraphicsItem::hoverMoveEvent(event);
}

void NodeSocketItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
  setToolTip("");
  _hovered = false;
  //QGraphicsItem::hoverLeaveEvent(event);
}

void NodeSocketItem::mousePressEvent(QGraphicsSceneMouseEvent * event) {
  //QGraphicsItem::mousePressEvent(event);
}

void NodeSocketItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event) {
  //QGraphicsItem::mouseMoveEvent(event);
}

void NodeSocketItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event) {
  //QGraphicsItem::mouseReleaseEvent(event);
}

int NodeSocketItem::type() const {
  // Enable the use of qgraphicsitem_cast with this item.
  return NodeSocketType;
}


const OpDataSocket *NodeSocketItem::opDataSocket() const {
  return _opdata_socket;
}


bool NodeSocketItem::canConnect(NodeSocketItem *_temp_socket_from, NodeSocketItem *_temp_socket_to) {
  if (!_temp_socket_from || !_temp_socket_to) return false;
  return OpDataSocket::canConnect(_temp_socket_from->opDataSocket(), _temp_socket_to->opDataSocket());
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
  if ( _hover_flag == NodeSocketItem::HoverFlag::CanConnect ) {
    painter->setBrush(QColor(64, 255, 0));
  } else if ( _hover_flag == NodeSocketItem::HoverFlag::CanNotConnect ) {
    painter->setBrush(QColor(255, 64, 0));
  }

  painter->drawEllipse(rect);
}

void NodeSocketItem::updateConnections() const {
  for ( auto conn: _connections)conn->updatePosFromSockets();
}

QVariant NodeSocketItem::itemChange(GraphicsItemChange change, const QVariant &value) {
  if (change == QGraphicsItem::ItemScenePositionHasChanged && scene()) {
    // socket scene position changed so update connection items
    updateConnections();
  }
  return QGraphicsItem::itemChange(change, value);
}


}}