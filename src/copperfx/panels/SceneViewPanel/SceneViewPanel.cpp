#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include <QVBoxLayout>

#include "SceneViewPanel.h"


namespace copper { namespace ui {

std::string SceneViewPanel::_ui_name = "Scene View";

SceneViewPanel::SceneViewPanel() {
	_gl_widget = new SceneViewPanelGLWidget();
	QLayout *layout = new QVBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);

  layout->addWidget(_gl_widget);
  setLayout(layout);
  BOOST_LOG_TRIVIAL(debug) << "SceneViewPanel constructed!";
}


SceneViewPanel::~SceneViewPanel() {
	delete _gl_widget;
  BOOST_LOG_TRIVIAL(debug) << "SceneViewPanel destructed!";
}

const std::string& SceneViewPanel::name() const{
  return SceneViewPanel::_ui_name;
}

// factory methods
std::string SceneViewPanel::myTypeName() {
  return "scene_view";
}

PanelBase *SceneViewPanel::myConstructor() {
	return new SceneViewPanel();
}

}}