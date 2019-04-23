#include "copperfx/Ui/Application.h"
#include "copperfx/Ui/PanelManager.h"
#include "copperfx/Ui/SceneViewPanel.h"


namespace copper { namespace ui {

Application::Application(int& argc, char** argv) : QApplication(argc, argv) {
	// Register all internally defined and pluggalble panel types
  PanelManager::_panel_factory.registerType( SceneViewPanel::myTypeName, SceneViewPanel::myConstructor );
}

}}