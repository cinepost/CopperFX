#ifndef GUI_PANEL_MANAGER_H
#define GUI_PANEL_MANAGER_H

#include <QFrame>
#include <QTabWidget>

class GUI_PanelManager : public QFrame
{
    Q_OBJECT

public:
    GUI_PanelManager(QWidget *parent = 0);
    virtual ~GUI_PanelManager();

private:
    QTabWidget *tabs;

};

#endif