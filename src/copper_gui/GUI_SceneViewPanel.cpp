#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include "GUI_SceneViewPanel.h"


GUI_SceneViewPanel::GUI_SceneViewPanel(QWidget *parent) : GUI_Panel(parent) {
  BOOST_LOG_TRIVIAL(debug) << "Scene View panel constructed!";
}


GUI_SceneViewPanel::~GUI_SceneViewPanel() {
  BOOST_LOG_TRIVIAL(debug) << "Scene View panel destructed!";
}


const char *GUI_SceneViewPanel::panelTypeName() const{
    return "Scene View";
}


GUI_Panel *GUI_SceneViewPanel::panelConstructor() {
	return new GUI_SceneViewPanel();
}

// method for registering panel type
void registerSceneViewPanelType(GUI_PanelRegistry *registry) {
	registry->addPanelType(	"scene_view", GUI_SceneViewPanel::panelConstructor);
}