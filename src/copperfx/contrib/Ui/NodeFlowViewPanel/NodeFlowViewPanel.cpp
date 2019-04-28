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

NodeFlowViewPanel::NodeFlowViewPanel() {
	_node_flow_view_widget = new NodeFlowView();
  _node_flow_view_widget->setScene(new NodeFlowScene()); // test scene
  _node_flow_view_widget->scene()->createTestNode(); // test item

	QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(_node_flow_view_widget);
  setLayout(layout);
  BOOST_LOG_TRIVIAL(debug) << "Node Flow View panel constructed!";
}


NodeFlowViewPanel::~NodeFlowViewPanel() {
	delete _node_flow_view_widget;
  BOOST_LOG_TRIVIAL(debug) << "Node Flow View panel destructed!";
}

const std::string NodeFlowViewPanel::name() const{
  return "Node Flow";
}

const std::string NodeFlowViewPanel::typeName() const{
  return "node_flow_view";
}

const unsigned int NodeFlowViewPanel::version() const{
	return 0;
}

// factory methods
std::string NodeFlowViewPanel::myTypeName() {
  return "node_flow_view";
}

PanelBase *NodeFlowViewPanel::myConstructor() {
	return new NodeFlowViewPanel();
}

}}