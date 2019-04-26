#include "copper/Operator/NetworkBoxItem.h"


namespace copper {

float NetworkBoxItem::getX() {
	return _x;
}

float NetworkBoxItem::getY() {
	return _y;
}

void NetworkBoxItem::setX(float x) {
	_x = x;
}

void NetworkBoxItem::setY(float y) {
	_y = y;
}

}