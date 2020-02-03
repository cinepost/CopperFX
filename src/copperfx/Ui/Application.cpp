#include "copperfx/Ui/Application.h"
#include "copperfx/Ui/PanelManager.h"

#include "copperfx/panels/SceneViewPanel/SceneViewPanel.h"
#include "copperfx/panels/NodeFlowViewPanel/NodeFlowViewPanel.h"

namespace copper { namespace ui {

Application::Application(int& argc, char** argv) : QApplication(argc, argv) {
	// Register all internally defined and pluggalble panel types
 	PanelManager::_panel_factory.registerType( SceneViewPanel::myTypeName, SceneViewPanel::myConstructor );
 	PanelManager::_panel_factory.registerType( NodeFlowViewPanel::myTypeName, NodeFlowViewPanel::myConstructor );
}

}}