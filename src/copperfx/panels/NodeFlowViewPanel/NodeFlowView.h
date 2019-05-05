#ifndef NODE_FLOW_VIEW_H
#define NODE_FLOW_VIEW_H

#include <unordered_map>

#include <QAction>
#include <QMouseEvent>
#include <QtCore/QPointF>
#include <QtWidgets/QGraphicsView>

#include "NodeFlowScene.h"


namespace copper { namespace ui {

class NodeFlowView : public QGraphicsView {
	Q_OBJECT

	public:
		explicit NodeFlowView(QWidget *parent, const std::string &op_network_path);
    ~NodeFlowView();
    
		QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    double zoomLevel();
    void zoom(double zoom_factor);
    void setZoomLevel(double zoom_level);

  protected:
  	void wheelEvent(QWheelEvent *event) override;
  	void mousePressEvent(QMouseEvent *event) override;
  	void mouseMoveEvent(QMouseEvent *event) override;
  	void drawBackground(QPainter* painter, const QRectF& r) override;

  private:
    void viewNetwork(const std::string &op_network_path);
  	void contextMenuEvent(QContextMenuEvent *event) override;

  //public slots:
    void onOpNetworkChanged(const std::string &op_network_path);
    void onOpNodeCreated(const std::string &op_node_path, const std::string &op_network_path);

  private:
  	double _min_zoom_level = 0.05;
  	double _max_zoom_level = 10.0;
  	double _zoom_level = 1.0;
  	QAction* _clearSelectionAction;
  	QAction* _deleteSelectionAction;

  	QPointF _clickPos;

  	std::unordered_map<std::string, NodeFlowScene*> _scenes;

};

}}


#endif // NODE_FLOW_VIEW_H