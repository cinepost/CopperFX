#include <iostream>
#include <boost/algorithm/clamp.hpp>
#include <cmath>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <QtGui/QPen>
#include <QtGui/QBrush>

#include <QtCore/QRectF>
#include <QtCore/QPointF>

#include <QTimer>
#include <QMenu>
#include <QColor>
#include <QAction>
#include <QActionGroup>
#include <QOpenGLWidget>
#include <QGraphicsItem>

#include "copper/Engine.h"

#include "NodeFlowDefines.h"
#include "NodeFlowView.h"


namespace copper { namespace ui {

NodeFlowView::NodeFlowView(QWidget *parent, const std::string &op_network_path): QGraphicsView(parent) {
  BOOST_LOG_TRIVIAL(debug) << "Constructing Node Flow View panel";

  _node_flow_scene = nullptr;

  _temp_socket_from = nullptr;
  _temp_socket_to = nullptr;
  _temp_connection_item = nullptr;
  _node_flow_scene = nullptr;

  setDragMode(QGraphicsView::NoDrag);
  setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setMouseTracking(true);
  setInteractive(true);

  // Force OpenGL rendering mode
  //QGLFormat format = QGLFormat::defaultFormat();
  //format.setSampleBuffers(true);
  //format.setSamples(16);
  //setViewport( QOpenGLWidget(format) );
  //setViewportUpdateMode( QGraphicsView::FullViewportUpdate );
  //setDragMode( QGraphicsView::RubberBandDrag );

  setViewport(new QOpenGLWidget());

  _temp_connection_item = Q_NULLPTR;

  // view op network
  viewNetwork(op_network_path);

  BOOST_LOG_TRIVIAL(debug) << "Node Flow View panel constructed!";
}

NodeFlowView::~NodeFlowView() {

}

void NodeFlowView::viewNetwork(const std::string &op_node_path) {
  delete _node_flow_scene;
  _node_flow_scene = new NodeFlowScene(this, op_node_path);
  QGraphicsView::setScene(_node_flow_scene);
}

QSize NodeFlowView::minimumSizeHint() const {
    return QSize(50, 50);
}

QSize NodeFlowView::sizeHint() const {
    return QSize(640, 360);
}

void NodeFlowView::drawBackground(QPainter* painter, const QRectF& r) {
  QGraphicsView::drawBackground(painter, r);
  painter->fillRect(r, QColor(42, 42, 42));

  if (_zoom_level > 0.1 ) {
    auto drawGrid =
      [&](double gridStep)
      {
        QRect windowRect = rect();
        QPointF tl = mapToScene(windowRect.topLeft());
        QPointF br = mapToScene(windowRect.bottomRight());

        double left   = std::floor(tl.x() / gridStep - 0.5);
        double right  = std::floor(br.x() / gridStep + 1.0);
        double bottom = std::floor(tl.y() / gridStep - 0.5);
        double top    = std::floor (br.y() / gridStep + 1.0);

        // vertical lines
        for (int xi = int(left); xi <= int(right); ++xi) {
          QLineF line(xi * gridStep, bottom * gridStep,
                      xi * gridStep, top * gridStep );

          painter->drawLine(line);
        }

        // horizontal lines
        for (int yi = int(bottom); yi <= int(top); ++yi) {
          QLineF line(left * gridStep, yi * gridStep, right * gridStep, yi * gridStep );
          painter->drawLine(line);
        }
      };

    //auto const &flowViewStyle = StyleCollection::flowViewStyle();

    QBrush bBrush = backgroundBrush();

    //QPen pfine(flowViewStyle.FineGridColor, 1.0);
    QPen pfine(QColor(64, 64, 64), 1.0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
    pfine.setCosmetic(true);

    painter->setPen(pfine);
    drawGrid(30);

    //QPen p(flowViewStyle.CoarseGridColor, 1.0);
    QPen pmain(QColor(64, 64, 64), 1.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    pmain.setCosmetic(true);

    painter->setPen(pmain);
    drawGrid(300);
  }
}

void NodeFlowView::contextMenuEvent(QContextMenuEvent *event) {
    QMenu main_menu(this);

    QMenu *op_menu = main_menu.addMenu("Create operator");
    QActionGroup *op_group = new QActionGroup(op_menu);

    QAction *op_action;

    // build opnodes creation menu actions
    for (auto & op_node_type_name : Engine::getInstance().opTable()->registeredTypeNames()) {
      op_action = op_menu->addAction(op_node_type_name.c_str());
      op_action->setActionGroup(op_group);
      connect(op_action, &QAction::triggered, this, [=]() { EngineSignals::getInstance().signalCreateOpNode(op_node_type_name, "/", ""); });
    }

    main_menu.exec(event->globalPos());
}

void NodeFlowView::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && event->modifiers().testFlag(Qt::ControlModifier)) {
    _clickPos = mapToScene(event->pos());
    setDragMode(QGraphicsView::ScrollHandDrag);
  } else {
    // process item click
    QGraphicsItem *item = itemAt(event->pos());
    if( item ){
      switch( item->type() ) {
        case NodeSocketType:
          // NodeSocket click. Start creating new connection
          _temp_socket_from = dynamic_cast<NodeSocketItem*>(item);

          _temp_connection_item = new NodeConnectionItem(_node_flow_scene);
          _temp_connection_item->setPosFrom(_temp_socket_from->scenePos());
          _temp_connection_item->setPosTo(_temp_socket_from->scenePos());
          break;
      }
    }
  }
  QGraphicsView::mousePressEvent(event);
}


void NodeFlowView::mouseMoveEvent(QMouseEvent *event) {
  // translate scene
  if (scene()->mouseGrabberItem() == nullptr && event->buttons() == Qt::LeftButton && event->modifiers ().testFlag (Qt::ControlModifier)) {
    // Make sure shift is not being pressed
    if ((event->modifiers() & Qt::ShiftModifier) == 0) {
      QPointF difference = _clickPos - mapToScene(event->pos());
      setSceneRect(sceneRect().translated(difference.x(), difference.y()));
    }
  } else {
    if (_temp_socket_to) {
      _temp_socket_to->setHoverFlag(NodeSocketItem::HoverFlag::NoHover);
      _temp_socket_to = nullptr;
    }
    if (_temp_connection_item) {
      // update temp connection item
      _temp_connection_item->setPosTo(mapToScene(event->pos()));

      // check if we are over some socket
      QGraphicsItem *item = itemAt(event->pos());
      if( item ){
        switch( item->type() ) {
          case NodeSocketType:
            _temp_socket_to = dynamic_cast<NodeSocketItem*>(item);
            if (NodeSocketItem::canConnect(_temp_socket_from, _temp_socket_to)) {
               // snap to socket and set hover flag on sockets
              _temp_connection_item->setPosTo(_temp_socket_to->scenePos());
              _temp_socket_to->setHoverFlag(NodeSocketItem::HoverFlag::CanConnect);
            } else {
              _temp_connection_item->setPosTo(mapToScene(event->pos()));
              _temp_socket_to->setHoverFlag(NodeSocketItem::HoverFlag::CanNotConnect);
            }
            break;
        }
      }
    }
  }
  QGraphicsView::mouseMoveEvent(event);
}


void NodeFlowView::mouseReleaseEvent(QMouseEvent *event) {
  // process sockets connection if it's there
  if(_temp_connection_item) {

    // delete temporary connection item
    delete _temp_connection_item;

    // check if coonection is allowed then fire signal to engine
    if(NodeSocketItem::canConnect(_temp_socket_from, _temp_socket_to)) {
      // connect temp item to socket items
      const OpDataSocket *socket_from = _temp_socket_from->opDataSocket();
      const OpDataSocket *socket_to = _temp_socket_to->opDataSocket();
      const OpNode *node_from = _temp_socket_from->nodeItem()->opNode();
      const OpNode *node_to = _temp_socket_to->nodeItem()->opNode();

      // ensure node/sockets passed in right order
      if (!socket_to->isInput()) {
        std::swap(socket_to, socket_from);
        std::swap(node_to, node_from);
      }

      EngineSignals::getInstance().signalConnectOpNodes(socket_to->idx(), node_to->path(), socket_from->idx(), node_from->path());
    }

    _temp_connection_item = nullptr;
    _temp_socket_from = nullptr;
    _temp_socket_to = nullptr;
  }

  setDragMode(QGraphicsView::NoDrag);
  QGraphicsView::mouseReleaseEvent(event);
}


void NodeFlowView::wheelEvent(QWheelEvent *event) {
  double zoom_in_factor = 1.05;
  double zoom_out_factor = 1 / zoom_in_factor;
  double zoom_factor;

  setTransformationAnchor(QGraphicsView::NoAnchor);
  setResizeAnchor(QGraphicsView::NoAnchor);

  QPointF old_pos = mapToScene(event->pos());

  float angle_delta = event->angleDelta().y();
  if (std::abs(angle_delta) > 0.1 ) { // using 0.1 threshold to make wheel smoother
    if (angle_delta > 0) {
      zoom_factor = zoom_in_factor;
    } else {
      zoom_factor = zoom_out_factor;
    }

    zoom(zoom_factor);

    QPointF new_pos = mapToScene(event->pos());

    QPointF delta = new_pos - old_pos;
    this->translate(delta.x(), delta.y());
  }
}

void NodeFlowView::zoom(double zoom_factor) {
  setZoomLevel(_zoom_level *= zoom_factor);
}

void NodeFlowView::setZoomLevel(double zoom_level) {
  _zoom_level = boost::algorithm::clamp(zoom_level, _min_zoom_level, _max_zoom_level);
  resetMatrix();
  scale(_zoom_level, _zoom_level);
}

double NodeFlowView::zoomLevel() {
  return _zoom_level;
}

}}