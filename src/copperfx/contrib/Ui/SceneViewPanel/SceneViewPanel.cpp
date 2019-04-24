#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include <QVBoxLayout>

#include "SceneViewPanel.h"


namespace copper { namespace ui {

SceneViewPanel::SceneViewPanel() {
	_gl_widget = new SceneViewPanelGLWidget();
	QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(_gl_widget);
  setLayout(layout);
  BOOST_LOG_TRIVIAL(debug) << "Scene View panel constructed!";
}


SceneViewPanel::~SceneViewPanel() {
	delete _gl_widget;
  BOOST_LOG_TRIVIAL(debug) << "Scene View panel destructed!";
}

const std::string SceneViewPanel::name() const{
  return "Scene View";
}

const std::string SceneViewPanel::typeName() const{
  return "scene_view";
}

const unsigned int SceneViewPanel::version() const{
	return 0;
}

// factory methods
std::string SceneViewPanel::myTypeName() {
  return "scene_view";
}

PanelBase *SceneViewPanel::myConstructor() {
	return new SceneViewPanel();
}

}}