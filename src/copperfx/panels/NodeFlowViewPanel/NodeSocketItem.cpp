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

NodeSocketItem::NodeSocketItem(NodeItem *parent, const OpDataSocket *opdata_socket): QGraphicsItem(parent), _opdata_socket(opdata_socket) {
  BOOST_LOG_TRIVIAL(debug) << "Constructing Node Socket Item.";
  setFlag(QGraphicsItem::ItemDoesntPropagateOpacityToChildren, true);
  setFlag(QGraphicsItem::ItemIsMovable, false);
  setFlag(QGraphicsItem::ItemIsFocusable, true);
  setFlag(QGraphicsItem::ItemIsSelectable, false);
  setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);

  setAcceptDrops(true);
  setAcceptHoverEvents(true);
  setZValue(1);
  setCacheMode(QGraphicsItem::DeviceCoordinateCache);

  //setToolTip(_opdata_socket->dataTypeName());
  BOOST_LOG_TRIVIAL(debug) << "Node Socket Item data type name: " << _opdata_socket->dataTypeName();

  _parent = parent;

  if (_opdata_socket->isInput()) {
    _is_input = true;
  }
  BOOST_LOG_TRIVIAL(debug) << "Node Socket Item constructed.";
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
  _hovered = true;
  QGraphicsItem::hoverEnterEvent(event);
}

void NodeSocketItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
  QGraphicsItem::hoverMoveEvent(event);
}


void NodeSocketItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
  _hovered = false;
  QGraphicsItem::hoverLeaveEvent(event);
}


void NodeSocketItem::mousePressEvent(QGraphicsSceneMouseEvent * event) {
  //if(event->button() & Qt::LeftButton) {
  //  _temp_connection_item = new NodeConnectionItem(this);
  //  _temp_connection_item->setPosFrom(event->pos());
  //  _temp_connection_item->setPosTo(event->pos());
  //} else {
  //  QGraphicsObject::mousePressEvent(event);
  //}
  //QGraphicsItem::mousePressEvent(event);
}


void NodeSocketItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event) {
  //if(_temp_connection_item) {
    //move the end point of a temporary connection item
  //  _temp_connection_item->setPosTo(event->pos());
  //}
  //QGraphicsItem::mouseMoveEvent(event);
}


void NodeSocketItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event) {
  //delete _temp_connection_item;
  QGraphicsItem::mouseReleaseEvent(event);
}


int NodeSocketItem::type() const {
  // Enable the use of qgraphicsitem_cast with this item.
  return NodeSocketType;
}


const OpDataSocket *NodeSocketItem::opDataSocket() const {
  return _opdata_socket;
}


bool NodeSocketItem::canConnect(NodeSocketItem *_temp_socket_from, NodeSocketItem *_temp_socket_to) {
  if (!_temp_socket_from || !_temp_socket_to || (_temp_socket_from == _temp_socket_to)) return false;
  if (_temp_socket_from->_is_input == _temp_socket_to->_is_input) return false;
  if (_temp_socket_from->_parent == _temp_socket_to->_parent) return false;
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