#ifndef __GUI_PanelManager_H__
#define __GUI_PanelManager_H__

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

#endif // __GUI_Panel_Manager_H___