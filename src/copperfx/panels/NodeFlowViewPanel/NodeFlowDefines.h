#ifndef NODE_FLOW_DEFINES_H
#define NODE_FLOW_DEFINES_H

#include <QGraphicsItem>


enum { 
	NodeType = QGraphicsItem::UserType + 1,
	NodeSocketType = QGraphicsItem::UserType + 2,
	NodeConnectionType = QGraphicsItem::UserType + 3
};

#endif // NODE_FLOW_DEFINES_H