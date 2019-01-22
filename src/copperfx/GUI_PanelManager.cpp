#include <QtWidgets>
#include <QTabWidget>

#include "copperfx/GUI/GUI_PanelManager.h"

GUI_PanelManager::GUI_PanelManager(QWidget *parent) : QFrame (parent) {
    setObjectName("PanelManager");

    tabs = new QTabWidget(this);
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
}

GUI_PanelManager::~GUI_PanelManager() {

}
