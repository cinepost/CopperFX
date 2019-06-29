#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include <QVBoxLayout>

#include "NodeFlowScene.h"
#include "NodeFlowView.h"
#include "NodeFlowViewPanel.h"
#include "NodeItem.h"

namespace copper { namespace ui {

std::string NodeFlowViewPanel::_ui_name = "Node Flow";

NodeFlowViewPanel::NodeFlowViewPanel() {
	_node_flow_view_widget = new NodeFlowView(this, "/");
  //_node_flow_view_widget->setScene(new NodeFlowScene()); // test scene
  //_node_flow_view_widget->scene()->createTestNode(); // test item

	QLayout *layout = new QVBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);

  layout->addWidget(_node_flow_view_widget);
  setLayout(layout);
  BOOST_LOG_TRIVIAL(debug) << "Node Flow View panel constructed!";
}


NodeFlowViewPanel::~NodeFlowViewPanel() {
	delete _node_flow_view_widget;
  BOOST_LOG_TRIVIAL(debug) << "Node Flow View panel destructed!";
}

const std::string& NodeFlowViewPanel::name() const{
  return NodeFlowViewPanel::_ui_name;
}

// factory methods
std::string NodeFlowViewPanel::myTypeName() {
  return "node_flow_view";
}

PanelBase *NodeFlowViewPanel::myConstructor() {
	return new NodeFlowViewPanel();
}

}}