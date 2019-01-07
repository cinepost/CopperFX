#include <QtWidgets>
#include <QTabWidget>

#include "GUI/GUI_PanelManager.h"

GUI_PanelManager::GUI_PanelManager(QWidget *parent)
{
    setObjectName("PanelManager");

    tabs = new QTabWidget(this);
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
}

GUI_PanelManager::~GUI_PanelManager() {

}
