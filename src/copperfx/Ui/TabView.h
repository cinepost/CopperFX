#ifndef TABVIEW_H
#define TABVIEW_H

#include <QTabWidget>


namespace copper { namespace ui {

/*
 * Subclass of a standard QTabWidget, to be extended to fit the desired view's
 * Drag&Drop behaviour
 */
class TabView : public QTabWidget {
    Q_OBJECT

  public:
    explicit TabView(QWidget *parent = 0);

    // Implementation of the QTabBar::tabAt method
    // This should be exposed here because the original one is a protected
    // method and in the TabbedWindow class we need to retrieve the tab's index
    // by the cursor position.
    int tabAt(const QPoint &pos);
};

}}

#endif // TABVIEW_H