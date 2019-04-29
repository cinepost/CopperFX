#ifndef TABBAR_H
#define TABBAR_H

#include <QTabBar>


namespace copper { namespace ui {

class GhostWindow;
class PanelManager;

/*
 * Re-implemented the standard QTabBar widget but adds new methods to allow
 * Drag&Drop operations outside the tab bar's window, like creating a new
 * window with a dragged view, move a view into a different window or close the
 * current window if no more tabs are available
 */
class TabBar : public QTabBar {
  Q_OBJECT

  public:
    TabBar(QWidget *parent = nullptr);
    ~TabBar();

    // If the left mouse button if pressed over a tab show the ghost window
    // and starts the Drag&Drop operation
    void mousePressEvent(QMouseEvent *) override;

    // Update the ghost window's position during mouse move
    void mouseMoveEvent(QMouseEvent *) override;

    // Drops the current dragged view and creates a new window if no tab bar
    // under the event's screen position otherwise move the dragged view into
    // the tab bar under the mouse event's position.
    // Finishing by destroying the ghost windows widget and closing the current
    // window if no tabs left.
    void mouseReleaseEvent(QMouseEvent *) override;

  protected:
    // If no tabs are left in the current tab bar closes the widget's window.
    //
    // See QTabBar::tabRemoved
    void tabRemoved(int index) override;

    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;

  private:
    bool _drag_started;
};

}}

#endif // TABBAR_H