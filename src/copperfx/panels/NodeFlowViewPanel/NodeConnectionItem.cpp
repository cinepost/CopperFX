#include <QBrush>
#include <QPen>
#include <QGraphicsScene>

#include "NodeSocketItem.h"
#include "NodeConnectionItem.h"


namespace copper { namespace ui {

NodeConnectionItem::NodeConnectionItem(QGraphicsItem *parent): QGraphicsPathItem(parent) {
	setPen(QPen(Qt::black, 2));
	setBrush(Qt::NoBrush);
	setZValue(-1);
	_socket_from = nullptr;
	_socket_to = nullptr;
}


NodeConnectionItem::~NodeConnectionItem() {
	if (_socket_from)
		_socket_from->connections().remove(_socket_from->connections().indexOf(this));
	if (_socket_to)
		_socket_to->connections().remove(_socket_to->connections().indexOf(this));
}


void NodeConnectionItem::setPosFrom(const QPointF &pos) {
	_pos_from = pos;
}


void NodeConnectionItem::setPosTo(const QPointF &pos) {
	_pos_to = pos;
}


void NodeConnectionItem::setSocketFrom(NodeSocketItem *socket_item) {
	_socket_from = socket_item;
	_socket_from->connections().append(this);
}


void NodeConnectionItem::setSocketTo(NodeSocketItem *socket_item) {
	_socket_to = socket_item;
	_socket_to->connections().append(this);
}


void NodeConnectionItem::updatePosFromPorts() {
	_pos_from = _socket_from->scenePos();
	_pos_to = _socket_to->scenePos();
}


void NodeConnectionItem::updatePath() {
	QPainterPath p;

	p.moveTo(_pos_from);

	qreal dx = _pos_to.x() - _pos_from.x();
	qreal dy = _pos_to.y() - _pos_from.y();

	QPointF ctr1(_pos_from.x() + dx * 0.25, _pos_from.y() + dy * 0.1);
	QPointF ctr2(_pos_from.x() + dx * 0.75, _pos_from.y() + dy * 0.9);

	p.cubicTo(ctr1, ctr2, _pos_to);

	setPath(p);
}


NodeSocketItem* NodeConnectionItem::socketFrom() const {
	return _socket_from;
}


NodeSocketItem* NodeConnectionItem::socketTo() const {
	return _socket_to;
}

}}

