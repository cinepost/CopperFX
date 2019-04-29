#include "TabView.h"
#include "TabBar.h"


namespace copper { namespace ui {

TabView::TabView(QWidget *parent): QTabWidget(parent) {
  // Set custom tabbar
  setTabBar(new TabBar);
}

int TabView::tabAt(const QPoint &pos) {
  return tabBar()->tabAt(pos);
}

}}