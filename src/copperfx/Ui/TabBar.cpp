#include <iostream>

#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QApplication>

#include "TabBar.h"
#include "TabView.h"

#include "PanelManager.h"


namespace copper { namespace ui {

TabBar::TabBar(QWidget *parent) : QTabBar(parent), _drag_started(false) { 
  setAcceptDrops(true);
}

TabBar::~TabBar() { }

void TabBar::mouseMoveEvent(QMouseEvent *event) {
  if (!_drag_started) {
    QTabBar::mouseMoveEvent(event);
  }
  this->setCursor(Qt::ClosedHandCursor);
}

void TabBar::mouseReleaseEvent(QMouseEvent *event) {
  this->setCursor(Qt::ArrowCursor);
  _drag_started = false;
  QTabBar::mouseReleaseEvent(event);
}

void TabBar::mousePressEvent(QMouseEvent *event) {
  QDrag *drag = new QDrag(this);
  QMimeData *mimeData = new QMimeData;

  mimeData->setText("lalala");
  drag->setMimeData(mimeData);
  
  _drag_started = true;
  QTabBar::mousePressEvent(event);
}

void TabBar::tabRemoved(int index) {
    if (count() == 0) {
        window()->close();
    }
}

void TabBar::dropEvent(QDropEvent *event) { 
  const QMimeData *mimeData = event->mimeData();

  if (mimeData->hasText()) {
    std::cout << mimeData->text().toStdString() << "\n";
  }
}

void TabBar::dragEnterEvent(QDragEnterEvent *event) {
    event->acceptProposedAction();
    //emit changed(event->mimeData());
}


}}
