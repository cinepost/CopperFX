#include <QtWidgets>
#include <QTabWidget>

#include "copperfx/GUI/GUI_PanelManager.h"


namespace copper {

GUI_PanelManager::GUI_PanelManager(QWidget *parent, GUI_PanelFactory *panel_factory)
	: QTabWidget (parent) {
		
	_panel_factory = panel_factory;

  setObjectName("PanelManager");

  setTabsClosable(true);
  setMovable(true);
}

GUI_PanelManager::~GUI_PanelManager() {

}

void GUI_PanelManager::addPanel(std::string panel_type_name) {

	GUI_Panel *new_panel = _panel_factory->createObjectByName(panel_type_name);
	addTab(new_panel, new_panel->name().c_str());
}

}