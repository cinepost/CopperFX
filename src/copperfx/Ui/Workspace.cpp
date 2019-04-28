#include <QtWidgets>

#include "copperfx/Ui/Workspace.h"


namespace copper { namespace ui {

Workspace::Workspace(QWidget *parent) {
  setObjectName("Workspace");

  // test workspace setup
  // TODO: load workspace layout from file

  QSplitter *splitter1 = new QSplitter(Qt::Horizontal, this);

	//splitter1->addWidget(new QLabel("I am widget A"));

  PanelManager *panel_manager1 = new PanelManager();

	splitter1->addWidget(panel_manager1);
	splitter1->addWidget(new QLabel("I am widget B"));

	QHBoxLayout *hBoxLayout = new QHBoxLayout();

	hBoxLayout->addWidget(splitter1);

  setLayout(hBoxLayout);

  // add test panels
  panel_manager1->addPanelByTypeName("scene_view");
  panel_manager1->addPanelByTypeName("node_flow_view");
}

Workspace::~Workspace() {

}

std::vector<PanelManager*> Workspace::panelManagers() {
	return _panel_managers;
}

}}
