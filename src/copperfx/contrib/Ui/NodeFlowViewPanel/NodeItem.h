#ifndef NODE_ITEM_H
#define NODE_ITEM_H

#include <QSizeF>
#include <QPainter>
#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsObject>

namespace copper { namespace ui {

class OpBase;

class NodeItem : public QGraphicsObject {
	Q_OBJECT

	public:
		NodeItem(std::shared_ptr<OpBase> = nullptr);

	public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

  private:
  	bool _locked;
  	QSizeF _size = QSizeF(60,20);

  	std::shared_ptr<OpBase> _op;
};

}}

#endif // NODE_ITEM_H