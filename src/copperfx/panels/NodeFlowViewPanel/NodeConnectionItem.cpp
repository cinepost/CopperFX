#include <iostream>
#include <algorithm>    // std::min

#include <QBrush>
#include <QPen>
#include <QGraphicsScene>

#include "NodeSocketItem.h"
#include "NodeConnectionItem.h"


namespace copper { namespace ui {

NodeConnectionItem::NodeConnectionItem(QGraphicsItem *parent): QGraphicsItem(parent) {
	setAcceptHoverEvents(true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);

	setCacheMode(QGraphicsItem::DeviceCoordinateCache);
	setZValue(1);

	_hovered = false;
	_connected = false;
	_socket_from = nullptr;
	_socket_to = nullptr;
}


NodeConnectionItem::~NodeConnectionItem() {
	//if (_socket_from)
	//	_socket_from->connections().remove(_socket_from->connections().indexOf(this));
	//if (_socket_to)
	//	_socket_to->connections().remove(_socket_to->connections().indexOf(this));
}


void NodeConnectionItem::setPosFrom(const QPointF &pos) {
	if (!_socket_from) {
		_pos_from = pos;
		update();
	}
}


void NodeConnectionItem::setPosTo(const QPointF &pos) {
	if (!_socket_to) {
		_pos_to = pos;
		update();
	}
}


void NodeConnectionItem::setSocketFrom(NodeSocketItem *socket_item) {
	if(socket_item) {
		_socket_from = socket_item;
		_socket_from->connections().append(this);
		if (_socket_to)_connected = true;
		updatePosFromSockets();
	}
}


void NodeConnectionItem::setSocketTo(NodeSocketItem *socket_item) {
	if(socket_item) {
		_socket_to = socket_item;
		_socket_to->connections().append(this);
		if (_socket_from)_connected = true;
		updatePosFromSockets();
	}
}


void NodeConnectionItem::updatePosFromSockets() {
	if(_socket_from)_pos_from = _socket_from->scenePos();
	if(_socket_to)_pos_to = _socket_to->scenePos();
	update();
}


QRectF NodeConnectionItem::boundingRect() const { 
  return QRectF(std::min(_pos_from.x(), _pos_to.x()), std::min(_pos_from.y(), _pos_to.y()), std::abs(_pos_from.x() -  _pos_to.x()), std::abs(_pos_from.y() - _pos_to.y()));
}


QPainterPath NodeConnectionItem::buildPath() const {
	QPainterPath p;
	p.moveTo(_pos_from);

	qreal dx = _pos_to.x() - _pos_from.x();
	qreal dy = _pos_to.y() - _pos_from.y();

	QPointF ctr1(_pos_from.x() + dx * 0.25, _pos_from.y() + dy * 0.1);
	QPointF ctr2(_pos_from.x() + dx * 0.75, _pos_from.y() + dy * 0.9);

	p.cubicTo(ctr1, ctr2, _pos_to);
	return p;
}


QPainterPath NodeConnectionItem::shape() const {
    return buildPath();
}


void NodeConnectionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);

  QPainterPath p = buildPath();

  painter->setPen(QPen(Qt::black, 1.0));

  if (isSelected() && _connected) {
    painter->setPen(QPen(Qt::yellow, 2.0));
  } else {
  	if (_hovered && _connected) {
  		painter->setPen(QColor(255, 190, 64));
  	}
  }

  painter->setBrush(Qt::NoBrush);
  painter->drawPath(p);

  //painter->setBrush(Qt::SolidPattern);
  //painter->drawEllipse(QRectF(_pos_from.x()-2, _pos_from.y()-2, 4, 4));
  //painter->drawEllipse(QRectF(_pos_to.x()-2, _pos_to.y()-2, 4, 4));
}


NodeSocketItem* NodeConnectionItem::socketFrom() const {
	return _socket_from;
}


NodeSocketItem* NodeConnectionItem::socketTo() const {
	return _socket_to;
}


void NodeConnectionItem::hoverEnterEvent(QGraphicsSceneHoverEvent * event) {
	_hovered = true;
	QGraphicsItem::hoverEnterEvent(event);
}


void NodeConnectionItem::hoverLeaveEvent(QGraphicsSceneHoverEvent * event) {
	_hovered = false;
	QGraphicsItem::hoverEnterEvent(event);
}


}}

