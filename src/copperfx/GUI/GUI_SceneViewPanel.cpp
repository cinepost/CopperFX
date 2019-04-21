#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include "copperfx/GUI/GUI_SceneViewPanel.h"


using namespace copper;

GUI_SceneViewPanel::GUI_SceneViewPanel(QWidget *parent) : GUI_Panel(parent) {
  BOOST_LOG_TRIVIAL(debug) << "Scene View panel constructed!";
}


GUI_SceneViewPanel::~GUI_SceneViewPanel() {
  BOOST_LOG_TRIVIAL(debug) << "Scene View panel destructed!";
}


const std::string GUI_SceneViewPanel::name() const{
  return "scene_view";
}


const std::string GUI_SceneViewPanel::typeName() const{
  return "Scene View";
}

const unsigned int GUI_SceneViewPanel::version() const{
	return 0;
}

GUI_Panel *GUI_SceneViewPanel::panelConstructor() {
	return new GUI_SceneViewPanel();
}


// method for registering panel type
void registerSceneViewPanelType(GUI_PanelRegistry *registry) {
	registry->addPanelType(	"scene_view", GUI_SceneViewPanel::panelConstructor);
}