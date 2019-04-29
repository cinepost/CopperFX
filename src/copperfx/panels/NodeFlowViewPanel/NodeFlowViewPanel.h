#ifndef NODE_FLOW_VIEW_PANEL_H
#define NODE_FLOW_VIEW_PANEL_H

#include "copperfx/Ui/PanelBase.h"


namespace copper { namespace ui {

class NodeFlowView;

class NodeFlowViewPanel : public PanelBase {
	Q_OBJECT

  public:
    NodeFlowViewPanel();
    ~NodeFlowViewPanel();

  public:
    const std::string name() const override;
    const std::string typeName() const override;
    const unsigned int version() const override;

  private:
  	NodeFlowView *_node_flow_view_widget;

  public:
    // factory methods
    static std::string myTypeName();
    static PanelBase *myConstructor();

};

}}


#endif // NODE_FLOW_VIEW_PANEL_H