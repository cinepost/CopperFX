#include "copper/Operator/OP_NetworkBoxItem.h"


namespace copper {

float OP_NetworkBoxItem::getX() {
	return this->x;
}

float OP_NetworkBoxItem::getY() {
	return this->y;
}

void OP_NetworkBoxItem::setX(float x) {
	this->x = x;
}

void OP_NetworkBoxItem::setY(float y){
	this->y = y;
}

}