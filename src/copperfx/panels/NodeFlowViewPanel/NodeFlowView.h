#ifndef NODE_FLOW_VIEW_H
#define NODE_FLOW_VIEW_H

#include <QAction>
#include <QMouseEvent>
#include <QtCore/QPointF>
#include <QtWidgets/QGraphicsView>

#include "NodeFlowScene.h"


namespace copper { namespace ui {

class NodeFlowView : public QGraphicsView {
	Q_OBJECT

	public:
		explicit NodeFlowView(QWidget *parent = nullptr);
		explicit NodeFlowView(NodeFlowScene *scene, QWidget *parent = nullptr);
    ~NodeFlowView();
    
		QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    double zoomLevel();
    void zoom(double zoom_factor);
    void setZoomLevel(double zoom_level);
    void setScene(NodeFlowScene *scene);

    NodeFlowScene * scene();

  protected:
  	void wheelEvent(QWheelEvent *event) override;
  	void mousePressEvent(QMouseEvent *event) override;
  	void mouseMoveEvent(QMouseEvent *event) override;
  	void drawBackground(QPainter* painter, const QRectF& r) override;

  private:
  	void contextMenuEvent(QContextMenuEvent *event) override;

  private:
  	double _min_zoom_level = 0.05;
  	double _max_zoom_level = 10.0;
  	double _zoom_level = 1.0;
  	QAction* _clearSelectionAction;
  	QAction* _deleteSelectionAction;

  	QPointF _clickPos;

  	NodeFlowScene* _scene;

};

}}


#endif // NODE_FLOW_VIEW_H