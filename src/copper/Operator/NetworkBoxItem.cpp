#include "copper/Operator/NetworkBoxItem.h"


namespace copper {

NetworkBoxItem::NetworkBoxItem(){
	_x = 0.0;
	_y = 0.0;
}

NetworkBoxItem::NetworkBoxItem(const NetworkBoxItem &item){
	_x = item._x + 10.0;
	_y = item._y + 10.0;
}

float NetworkBoxItem::x() {
	return _x;
}

float NetworkBoxItem::y() {
	return _y;
}

void NetworkBoxItem::setX(float x) {
	_x = x;
}

void NetworkBoxItem::setY(float y) {
	_y = y;
}

void NetworkBoxItem::setPos(float x, float y) {
	_x = x;
	_y = y;
}

}