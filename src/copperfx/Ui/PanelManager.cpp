#include <QtWidgets>
#include <QTabWidget>

#include "copperfx/Ui/PanelManager.h"


namespace copper { namespace ui {

// initialize static memeber factory
UiPanelFactory PanelManager::_panel_factory;

PanelManager::PanelManager() : PanelManager(nullptr) { }

PanelManager::PanelManager(QWidget *parent) : QTabWidget (parent) {
  setObjectName("PanelManager");

  setTabsClosable(true);
  setMovable(true);
}

PanelManager::~PanelManager() {

}

void PanelManager::addPanelByTypeName(std::string panel_type_name) {
	PanelBase *new_panel = _panel_factory.createObjectByTypeName(panel_type_name);
	addTab(new_panel->widget(), new_panel->name().c_str());
}

}}