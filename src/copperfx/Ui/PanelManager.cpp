#include <QtWidgets>
#include <QTabWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSizePolicy>

#include "copperfx/Ui/PanelManager.h"


namespace copper { namespace ui {

// initialize static memeber factory
UiPanelFactory PanelManager::_panel_factory;

PanelManager::PanelManager() : PanelManager(nullptr) { }

PanelManager::PanelManager(QWidget *parent) : TabView (parent) {
  setObjectName("pane_manager");
  setTabsClosable(true);
  setMovable(true);

  _corner_widget = new QWidget(this);
  _corner_widget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored);

  QHBoxLayout *corner_widget_layout = new QHBoxLayout();
  corner_widget_layout->setSpacing(0);
  corner_widget_layout->setContentsMargins(0, 0, 0, 0);

  _corner_widget->setLayout(corner_widget_layout);

  QPushButton *plus_button = new QPushButton();
  plus_button->setIcon(QIcon::fromTheme("tab-new", QIcon(":/icons/pane-plus")));

  QPushButton *max_button = new QPushButton();
  max_button->setIcon(QIcon::fromTheme("view-fullscreen", QIcon(":/icons/pane-maximize")));

  QPushButton *menu_button = new QPushButton();
  menu_button->setIcon(QIcon::fromTheme("go-down", QIcon(":/icons/panes-menu")));


  corner_widget_layout->addWidget(plus_button);
  corner_widget_layout->addStretch();
  corner_widget_layout->addWidget(max_button);
  corner_widget_layout->addWidget(menu_button);

  setCornerWidget(_corner_widget);
}

PanelManager::~PanelManager() {
	delete _corner_widget;
}

void PanelManager::addPanelByTypeName(std::string panel_type_name) {
	PanelBase *new_panel = _panel_factory.createObjectByTypeName(panel_type_name);
	addTab(new_panel, new_panel->name().c_str());
}

}}